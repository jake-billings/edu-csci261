/* CSCI261 Lab 07A: Star File
 *
 * Author: Jake Billings
 */
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//Character that separates values
	const char FIELD_DELIMETER = '\t';

	//Width and height to map star coordinates to
	const int WIDTH = 640;
	const int HEIGHT = WIDTH;

	ifstream data("stars.txt");
	ofstream output("ModifiedStars.txt");

	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	if ( output.fail() ) {
		cerr << "Error opening output file";
		exit(1);
	}

	while (!data.eof()) {
		//Read x
		double xStar;
		data >> xStar;

		//Read yStar
		double yStar;
		data >> yStar;

		//Read zStar
		double zStar;
		data >> zStar;

		//Read brightness
		double brightness;
		data >> brightness;

		//Read Harvard and Draper
		double draper;
		data >> draper;
		double harvard;
		data >> harvard;

		//Ignore brightness outside the inclusive range 0-8
		if (brightness <= 8.0 && brightness >= 0) {
			//Perform calculations
			int xPixel = (int)( ( xStar + 1 ) * WIDTH / 2 );
			int yPixel = (int)( ( yStar + 1 ) * HEIGHT / 2 );

			//Output modified values
			output << xPixel << FIELD_DELIMETER << yPixel << FIELD_DELIMETER << brightness << endl;
		}
	}

	return 0;
}
