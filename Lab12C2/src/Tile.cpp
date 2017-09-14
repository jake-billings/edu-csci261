#include "Tile.h"

// our tile is represented by a rectangular shape
void Tile::draw(RenderTarget& window, RenderStates states) const {
    RectangleShape shape(Vector2f((float)width, (float)height));
    shape.setPosition((float)x, (float)y);
    shape.setFillColor(color);
    window.draw(shape, states);
}

bool Tile::isPortal() const {
	return (portalX>-1&&portalY>-1);
}
