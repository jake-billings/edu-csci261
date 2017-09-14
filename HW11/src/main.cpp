//============================================================================
// Name        : HW11
// Author      : Jake Billings
//
//I shared the code for my Arithmetic Quiz with Steven Clark, Lucas Peterson, Jake Albers, and Emias Girmai
//============================================================================


#include <iostream>
#include "BillingsMagicItem.h"
#include "BullsAndCows.h"
#include "Magic.h"
#include "geography.h"

using namespace std;

int main() {
	//My Magic Item

	cout << "Playing Jake Billings' Arithmetic Quiz" << endl;

	BillingsMagicItem billings;

	billings.Introduction();

	while (!billings.hasReceivedPrize()) {
		billings.RunRound();
		cout << "Current score: " << billings.getScore() << endl;
	}

	cout << "Congratulations! You win!" << endl;

	//Steven Clark's Magic Item
	cout << "Playing Steven Clark's Song Quiz" << endl;

	MagicThing clark;

	string answerOne, answerTwo;

	cout << clark.GetSongLineOne() << endl;
	cout << "Answer: ";
	cin >> answerOne;

	cout << clark.GetSongLineTwo() << endl;
	cout << "Answer: ";
	cin >> answerTwo;

	if (clark.CheckAnswerOne(answerOne)&&clark.CheckAnswerTwo(answerTwo)) {
		cout << "You answered both questions correctly!" << endl;
		cout << "Prize: " << clark.GetPrize() << endl;
	} else {
		cout << "Sorry.  You answered one or more questions wrong.  No prize for you." << endl;
	}

	//Lucas Peterson's Magic Item
	cout << "Playing Lucas Peterson's Bulls and Cows" << endl;

	BullsAndCows peterson;

	peterson.RunBullsAndCows();

	//Jake Albers' Geography Quiz
	cout << "Playing Jake Albers' Geography Quiz" << endl;

	Geography albers;

	albers.Introduction();
	albers.GetQuestion();

	string guess;

	cout << "Answer: ";
	cin >> guess;

	albers.GetQuestion();

	if (albers.CheckAnswer(guess)) {
		cout << "Correct." << endl;
		cout << "Prize: " << albers.GetPrize() << endl;
	} else {
		cout << "Incorrect." << endl;
		cout << albers.WrongAnswer() << endl;
	}

	return 0;
}
