/* CSCI 261 Lab 02B: ASCII Fun (Converts five characters to uppercase)
*
* Author: Jake Billings
* 01/20/2014
* CSCI261
*/

// The include section adds extra definitions from the C++ standard library.
#include <iostream>

//Use the standard namespace, so std::cout, etc.. is unnecessary
using namespace std;

int main() {
	//Define constants
	const string yellingMessage = " - why are you yelling?"; //Message to accompany five characters
	int size=5; //Number of characters to be collected

	char chars[size]; //Declare an array to hold the ASCII letters

	//Fill the array with user input
	for (int i=0;i<size;i++) {
		cin >> chars[i];//Input user information
		chars[i]-=32;//Subtract 32 from the ASCII value to convert the letter to ASCII
	}

	//Print the stored values
	for (int i=0;i<size;i++) {
		cout << chars[i];
	}

	//Print the final message
	cout << yellingMessage << endl;

 	return 0;
}


