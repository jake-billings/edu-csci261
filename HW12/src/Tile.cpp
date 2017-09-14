#include "Tile.h"

// our tile is represented by a rectangular shape
void Tile::draw(RenderTarget& window, RenderStates states) const
{
    // Make a rectangle with a width and height
    RectangleShape shape(Vector2f((float) TILE_WIDTH, (float) TILE_HEIGHT));

    // Set it's position using the Tile x,y position
    shape.setPosition((float)x, (float)y);

    // Set the FillColor using the variable
    shape.setFillColor(color);

    // Set an outline: this gives us a grid
    shape.setOutlineColor(Color::Green);

    // But in order to have a grid, we need some thickness to the grid lines.
    shape.setOutlineThickness(1);

    // Tell the window to draw the rectangle
    window.draw(shape, states);

    // Draw a circle in the middle of the square with a radius of "points" number of pixels
    CircleShape dot(points);

    // To position the dot correctly, we need to line up the dot's upper-left corner with
    // a position to make the center of it in the middle of the square
    // Start with the original x,y. Then translate in to the center of the square,
    // making the upper-left corner of the space that the circle takes up correlate
    // to the center of the tile, then finally subtract off the radius (points)
    // to wind up with the circle drawn in the middle of the square.
    dot.setPosition((float) x + TILE_WIDTH/2 - points, (float) y + TILE_HEIGHT/2 - points);

    // Make the points show up as Yellow
    dot.setFillColor(Color::Yellow);

    // Draw that dot!
    window.draw(dot);
}

Tile::Tile() {
	setPoints(0);
}

void Tile::SetSize(int width, int height) {
	setWidth(width);
	setHeight(height);
}

void Tile::SetPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Tile::SetColor(Color color)
{
    this->color = color;
}

void Tile::SetPoints(int p)
{
    points = p;
}

void Tile::SetWalkable(bool w)
{
    walkable = w;
}

int Tile::GetPoints() const
{
    return points;
}

bool Tile::IsWalkable() const
{
    return walkable;
}

Color Tile::getColor() const {
	return color;
}

void Tile::setColor(Color color) {
	this->color = color;
}

int Tile::getHeight() const {
	return height;
}

void Tile::setHeight(int height) {
	this->height = height;
}

int Tile::getPoints() const {
	return points;
}

void Tile::setPoints(int points) {
	this->points = points;
}

bool Tile::isWalkable() const {
	return walkable;
}

void Tile::setWalkable(bool walkable) {
	this->walkable = walkable;
}

int Tile::getWidth() const {
	return width;
}

void Tile::setWidth(int width) {
	this->width = width;
}

int Tile::getX() const {
	return x;
}

void Tile::setX(int x) {
	this->x = x;
}

int Tile::getY() const {
	return y;
}

void Tile::setY(int y) {
	this->y = y;
}
