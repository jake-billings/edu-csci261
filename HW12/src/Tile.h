#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// A Tile is a single square inside the map. Each Tile could be a wall, or could
// be a walkway, as described by walkable. Each Tile has some optional points that could
// be held. If there are points, a circle is drawn that can be collected.
class Tile : public Drawable
{
private:
    int x, y; // upper left coordinate
    Color color;    // The color that will be used to draw the Tile
    int width, height;  // The size of the square
    bool walkable; // whether the tile is 'walkable' or not
    int points; // How many points the Tile has. If 0, no circle will be drawn

public:
    static const int TILE_WIDTH = 50;
    static const int TILE_HEIGHT = 50;

    Tile();

    void SetPosition(int x, int y);
    void SetColor(Color color);
    void SetSize(int w, int h);
    void SetPoints(int p);
    void SetWalkable(bool w);

    bool IsWalkable() const;
    int  GetPoints() const;
    void draw(RenderTarget&, RenderStates) const;
	Color getColor() const;
	void setColor(Color color);
	int getHeight() const;
	void setHeight(int height);
	int getPoints() const;
	void setPoints(int points);
	bool isWalkable() const;
	void setWalkable(bool walkable);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

