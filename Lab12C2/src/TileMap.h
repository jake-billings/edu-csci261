#pragma once

#include "Tile.h"
#include <string>
#include <fstream>

using namespace std;

class TileMap : public Drawable {
public:
    static const int ROWS = 10;
    static const int COLS = 10;
    static const int TILE_WIDTH = 50;
    static const int TILE_HEIGHT = 50;
    Tile tile[ROWS][COLS];
    void LoadFromFile(string); // reads the tile map from a data file
    Tile GetTile(int, int) const; // returns the tile that corresponds to a coordinate
    // not following zybook naming for draw because it needs to be the same name as the parent class
    void draw(RenderTarget&, RenderStates) const;
};
