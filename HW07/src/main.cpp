/* CSCI261 Homework 7: Letter Frequency
 *
 * Author: Jake Billings
 *
 * Description: Analyzes the letter frequencies of a text file and displays a graph using SFML
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Global variables (constants)
const string FONT_NAME = "data/arial.ttf";
const int WIDTH = 800;
const int HEIGHT = 600;

// function prototypes
string charToString(char);
void doubleDraw(RenderWindow&, Drawable&);

int main()
{
	// Part I - Console Interface
	/***** Begin your code for Part I here *****/
	const int NUMBER_OF_LETTERS = 26; //The number of letters in the alphabet

	int letterCount[NUMBER_OF_LETTERS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //An array of appropriate size to hold a count for each letter

	//Open a data stream
	ifstream data("data/alice.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	//Read letters from the file
	while (!data.eof()) {
		//Read a single char
		char c = data.get();
		//If the ASCII value is greater than 'Z', subtract 32
		//This converts lowercase letters to uppercase letters and changes punctuation marks/other values
		if (c > 90) c -= 32;

		//Addresses the letter A at array index 0, so that the letter counts fit in the array
		int index = ((int) c) - 65;

		//If the ASCII value is an uppercase letter, count it
		if (index>=0&&index<NUMBER_OF_LETTERS) {
			//cout << index << endl;
			//and increments that location
			letterCount[index]++;
		}
	}

	char mostCommonLetter;
	int mostCommonLetterCount=0;

	for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
		//Prints the letter of the address in the letter count array
		//(Converts 0 to A and so on)
		//and prints the quantity of that letter
		cout << (char) (i+97) << ": " << letterCount[i] << endl;
		if (letterCount[i]>mostCommonLetterCount) {
			mostCommonLetter = (char) (i+97);
			mostCommonLetterCount = letterCount[i];
		}
	}

	cout << "The most common letter was: " << mostCommonLetter << endl;

	/***** End of your code for Part I *****/

	// Part II - Graphical User Interface
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Letter Frequencies");
	window.clear(Color::Black);
	Font font;
	if (!font.loadFromFile(FONT_NAME))
	{
		cout << "Couldn't open font file!\n";
		return EXIT_FAILURE;
	}
	RectangleShape bar;
	Text text;
	text.setFont(font);
	text.setStyle(Text::Bold);
	text.setCharacterSize(14);

	/***** Begin your code for Part II here *****/
	//The width of each
	const float BAR_WIDTH = 32;

	for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
		//Map the bar height to the screen
		int barHeight = letterCount[i] * HEIGHT / mostCommonLetterCount;

		//Set the size of the bar
		bar.setSize(Vector2f(BAR_WIDTH, barHeight));

		//Set the position of the bar (ensure it gets flipped such that it is right side up)
		bar.setPosition(Vector2f(BAR_WIDTH*i, HEIGHT-barHeight));

		//Draw the bar as red if it is the most common and white if it is not
		if (letterCount[i]==mostCommonLetterCount) {
			bar.setFillColor(Color::Red);
		} else {
			bar.setFillColor(Color::White);
		}

		//Draw the bar
		window.draw(bar);

		//Label the bar
		//Set the position
		text.setPosition(Vector2f(BAR_WIDTH*i+10, HEIGHT-24));
		//Convert the index to a lowercase letter string
		text.setString(charToString(i+97));
		//Set text color to blue
		text.setColor(Color::Blue);
		//Draw the text
		window.draw(text);
	}

	//Display the window
	window.display();

	/***** End of your code for Part II *****/

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();
	}


	return EXIT_SUCCESS;
}

// Converts a char to a string
string charToString(char c)
{
	stringstream ss;
	ss << c;
	string s;
	ss >> s;
	return s;
}

// Draw and display using double-buffering
void doubleDraw(RenderWindow& rw, Drawable& d) {
	// Draw d to BOTH on-screen and off-screen framebuffers
	rw.draw(d);
	rw.display();
	rw.draw(d);
	rw.display();
}
