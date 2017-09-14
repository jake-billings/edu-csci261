/* CSCI 261 HW 05: Calculator
 *
 * Author: Jake Billings
 * 01/30/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>

using namespace std;

double doPoundsToKilograms(double pounds) {
	return pounds/2.20462;
}

double doFeetToMeters(double feet) {
	return feet/0.3048;
}

double doBMI(double weight, double height) {
	return (weight/(height*height));
}

double doGBtoMB(double gb) {
	return gb*1024;
}

void poundsToKilograms() {
	double input;
	cout << "Pounds: ";
	cin >> input;
	cout << doPoundsToKilograms(input) << endl;
}

void feetToMeters() {
	double input;
	cout << "Feet: ";
	cin >> input;
	cout << doFeetToMeters(input) << endl;
}

void bodyMassIndex() {
	double inputPounds, inputFeet;
	cout << "Pounds: ";
	cin >> inputPounds;
	cout << "Feet: ";
	cin >> inputFeet;
	cout << doBMI(doPoundsToKilograms(inputPounds),doFeetToMeters(inputFeet)) << endl;
}
void gbToMb() {
	double input;
	cout << "Gigabytes: ";
	cin >> input;
	cout << doGBtoMB(input) << endl;
}


void menu() {
	int input;

	cout << "Type a number to select calculation." << endl;
	cout << "1 - Pounds to Kilograms" << endl;
	cout << "2 - Feet to Meters" << endl;
	cout << "3 - BMI" << endl;
	cout << "4 - Gigabytes to Megabytes" << endl;
	cout << "Input: ";

	cin >> input;

	switch (input) {
			case 1:
				poundsToKilograms();
				break;
			case 2:
				feetToMeters();
				break;
			case 3:
				bodyMassIndex();
				break;
			case 4:
				gbToMb();
				break;
			default:
				cout << "Invalid input." << endl;
	}
}

int main() {
// DO NOT change this main function

     menu();

     return 0;

} // end of Main Function
