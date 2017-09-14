#pragma once

#include "TileMap.h"
#include "Direction.h"

class Player : public Drawable {
public:
    Color color;
    int x, y; // upper left coordinate
    int radius;
    int direction;
    int speed;
    // not following zybook naming for draw because it needs to be the same name as the parent class
    void draw(RenderTarget&, RenderStates) const;
    void Move(const TileMap &tileMap);
};