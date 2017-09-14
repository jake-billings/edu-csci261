/* CSCI261 Homework 08: Image Processing
*
* Author: Jake Billings
*
* Description: Creates four versions of columbine.png
*
*/
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Global variables (constants)
const string ALPHABET_IMAGE_FILE = "data/columbine.png"; // you may change the image file if you want
const int WIDTH = 250; // update width if using your own image file
const int HEIGHT = 262; // update height if using your own image file
const double RED_WEIGHT = 0.299;
const double GREEN_WEIGHT = 0.587;
const double BLUE_WEIGHT = 0.114;

const unsigned int MAX_RGB_VALUE = 255;

const unsigned int PUZZLE_WIDTH = 8;
const unsigned int PUZZLE_HEIGHT = 8;

const unsigned int PUZZLE_PIECE_WIDTH = WIDTH / PUZZLE_WIDTH;
const unsigned int PUZZLE_PIECE_HEIGHT = HEIGHT / PUZZLE_HEIGHT;

// Function Prototypes
void doubleDraw(RenderWindow&, Drawable&);
/***** define your function prototypes below here *****/

void getPixels(const Image&, Color[WIDTH][HEIGHT]);
void setPixels(Image&, const Color[WIDTH][HEIGHT]);
void doNegative(Color[WIDTH][HEIGHT]);
void doGrayScale(Color[WIDTH][HEIGHT]);
void doSpecial(Color[WIDTH][HEIGHT]);

/***** define your function prototypes above here *****/

// No need to change main()
int main() {
    // creates an image object associated to the specified image data file
    Image image;
    if (!image.loadFromFile(ALPHABET_IMAGE_FILE)) {
        cerr << "Couldn't load image file " << ALPHABET_IMAGE_FILE << endl;
        return EXIT_FAILURE;
    }

    // creates a window object that can fit a 2x2 matrix of the specified image
    RenderWindow window(VideoMode(WIDTH * 2, HEIGHT * 2), "Image Processing", Style::Titlebar | Style::Close);
    window.clear(Color::Black);

    // declares an array of pixels and the texture and sprite objects
    Color pixel[WIDTH][HEIGHT];
    Texture texture;
    Sprite sprite;

    // draws sprites from the images after processing them
    for (int i = 0; i < 2; i++) // "i" is for rows
        for (int j = 0; j < 2; j++) { // "j" is for columns
        Image temp;
        temp.create(WIDTH, HEIGHT);
        getPixels(image, pixel); // loads the array of pixels from the image object
        // applies a transformation depending on the values of "i" and "j"
        switch (2 * i + j) {
        case 1:
            doNegative(pixel);
            break;
        case 2:
            doGrayScale(pixel);
            break;
        case 3:
            doSpecial(pixel);
        }
        setPixels(temp, pixel); // sets the image's pixels from the array of pixels after transformation
        texture.loadFromImage(temp); // updates texture based on the image
        sprite.setTexture(texture); // updates sprite based on the texture
        sprite.setPosition(Vector2f((float)j * WIDTH, (float)i * HEIGHT)); // positions the sprite object
        doubleDraw(window, sprite); // draws the sprite
    }

    // displays window and wait for it to be closed
    while (window.isOpen()) {
        window.display();
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();
    }

    return EXIT_SUCCESS;
}

// Draw and display using double-buffering
void doubleDraw(RenderWindow& rw, Drawable& d) {
    // Draw d to BOTH on-screen and off-screen framebuffers
    rw.draw(d);
    rw.display();
    rw.draw(d);
    rw.display();
}

/***** Start your function definitions below here *****/
void getPixels(const Image& img, Color colors[WIDTH][HEIGHT]) {
	for (int x = 0; x < WIDTH; x++) for (int y = 0; y < HEIGHT; y++) {
		colors[x][y] = img.getPixel(x,y);
	}
}

void setPixels(Image& img, const Color colors[WIDTH][HEIGHT]) {
	for (unsigned int x = 0; x < WIDTH; x++) for (unsigned int y = 0; y < HEIGHT; y++) {
		img.setPixel(x,y,colors[x][y]);
	}
}
void doNegative(Color colors[WIDTH][HEIGHT]) {
	for (unsigned int x = 0; x < WIDTH; x++) for (unsigned int y = 0; y < HEIGHT; y++) {
		Color c = colors[x][y];
		colors[x][y] = Color(MAX_RGB_VALUE-c.r,MAX_RGB_VALUE-c.g,MAX_RGB_VALUE-c.b);
	}
}
void doGrayScale(Color colors[WIDTH][HEIGHT]) {
	for (unsigned int x = 0; x < WIDTH; x++) for (unsigned int y = 0; y < HEIGHT; y++) {
		Color c = colors[x][y];
		unsigned int shade = RED_WEIGHT * c.r + GREEN_WEIGHT * c.g + BLUE_WEIGHT * c.b;
		colors[x][y] = Color(shade,shade,shade);
	}
}
void doSpecial(Color colors[WIDTH][HEIGHT]) {
	srand(time(0));
	//Divide the puzzle into 'pieces' and shuffle them
	for (unsigned int x = 0; x < PUZZLE_WIDTH; x++) for (unsigned int y = 0; y < PUZZLE_HEIGHT; y++) {

		//Make a copy of the 'piece' we are in
		Color temp[PUZZLE_PIECE_WIDTH][PUZZLE_PIECE_HEIGHT];
		for (unsigned int px = 0; px < PUZZLE_PIECE_WIDTH; px++)
			for (unsigned int py = 0; py < PUZZLE_PIECE_HEIGHT; py++) {
				temp[px][py]=colors[PUZZLE_PIECE_WIDTH*x+px][PUZZLE_PIECE_HEIGHT*y+py];
		}

		//Determine a random 'piece' to swap with
		int otherX = rand()%PUZZLE_WIDTH;
		int otherY = rand()%PUZZLE_HEIGHT;

		//Copy another 'piece' into this location
		for (unsigned int px = 0; px < PUZZLE_PIECE_WIDTH; px++)
			for (unsigned int py = 0; py < PUZZLE_PIECE_HEIGHT; py++) {
				colors[PUZZLE_PIECE_WIDTH*x+px][PUZZLE_PIECE_HEIGHT*y+py]=
						colors[otherX*PUZZLE_PIECE_WIDTH+px][otherY*PUZZLE_PIECE_HEIGHT+py];
		}

		//Copy another 'piece' into this location
		for (unsigned int px = 0; px < PUZZLE_PIECE_WIDTH; px++)
			for (unsigned int py = 0; py < PUZZLE_PIECE_HEIGHT; py++) {
				colors[PUZZLE_PIECE_WIDTH*otherX+px][PUZZLE_PIECE_HEIGHT*otherY+py]=
						temp[px][py];
		}
	}
}
