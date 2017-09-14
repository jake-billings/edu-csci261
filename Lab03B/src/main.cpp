/* CSCI 261 Lab03B: Triangles Classifier + Options Menu
 *
 * Author: Jake Billings
 * 01/25/2015
 * CSCI261
 *
 * The goal of this lab is to practice the use of if-else statements to classify triangles based on their sides.
 * It will also teach you how to correctly compare double values for equality using a tolerance factor and
 * the use of a menu of options using the switch statement.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <string>   // For string class
#include <cmath>    // For math functions

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants or global variables below this comment.
const double TOLERANCE = 0.0001;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
	int option;                     // to store the user's option (1-5)
	double inputA, inputB, inputC;  // to store user's side measurements
	double a, b, c;     // to copy side measurements such that c >= a and c >= b
	bool isTriangle = false; // states that side measuremenst can actually be use as sides of a triangle

	do {
		// show the menu
		cout << "\n1. Enter measurements\n";
		cout << "2. Print measurements\n";
		cout << "3. Check triangle feasibility\n";
		cout << "4. Classify triangle\n";
		cout << "5. Exit\n";

		// read user's choice
		cout << "Please, choose an option: ";
		cin >> option;

		// ignore option if not 1-5
		if (option < 1 || option > 5) {
			cout << "Invalid option!\n";
			continue;
		}

		//Use a switch to check what the user entered
		switch (option) {
		case 1:
			//Case 1: input measurements
			cout << "Side 1: ";
			cin >> inputA;
			cout << inputA << endl;

			cout << "Side 2: ";
			cin >> inputB;
			cout << inputB << endl;

			cout << "Side 3: ";
			cin >> inputC;
			cout << inputC << endl;

			//Determine if sides form a triangle
			isTriangle = inputA < inputB + inputC && inputB < inputA + inputC
					&& inputC < inputA + inputB;
			break;

		case 2:
			//Case 2: output measurements
			cout << "Side 1: " << inputA << endl;
			cout << "Side 2: " << inputB << endl;
			cout << "Side 3: " << inputC;
			break;

		case 3:
			//Case 3: output if sides form a triangle
			if (isTriangle) {
				cout << "Sides do form a triangle";
			} else {
				cout << "Sides do not form a triangle.";
			}
			break;

		case 4:
			//Case 4: classify triangle
			if (isTriangle) { //Only classify if the sides form a triangle
				double a, b, c;
				//A should be the minimum
				a = min(inputA, min(inputB, inputC));

				//C should be the maximum
				c = max(inputA, max(inputB, inputC));

				//B will be the other number
				b = inputA + inputB + inputC - a - c;

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
				cout << "The sides do not form a triangle.";
			}
			break;
		}
		cout << endl;
	} while (option != 5);

	return EXIT_SUCCESS; // signals the operating system that our program ended OK.
}
