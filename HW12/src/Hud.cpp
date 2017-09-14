#include <cstdlib>
#include <iostream>
#include "Hud.h"

// Construct a HUD with 0 points
Hud::Hud(Font font)
{
    this->font = font;
    setPoints(0);
}

// When the player collects points, this function is called, which updates
// the record of points.
void Hud::AddPoints(int p) {
	setPoints(getPoints()+p);
}

// Draw the points in the upper left-hand corner by using a Text object.
void Hud::draw(RenderTarget& rt, RenderStates rs) const
{
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString(to_string(getPoints()));

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	rt.draw(text,rs);
}

const Font& Hud::getFont() const {
	return font;
}

void Hud::setFont(const Font& font) {
	this->font = font;
}

int Hud::getPoints() const {
	return this->points;
}

void Hud::setPoints(int points) {
	this->points = points;
}
