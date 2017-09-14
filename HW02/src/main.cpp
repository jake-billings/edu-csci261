/* CSCI 261 HW 02: ARITHMETIC, CARS, and TRIANGLES
*
* Author: Jake Billings
* 01/20/2014
* CSCI261
*/

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <cmath>
#include <ios>
#include <iomanip>


//Use the standard namespace, so std::cout, etc.. is unnecessary
using namespace std;

int main() {
	// PART I: INSERT YOUR CODE BELOW HERE
	int x, y, z;
	cout << "X: ";
	cin >> x;
	cout << x << endl;

	cout << "Y: ";
	cin >> y;
	cout << y << endl;

	cout << "Z: ";
	cin >> z;
	cout << z << endl;

	cout << "X+Y=" << x + y << endl;
	cout << "(X+Y*Z)=" << (x + y * z) << endl;
	cout << "((X+Y)*Z)=" << ((x + y) * z) << endl;
	cout << "X/Y=" << x / y << endl;
	cout << "X%Y=" << x % y << endl;
	cout << "X/Y (decimal)=" << static_cast<double>(x) / static_cast<double>(y) << endl;

	// PART I INSERT YOUR CODE ABOVE HERE

	// PART II: INSERT YOUR CODE BELOW HERE
	double car1Time, car1Acceleration, car2Time, car2Acceleration;

	cout << "Car 1: ";
	cin >> car1Time;
	cout << car1Time << endl;

	cout << "Car 2: ";
	cin >> car2Time;
	cout << car2Time << endl;

	car1Acceleration = 60 / car1Time;
	car2Acceleration = 60 / car2Time;

	cout << "Car 1 Acceleration: " << car1Acceleration << " mph/s" << endl;
	cout << "Car 2 Acceleration: " << car2Acceleration << " mph/s" << endl;

	cout << "Ratio: " << car1Acceleration/car2Acceleration << endl;

	// PART II INSERT YOUR CODE ABOVE HERE

	// PART III: INSERT YOUR CODE BELOW HERE
	double p1x, p1y, p2x, p2y, p3x, p3y, side1, side2, side3, perimeter, s, area;
	cout << "Enter coordinates for the first point:";
	cin >> p1x;
	cin >> p1y;
	cout << "Enter coordinates for the second point:";
	cin >> p2x;
	cin >> p2y;
	cout << "Enter coordinates for the third point:";
	cin >> p3x;
	cin >> p3y;

	side1=sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
	side2=sqrt(pow(p3x - p1x, 2) + pow(p3y - p1y, 2));
	side3=sqrt(pow(p2x - p3x, 2) + pow(p2y - p3y, 2));

	perimeter = side1 + side2 + side3;

	s = perimeter/2.0;
	area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

	cout << setprecision(3);
	cout << "Sides of the triangle are " << side1 << "; " << side2 << "; " << side3 << endl;
	cout << "Perimeter of the triangle is " << perimeter << endl;
	cout << "Area of the triangle is " << area << endl;
	// PART III INSERT YOUR CODE ABOVE HERE

 	return 0;
}


