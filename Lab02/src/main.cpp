/* CSCI 261 Lab 02: Volume of Prism (Calculates the volume of a right rectangular prism)
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
	//Declare variables
    int length;
    int width;
    int height;
    int volume;

    //Gather user input
    cout << "Length: ";
    cin >> length;

    cout << "Width: ";
    cin >> width;

    cout << "Height: ";
    cin >> height;

    // Volume of a box is length times width times height.
    volume = length * width * height;

    cout << "Volume of prism: " << volume;

  return 0; // signals the operating system that our program ended OK.

}
