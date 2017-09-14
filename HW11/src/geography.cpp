/* CSCI 261 HW11: Class Fun
*
* Author: Jake Albers, Section B
*
* Implementation file for the Geography Trivia Class
*/

#include <iostream>
#include <string>
#include "geography.h"
using namespace std;

// Constructors
Geography::Geography() {
	question = "What is the capital of Djibouti?";
	answer = "Djibouti";
	prize = "Correct! Here are some stars  ***";
    wrong = "Nope, better luck next time.";
}

// Member functions
void Geography::Introduction() {
	cout << "Welcome to the geography trivia game!" << endl;
    cout << "You must answer the question correctly in order to get the prize." << endl << endl;
}

void Geography::GetQuestion(){
    cout << "Here is your question: " << endl;
    cout << "What is the capital of Djibouti?" << endl;
}

string Geography::GetPrize(){
	return prize;
}

bool Geography::CheckAnswer(const string guess){
    if (guess == answer){
        return true;
    }
    else {
        return false;
    }
}

string Geography::WrongAnswer() {
    return wrong;
}






