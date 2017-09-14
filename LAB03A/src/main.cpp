/* CSCI 261 Lab 03A: Triangle Classification
*
* Author: Jake Billings
* 01/25/2015
* CSCI261
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const double TOLERANCE = 0.0001;

	//Record inputs
	double side1, side2, side3;
	cout << "Side 1: ";
	cin >> side1;
	cout << side1 << endl;

	cout << "Side 2: ";
	cin >> side2;
	cout << side2 << endl;

	cout << "Side 3: ";
	cin >> side3;
	cout << side3 << endl;

	//Determine if the side lengths can form a triangle
	if (side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2) {
		//Sort the values such that they can follow the Pythagorean formula a^2 + b^2 = c^2
		double a, b, c;
		//A should be the minimum
		a = min(side1, min (side2, side3));

		//C should be the maximum
		c = max(side1, max(side2, side3));

		//B will be the other number
		b = side1 + side2 + side3 - a - c;

		//The left side of the equation
		double leftSide = pow(a, 2) + pow(b, 2);
		double rightSide = pow(c, 2);

		//Check if the triangle is right using double tolerance
		if (leftSide - rightSide <= TOLERANCE) {
			cout << "The triangle is right.";

		//Check if the triangle is left
		} else if (leftSide > rightSide) {
			cout << "The triangle is acute.";

		//The triangle is probably obtuse
		} else {
			cout << "The triangle is obtuse.";
		}
	} else {
		cout << "Each side must be less than the sum of the others to form a triangle.";
	}

	return 0;
}
