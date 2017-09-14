#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile : public Drawable {
public:
    int x, y; // upper left coordinate
    int portalX, portalY; //-1,-1 means it's not a portal
    Color color;
    int width, height;
    bool walkable; // whether the tile is 'walkable' or not

    Sprite sprite;

    // not following zybook naming for draw because it needs to be the same name as the parent class
    void draw(RenderTarget&, RenderStates) const;
    bool isPortal() const;

};
