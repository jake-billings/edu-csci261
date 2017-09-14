#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "Hud.h"
#include "TileMap.h"

using namespace sf;
using namespace std;

// The player class holds a representation of the player, and maintains all their
// attributes: where they are, how big they are, the direction they're facing, etc.
class Player : public Drawable
{
private:
    Hud &hud;   // A reference to the HUD, so that the player can collect points

    int x, y;   // Coordinates of the top-left corner that the player takes up
    int radius; // Pacman is circular, so we represent the size as a radius

    int directionIAmGoing;  // Which direction is the player facing/moving?
    int directionIWannaGo;  // Where does the user WANT to go?
    int speed;  // Number of pixels moved each frame

public:

    // Make a player that has access to the Hud (so they can update it when
    // collecting points. Ignore the Hud* part for now. It's a pointer to a
    // Hud object, and operates much like a reference.
    Player(Hud &h);

    // Draw the player onto the screen
    void draw(RenderTarget& rt, RenderStates rs) const;

    // Instruct the player to update their location, given their speed and direction
    void Move(TileMap &tileMap);

    // Getters and Setters
    void SetDirection(int direction);
    int GetX() const;
    int GetY() const;
    int GetRadius() const;
	int getDirectionIAmGoing() const;
	void setDirectionIAmGoing(int directionIAmGoing);
	int getDirectionIWannaGo() const;
	void setDirectionIWannaGo(int directionIWannaGo);
	const Hud& getHud() const;
	int getRadius() const;
	void setRadius(int radius);
	int getSpeed() const;
	void setSpeed(int speed);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

