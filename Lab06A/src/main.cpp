/* CSCI261 Lab 06A: Miscellaneous Functions
 *
 * Author: Jake Billings
*/
#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

double areaRectangle(double width, double height);
double inputDiameter();
int countVowels(const string& str);

int main() {
    cout << "Testing functions..." << endl << endl;

    cout << "Five vowels in 'aeiou': " << countVowels("aeiou") << endl;
    cout << "Four vowels in 'This is a test.': " << countVowels("This is a test.") << endl;
    cout << "The area of a 3x4 rectangle is 12: " << areaRectangle(3,4) << endl << endl;
    double diamter = inputDiameter();
    cout << "Inputted Diameter: " << diamter << endl;

    // Exit program.
    return 0;
}

double areaRectangle(double width, double height) {
	return width * height;
}

double inputDiameter() {
	cout << "Hello! Here is your joke of the day: " << endl << endl;

	cout << "What do you get if you divide the circumference of a pumpkin by its diameter?" << endl;
	cout << "Pumpkin pi of course. Yum." << endl << endl;

	cout << "Please enter your pumpkin's diameter: ";

	double input;
	cin >> input;

	return input;
}

int countVowels(const string& str) {
	int count = 0;
	for (int i=0;i<str.length();i++) {
		char c = str.at(i);
		//Test upper and lower case
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
				||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
			count++;
		}
	}
	return count;
}
