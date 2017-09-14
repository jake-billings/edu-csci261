#include "AIPlayer.h"
#include "Tile.h"

AIPlayer::AIPlayer()
{
    // To avoid unnecessary collisions, we want the AI to ALMOST take up
    // an entire square. If they're too big, they can't move effectively
    // The width/height leaves 2 pixels on each side
    width = Tile::TILE_HEIGHT-1;
    height = Tile::TILE_WIDTH-1;

    // Start the AI inside the top-left walkable() square, and inset by a pixel
    // we inset by 1x1 pixel so they aren't accidentally inside the wall at spawn
    x = Tile::TILE_WIDTH;
    y = Tile::TILE_HEIGHT;

    // The AI is a little slower than the player (1 vs 2)
    speed = 1;

    // Start the AI moving off in some direction; doesn't actually matter which,
    // since each move action will decide on the best direction to move
    direction = Direction::NORTH;
}

// Draw the AIPlayer inside the window
void AIPlayer::draw(RenderTarget& window, RenderStates states) const
{
    // TODO: Load up the texture for the stalker, and draw the AIPlayer.
    // For incremental development, you should follow these steps:
    // 1. Start with a rectangle. Notice that the x,y position, width, and height
    //    are stored as member variables. Don't forget to set the color
    // 2. Load up 1 texture, and use the setTexture() function on the rectangle
    //    to draw the texture on the rectangle.
    // 3. Use a Sprite instead of a rectangle.
    // 4. Switch which texture file is used based on the AIPlayer's direction
    // Load up the texture to use for the sprite based off the direction
    Texture texture;
    switch (direction)
    {
    case Direction::NORTH:
        texture.loadFromFile("data/stalker0.png");
        break;
    case Direction::EAST:
        texture.loadFromFile("data/stalker1.png");
        break;
    case Direction::SOUTH:
        texture.loadFromFile("data/stalker2.png");
        break;
    case Direction::WEST:
        texture.loadFromFile("data/stalker3.png");
        break;
    }

    // Create a sprite that we can texture and use for drawing
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition((float) x, (float) y);

    // Draw the sprite
    window.draw(sprite, states);
}

bool AIPlayer::CanWalk(const TileMap& tileMap, int direction)
{
    switch (direction) {
        case Direction::NORTH:
            return CanWalkNorth(tileMap);
        case Direction::EAST:
            return CanWalkEast(tileMap);
        case Direction::SOUTH:
            return CanWalkSouth(tileMap);
        case Direction::WEST:
            return CanWalkWest(tileMap);
        default: return false;
    }
}

int AIPlayer::OppositeDirection(int direction)
{
    direction -= 2;
    if (direction < 0)
        direction += 4;
    return direction;
}

bool AIPlayer::CanWalkExcept(const TileMap& tileMap, int dirA, int dirB)
{
    bool walkOther = false;
    for (int odir=0; odir < 4; ++odir) {
        if (odir != dirA && odir != dirB) {
            // OR walking in directions other than the one specified
            walkOther |= CanWalk(tileMap, odir);
        }
    }
    return walkOther;
}


bool AIPlayer::CanWalkNorth(const TileMap &tileMap) {
    return tileMap.GetTile(x, y - speed).IsWalkable()
            && tileMap.GetTile(x + width, y - speed).IsWalkable();
}
bool AIPlayer::CanWalkEast(const TileMap &tileMap) {
    return tileMap.GetTile(x + width+ speed, y).IsWalkable()
            && tileMap.GetTile(x + width + speed, y + height).IsWalkable();
}
bool AIPlayer::CanWalkSouth(const TileMap &tileMap) {
    return tileMap.GetTile(x, y + height + speed).IsWalkable()
            && tileMap.GetTile(x + width, y + height + speed).IsWalkable();
}
bool AIPlayer::CanWalkWest(const TileMap &tileMap) {
    return tileMap.GetTile(x - speed, y).IsWalkable()
            && tileMap.GetTile(x - speed, y + height).IsWalkable();

}

// before move to a direction we should check whether we are not hitting a wall (i.e., non-IsWalkable() tile)
void AIPlayer::Move(const TileMap &tileMap, const Player player)
{
    // Consider changing directions if AI hits a wall or Can make a turn
    if (!CanWalk(tileMap, direction)
            ||    ((x % Tile::TILE_WIDTH  == 0)
                && (y % Tile::TILE_HEIGHT == 0)
                && CanWalkExcept(tileMap, direction, OppositeDirection(direction))))
    {
        // Consider: Should the AI change directions?

        // Warning: None of these AI are authentic; the originals depend on path-finding

        // "Blinky" AI: Move in the direction to Get us closer (ish) to the player
        if (   player.GetX() - x < 0
            && player.GetX() - x + speed < 0
            && CanWalkWest(tileMap)) {
            direction = Direction::WEST;
        } else if (player.GetY() - y < 0
            && player.GetY() - y + speed < 0
            && CanWalkNorth(tileMap)) {
            direction = Direction::NORTH;
        } else if (player.GetX() - x > 0
            && player.GetX() - x - speed > 0
            && CanWalkSouth(tileMap)) {
            direction = Direction::EAST;
        } else if (player.GetY() - y > 0
            && player.GetY() - y - speed > 0
            && CanWalkEast(tileMap)) {
            direction = Direction::SOUTH;
        }
        // "Clyde" AI: Randomly choose a different direction that we Can move in.
        // Warning: Not particularly effective
        /*
        bool forceChoice = true;
        while (!CanWalk(tileMap, direction) || (forceChoice && !(forceChoice = false))) {
            direction = rand() % 4;
        }
        */
    }

    // Apply a movement on the AI depending on the direction they're headed
    switch (direction)
    {
    case Direction::NORTH:
        if (CanWalkNorth(tileMap))
            y -= speed;
        break;
    case Direction::EAST:
        if (CanWalkEast(tileMap))
            x += speed;
        break;
    case Direction::SOUTH:
        if (CanWalkSouth(tileMap))
            y += speed;
        break;
    case Direction::WEST:
        if (CanWalkWest(tileMap))
            x -= speed;
        break;
    }
}

bool AIPlayer::PlayerCollide(const Player player) const
{

    return !(x + Tile::TILE_WIDTH < player.GetX() || x > player.GetX() + Tile::TILE_WIDTH
    		|| y > player.GetY() + Tile::TILE_HEIGHT || y + Tile::TILE_HEIGHT < player.GetY());
}
