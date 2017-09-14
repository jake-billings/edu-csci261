#include <iostream>
#include <cstdlib>
#include <fstream>
#include "TileMap.h"
#include "Player.h"

// declare your constants below here
static const string DATA_FILE = "data/tilemap.txt";

int main()
{
	// creates the window object    
	RenderWindow window(sf::VideoMode(TileMap::COLS * TileMap::TILE_WIDTH, TileMap::ROWS * TileMap::TILE_HEIGHT), "Lab12C - Simple Game", Style::Titlebar | Style::Close);

	// creates the tile map object
	TileMap tileMap;
	tileMap.LoadFromFile(DATA_FILE);

	// creates the player object
	Player player;
	player.x = 250;
	player.y = 255;
	player.radius = 20;
	player.speed = 2;
	player.color = Color::Yellow;
	player.direction = Direction::EAST;

	// constantly draws the window until it is closed
	while (window.isOpen()) {
		// updates the window 
		window.clear();
		window.draw(tileMap);
		window.draw(player);
		window.display();

		// checks for events
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
				switch (event.key.code) {
				    case Keyboard::Up:
					    player.direction = Direction::NORTH;
					    break;
				    case Keyboard::Down:
					    player.direction = Direction::SOUTH;
					    break;
				    case Keyboard::Left:
					    player.direction = Direction::WEST;
					    break;
				    case Keyboard::Right:
					    player.direction = Direction::EAST;
					    break;
				    default:
				    	break;
			        }
		}

		// moves the player
		player.Move(tileMap);
	}

	return 0;
}
