/* CSCI261 Lab 07B: SFML Drawing Stars
 *
 * Author: Jake Billings
 */
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	//Width and height to map star coordinates to
	const int WIDTH = 640;
	const int HEIGHT = WIDTH;

	//The maximum brightness to map other stars to
	const int BRIGHTEST_STAR = 8;

	//An array to cache loaded stars so the stars are not loaded on each frame
	CircleShape starShapes[4096];

	//Open a data stream
	ifstream data("data/ModifiedStars.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	//A count of the number of stars to keep count while loading and used for iteration later
	int starCount = 0;
	//Read all stars from the file
	while (!data.eof()) {
		//Read x
		double xStar;
		data >> xStar;

		//Read yStar
		double yStar;
		data >> yStar;

		//Read brightness
		double brightness;
		data >> brightness;

		//Create a CircleShape with radius 2
		CircleShape star = CircleShape(2);

		//Set the star's coordinates
		star.setPosition(Vector2f(xStar,yStar));

		//Calculate the star's shade of grey
		int shadeOfGray = (int)( ( 255.0 * brightness ) / BRIGHTEST_STAR );

		//Set the fill color of the star using the same shade for each channel resulting in a grey value
		star.setFillColor(Color(shadeOfGray, shadeOfGray, shadeOfGray));

		//Add the star to the array cache
		starShapes[starCount++] = star;
	}

    // creates the window object with an 800x600 resolution window
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Lab07B: StarMap");

	// Draw loop: Each iteration of this loop draws a single frame
	while (window.isOpen()) {

		// Erase the screen with black (because space)
		window.clear();

		//Create CircleShape with radius 2 and set its position
		for (int i=0;i<starCount;i++) {
			window.draw(starShapes[i]);
		}

		// Apply all the draws to the screen
		window.display();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
	}

    return EXIT_SUCCESS;
}
