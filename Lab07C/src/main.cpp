/* CSCI261 Lab 07A: Star File
 *
 * Author: Jake Billings
 */
#include <iostream>
using namespace std;

int main() {
	const int NUMBER_COUNT = 5;

	cout << "Hey! Witness my first array mojo!" << endl;
	cout << "Enter " << NUMBER_COUNT << " numbers and I will tell you which is the largest." << endl;

	int numbers[NUMBER_COUNT];

	for (int i = 0; i < NUMBER_COUNT; i++) {
		cout << "Number " << i+1 << ": ";
		cin >> numbers[i];
	}

	cout << "So awesome!" << endl;

	int largest = 0;
	for (int i = 0; i < NUMBER_COUNT; i++) {
		if (numbers[i]>largest) {
			largest = numbers[i];
		}
	}

	cout << "The largest number was " << largest;

	return 0;
}
