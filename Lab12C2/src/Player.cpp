#include "Player.h"
#include <SFML/Graphics.hpp>
// our player is represented by a circular shape
void Player::draw(RenderTarget& window, RenderStates states) const {
	Sprite s;
	switch (direction) {
	case Direction::NORTH:
		s.setTexture(northTexture);
		break;
	case Direction::SOUTH:
		s.setTexture(southTexture);
		break;
	case Direction::EAST:
		s.setTexture(eastTexture);
		break;
	case Direction::WEST:
		s.setTexture(westTexture);
		break;
	}
	s.setPosition((float) x, (float) y);
    window.draw(s, states);
}

// before move to a direction we should check whether we are not hitting a wall (i.e., non-walkable tile)
void Player::Move(const TileMap &tileMap) {
    switch (direction) {
    case Direction::NORTH:
        if (tileMap.GetTile(x, y - speed).walkable && tileMap.GetTile(x + 2 * radius, y - speed).walkable) {
            y -= speed;
        }
        break;
    case Direction::EAST:
        if (tileMap.GetTile(x + 2 * radius + speed, y).walkable && tileMap.GetTile(x + 2 * radius + speed, y + 2 * radius).walkable) {
            x += speed;
        }
        break;
    case Direction::SOUTH:
        if (tileMap.GetTile(x, y + speed).walkable && tileMap.GetTile(x, y + 2 * radius + speed).walkable) {
            y += speed;
        }
        break;
    case Direction::WEST:
        if (tileMap.GetTile(x + 2 * radius - speed, y).walkable && tileMap.GetTile(x - speed, y + 2 * radius).walkable) {
            x -= speed;
        }
        break;
    }

    Tile tile = tileMap.GetTile(x,y);
    if (tile.isPortal()) {
    	x = tile.portalX;
    	y = tile.portalY;
    }
}
