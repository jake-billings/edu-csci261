/* CSCI 261 Lab 05A: Intro to Functions
*
* Author: Jake Billings
*
* This program demonstrates functions using random number generation
*/

#include <iostream>
using namespace std;

short myRand(int theSeed) {
	srand(theSeed);
	return rand()%3;
}

int main() {
	int seed;
	cout << "Enter a Random Seed: ";
	cin >> seed;

	cout << "Output: " << myRand(seed);

    return 0;
}
