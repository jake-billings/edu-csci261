/* CSCI 261 Lab 02A: Area of a Circle (Calculates the volume of a circle)
*
* Author: Jake Billings
* 01/14/2014
* CSCI261
*/

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{
	//Initialize Constants
	const double PI = 3.14592;

	//Declare variables
    double radius;
    double area;

    //Gather user input
    cout << "Radius: ";
    cin >> radius;

    // Calculate area
    area = PI * radius * radius;

    //Print output
    cout << "Area of circle with radius " << radius << " : " << area;

  return 0; // signals the operating system that our program ended OK.

}
