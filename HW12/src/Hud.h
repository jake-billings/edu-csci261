#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

// The Hud class holds the number of points that the player has collected,
// and displays them
class Hud : public Drawable {
    // DONE: Finish the Hud class. It needs to hold the number of points collected,
    // and the draw function should display the number of points the player has
    // collected in the upper-left corner of the screen
    //
    // Notes:
    // The player needs some accessor functions to be able to collect points.
    // In main, when constructing the Hud, a font is passed in. Keep record of
    //    this in the Hud so that the font only needs to be read in once for the
    //    entire program (as opposed to reading it in everytime draw is called)
private:
	Font font;
	int points;
	
public:
    Hud(Font font);
    void draw(RenderTarget& rt, RenderStates rs) const;
    void AddPoints(int points);
	const Font& getFont() const;
	void setFont(const Font& font);
	int getPoints() const;
	void setPoints(int points);
	void addPoints(int pointsToAdd);
};
