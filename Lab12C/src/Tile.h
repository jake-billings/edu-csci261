#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile : public Drawable {
public:
    int x, y; // upper left coordinate
    Color color;
    int width, height;
    bool walkable; // whether the tile is 'walkable' or not
    // not following zybook naming for draw because it needs to be the same name as the parent class
    void draw(RenderTarget&, RenderStates) const;
};