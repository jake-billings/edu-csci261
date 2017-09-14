#include "Player.h"

// our player is represented by a circular shape
void Player::draw(RenderTarget& window, RenderStates states) const {
    CircleShape shape((float)radius);
    shape.setPosition((float)x, (float)y);
    shape.setFillColor(color);
    window.draw(shape, states);
}

// before move to a direction we should check whether we are not hitting a wall (i.e., non-walkable tile)
void Player::Move(const TileMap &tileMap) {
    switch (direction) {
    case Direction::NORTH:
        if (tileMap.GetTile(x, y - speed).walkable && tileMap.GetTile(x + 2 * radius, y - speed).walkable)
            y -= speed;
        break;
    case Direction::EAST:
        if (tileMap.GetTile(x + 2 * radius + speed, y).walkable && tileMap.GetTile(x + 2 * radius + speed, y + 2 * radius).walkable)
            x += speed;
        break;
    case Direction::SOUTH:
        if (tileMap.GetTile(x, y - speed).walkable && tileMap.GetTile(x + 2 * radius, y - speed).walkable)
            y += speed;
        break;
    case Direction::WEST:
        if (tileMap.GetTile(x + 2 * radius + speed, y).walkable && tileMap.GetTile(x + 2 * radius + speed, y + 2 * radius).walkable)
            x -= speed;
        break;
    }
}
