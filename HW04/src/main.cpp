/* CSCI 261 HW 04: Number Guessing Game
 *
 * Author: Jake Billings
 * 01/30/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//Declare a variable to hold a user's guess
	int guess;

	//Set a seed based on the time
	srand(time(NULL));

	//Generate a random number to guess
	int number = rand()%99+1;

	//Declare a variable to store how many times the player has guessed
	int tryCount = 0;

	//Welcome message
	cout << "Hold onto your pants, we're about to play guess-the-numbah!" << endl;

	//Main loop
	do {
		//Get the user's guess
		cout << "Guess a number between 0 and 100: ";
		cin >> guess;

		//Print if it was too high or too low
		if (guess > number) {
			cout << "Too high!";
		} else if (guess < number) {
			cout << "Too low!";
		}

		//Calculate how far off the user was
		int distance = abs(number-guess);

		//Taunt the user if their guess was too far off or tell them if they are close
		if (distance!=0) {
			if (distance<=10) {
				cout << " Oooh you're close!";
			} else if (distance>30) {
				cout << " You're not even close!";
			}
		}

		cout << endl;

		//Increment the number of times tried
		tryCount++;
	} while (guess != number);

	//Exit message
	cout << "You guessed the number in " << tryCount << " tries.";

	return EXIT_SUCCESS;
}
