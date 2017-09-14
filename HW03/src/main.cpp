/* CSCI 261 Lab 03A: Triangle Classification
 *
 * Author: Jake Billings
 * 01/25/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>

using namespace std;

const string welcomeMessage =
		"Welcome one and all to a round of Rock, Paper Scissors! (Enter P, R or S): ";

//Converts chars R, P, and S to Rock, Paper, and Scissors
string rpsToString(char rps) {
	 if (rps == 'R') {
		 return "Rock";
	 } else if (rps == 'P') {
		 return "Paper";
	 } else if (rps == 'S'){
		 return "Scissors";
	 }
	 return "Error";
}

int main() {
	char oneInput, twoInput;
	string one, two, winner;

	cout << welcomeMessage << endl;

	//Input player moves
	cout << "Player One: ";
	cin >> oneInput;

	srand(time(NULL));
	int randNum = rand() % 3;

	if (randNum == 0) {
		twoInput = 'r';
	} else if (randNum == 1) {
		twoInput = 'p';
	} else {
		twoInput = 's';
	}

	cout << "Computer: " << twoInput << endl;

	//Convert letters to uppercase
	if (oneInput > 'Z') {
		oneInput -= 32;
	}
	if (twoInput > 'Z') {
		twoInput -= 32;
	}

	//Determine the winner in every possible game.
	if (oneInput == 'R') {
		if (twoInput == 'R') {
			winner = "Neither";
		} else if (twoInput == 'P') {
			winner = "Computer";
		} else if (twoInput == 'S') {
			winner = "Player One";
		}
	} else if (oneInput == 'P') {
		if (twoInput == 'R') {
			winner = "Player One";
		} else if (twoInput == 'P') {
			winner = "Neither";
		} else  if (twoInput == 'S') {
			winner = "Computer";
		}
	} else if (oneInput == 'S') {
		if (twoInput == 'R') {
			winner = "Computer";
		} else if (twoInput == 'P') {
			winner = "Player One";
		} else  if (twoInput == 'S') {
			winner = "Neither";
		}
	}

	//Print the string version of the winning player's move
	if (winner!="Neither") {
	if (winner == "Player One") {
		cout << rpsToString(oneInput);
	} else if (winner == "Computer") {
		cout << rpsToString(twoInput);
	}

	cout << " beats ";

	//Print the string version of the losing player's move
	if (winner == "Player One") {
		cout << rpsToString(twoInput);
	} else if (winner == "Computer") {
		cout << rpsToString(oneInput);
	}
	} else {
		cout << "Looks like it's a tie";
	}

	//Print the winner
	cout << ". " << winner << " wins."<< endl;

}
