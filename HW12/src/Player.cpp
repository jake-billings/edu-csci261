#include "Player.h"

// When constructing a player, give them a place to update their score (the Hud)
// Also assign some defaults for the position, speed, and direction
Player::Player(Hud &hud) : hud(hud) {
    x = 250;
    y = 250;
    radius = 24;
    speed = 2;
    directionIWannaGo = Direction::EAST;
    directionIAmGoing = Direction::EAST;
}

// Draw the player onto the screen. For extra fanciness, we use sprites to draw
// the player
void Player::draw(RenderTarget& window, RenderStates states) const
{
    // Load up the texture to use for the sprite based off the direction
    Texture texture;
    switch (directionIAmGoing)
    {
    case Direction::NORTH:
        texture.loadFromFile("data/player0.png");
        break;
    case Direction::EAST:
        texture.loadFromFile("data/player1.png");
        break;
    case Direction::SOUTH:
        texture.loadFromFile("data/player2.png");
        break;
    case Direction::WEST:
        texture.loadFromFile("data/player3.png");
        break;
    }

    // Create a sprite that we can texture and use for drawing
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition((float) x, (float) y);

    // Scale to fit inside a 2*radius by 2*radius square
    Vector2u tsz = texture.getSize();
    sprite.setScale((float) 2*radius/tsz.x, (float) 2*radius/tsz.y);

    // Draw the sprite
    window.draw(sprite, states);
}

// before move to a direction we should check whether we are not hitting a wall (i.e., non-is.IsWalkable()() tile)
void Player::Move(TileMap &tileMap)
{
    // Player changes directions at junctions only when the player can move in that direction
    // Don't modify this part. It makes movement natural for you. Just use directionIAmGoing
    if ( directionIWannaGo != directionIAmGoing
        && (x % Tile::TILE_WIDTH == 0 || x % Tile::TILE_WIDTH == 1)
        && (y % Tile::TILE_HEIGHT == 0 || y % Tile::TILE_HEIGHT == 1)) {
        directionIAmGoing = directionIWannaGo;
    }

    // Based on the direction the player is headed, we add/subtract the speed
    // with the player's coordinates, moving them by a distance of speed in the
    // respective direction. North results in subtracting from y, East in adding
    // to x, and etc.
    //
    // Each time, though, we need to make sure the player can actually move
    // there; otherwise, they'd cheat, and just clip through walls! Each direction
    // checks that the 2 points on the outer edges of the player on that side
    // are in .IsWalkable() areas, like so:
    //
    // Normal Player:   Checking East (marked by '-')
    // sssss            ssss-
    // s   s            s   s
    // sssss            ssss-
    //
    // Remember that x,y is the top-left coordinate, and each side-length is 2*radius long
    switch (directionIAmGoing)
    {
    case Direction::NORTH:
        if (tileMap.GetTile(x, y - speed).IsWalkable() && tileMap.GetTile(x + 2 * radius, y - speed).IsWalkable()) {
            y -= speed;
        }
        break;
    case Direction::EAST:
        if (tileMap.GetTile(x + 2 * radius + speed, y).IsWalkable() && tileMap.GetTile(x + 2 * radius + speed, y + 2 * radius).IsWalkable()) {
            x += speed;
        }
        break;
    case Direction::SOUTH:
        if (tileMap.GetTile(x, y + speed).IsWalkable() && tileMap.GetTile(x, y + 2 * radius + speed).IsWalkable()) {
            y += speed;
        }
        break;
    case Direction::WEST:
        if (tileMap.GetTile(x + 2 * radius - speed, y).IsWalkable() && tileMap.GetTile(x - speed, y + 2 * radius).IsWalkable()) {
            x -= speed;
        }
        break;
    }
    // Evaluate the new position to see if we can/should consume a point-giving dot
    // We add radius to x,y so that we check the tile that the player is in the middle of
    if (tileMap.GetTile(x+radius, y+radius).GetPoints() > 0) {
        // Add those points to the HUD's displayed score
        hud.AddPoints(tileMap.GetTile(x+radius, y+radius).GetPoints());
        // Remove the points from the tile
        tileMap.SetTilePoints(x+radius, y+radius, 0);
    }
}

// Have the player change directions
void Player::SetDirection(int direction)
{
    this->directionIWannaGo = direction;
}

int Player::GetX() const
{
    return x;
}

int Player::GetY() const
{
    return y;
}

int Player::GetRadius() const
{
    return radius;
}

int Player::getDirectionIAmGoing() const {
	return directionIAmGoing;
}

void Player::setDirectionIAmGoing(int directionIAmGoing) {
	this->directionIAmGoing = directionIAmGoing;
}

int Player::getDirectionIWannaGo() const {
	return directionIWannaGo;
}

void Player::setDirectionIWannaGo(int directionIWannaGo) {
	this->directionIWannaGo = directionIWannaGo;
}

const Hud& Player::getHud() const {
	return hud;
}

int Player::getRadius() const {
	return radius;
}

void Player::setRadius(int radius) {
	this->radius = radius;
}

int Player::getSpeed() const {
	return speed;
}

void Player::setSpeed(int speed) {
	this->speed = speed;
}

int Player::getX() const {
	return x;
}

void Player::setX(int x) {
	this->x = x;
}

int Player::getY() const {
	return y;
}

void Player::setY(int y) {
	this->y = y;
}
