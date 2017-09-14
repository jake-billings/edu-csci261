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
	RenderWindow window(sf::VideoMode(TileMap::COLS * TileMap::TILE_WIDTH, TileMap::ROWS * TileMap::TILE_HEIGHT), "Lab12C2 - Simple Game", Style::Titlebar | Style::Close);

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
	player.westTexture = Texture();
	player.westTexture.loadFromFile("data/player3.png");
	player.eastTexture = Texture();
	player.eastTexture.loadFromFile("data/player1.png");
	player.northTexture = Texture();
	player.northTexture.loadFromFile("data/player0.png");
	player.southTexture = Texture();
	player.southTexture.loadFromFile("data/player2.png");


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
				    case Keyboard::A: //A and S used because plus and minus weren't working.
				    	player.speed++;
				    	break;
				    case Keyboard::S:
				    	player.speed--;
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
