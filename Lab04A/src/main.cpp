/* CSCI 261 Lab 04A: Triangle Repl
 *
 * Author: Jake Billings
 * 01/30/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double inputA, inputB, inputC;
	bool isTriangle = false;

	while (!isTriangle) {
		cout << "Please enter a valid triangle." << endl;

		cout << "Side 1: ";
		cin >> inputA;
		cout << inputA << endl;

		cout << "Side 2: ";
		cin >> inputB;
		cout << inputB << endl;

		cout << "Side 3: ";
		cin >> inputC;
		cout << inputC << endl;

		isTriangle = inputA < inputB + inputC && inputB < inputA + inputC
				&& inputC < inputA + inputB;
	}

	cout << "Triangle is valid.";
}
