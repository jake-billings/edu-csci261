/*Author: Luke Peterson
CSCI 261 Section F
Bulls and Cows Implementation File*/

#include "BullsAndCows.h"
#include <iostream>
//#include "windows.h" - not sure if this is Microsoft Windows, but I (Jake) am on Mac..
#include <random>
#include <ctime>

using namespace std;

BullsAndCows::BullsAndCows() {
    guess = 0;
    numGuesses = 0;
    difficulty = 4;
}
void BullsAndCows::ExplainRules() {
    cout << "Welcome! We're about to play Bulls and Cows,\nan exciting number guessing game!" << endl;
    cout << "Here are the rules:" << endl;
    cout << "One player, the Chooser (the computer), thinks of a four - digit number\nand the other player, the Guesser (you), tries to guess it." << endl << endl;
    cout << "At each turn the Guesser tries a four, five, or six digit number depending\non your difficulty, and the Chooser says how close\nit is to the answer by giving: " << endl << endl;
    cout << "The number of Bulls - digits correct in the right position." << endl;
    cout << "The number of Cows - digits correct but in the wrong position." << endl << endl;
    cout << "The Guesser tries to guess the answer in the fewest number of turns." << endl;
    cout << "Dupilicate digits in either number can be counted for twice and bulls\nare counted before cows." << endl << endl;
    cout << "Are you ready to play?!" << endl << endl;
}
void BullsAndCows::SetupGameplay() {
    int d;
    bool outOfRange = false;
    while (outOfRange == false) {
        cout << "Choose your difficulty: 4 digits, 5 digits, or 6 digits: ";
        cin >> d;
        if (d != 4 && d != 5 && d != 6) {
            cout << "Please choose 4, 5, or 6." << endl;
        }
        else {
            outOfRange = true;
            SetDifficulty(d);
        }
    }
}
void BullsAndCows::SetDifficulty(int d) {
    difficulty = d;
}
int BullsAndCows::GetDifficulty() {
    return difficulty;
}
void BullsAndCows::SetRandomNumber() {
    srand(time(NULL));
    switch (difficulty) {
    case 4:
        randNum = rand() % 9000 + 1000;
        break;
    case 5:
        randNum = rand() % 90000 + 10000;
        break;
    case 6:
        randNum = rand() % 900000 + 100000;
        break;
    }
    SplitRandNumDigits();
    cout << "I, the mighty bull, have chosen my number." << endl;
}
int BullsAndCows::GetRandomNumber() {
    return randNum;
}
void BullsAndCows::SetGuess() {
    int g;
    guessDigits.clear();    
    cout << "Make your " << difficulty << " digit guess of what number the bull has chosen: ";
    cin >> g;
    guess = g;
    SplitGuessDigits();
}
void BullsAndCows::SplitGuessDigits() {
    switch (difficulty) {
    case 4:
        guessDigits.push_back(guess / 1000 % 10);
        guessDigits.push_back(guess / 100 % 10);
        guessDigits.push_back(guess / 10 % 10);
        guessDigits.push_back(guess % 10);
        break;
    case 5:
        guessDigits.push_back(guess / 10000 % 10);
        guessDigits.push_back(guess / 1000 % 10);
        guessDigits.push_back(guess / 100 % 10);
        guessDigits.push_back(guess / 10 % 10);
        guessDigits.push_back(guess % 10);
        break;
    case 6:
        guessDigits.push_back(guess / 100000 % 10);
        guessDigits.push_back(guess / 10000 % 10);
        guessDigits.push_back(guess / 1000 % 10);
        guessDigits.push_back(guess / 100 % 10);
        guessDigits.push_back(guess / 10 % 10);
        guessDigits.push_back(guess % 10);
        break;
    }
}
void BullsAndCows::SplitRandNumDigits() {
    switch (difficulty) {
    case 4:
        randNumDigits.push_back(randNum / 1000 % 10);
        randNumDigits.push_back(randNum / 100 % 10);
        randNumDigits.push_back(randNum / 10 % 10);
        randNumDigits.push_back(randNum % 10);
        break;
    case 5:
        randNumDigits.push_back(randNum / 10000 % 10);
        randNumDigits.push_back(randNum / 1000 % 10);
        randNumDigits.push_back(randNum / 100 % 10);
        randNumDigits.push_back(randNum / 10 % 10);
        randNumDigits.push_back(randNum % 10);
        break;
    case 6:
        randNumDigits.push_back(randNum / 100000 % 10);
        randNumDigits.push_back(randNum / 10000 % 10);
        randNumDigits.push_back(randNum / 1000 % 10);
        randNumDigits.push_back(randNum / 100 % 10);
        randNumDigits.push_back(randNum / 10 % 10);
        randNumDigits.push_back(randNum % 10);
        break;
    }
}
void BullsAndCows::EvaluateGuess() {
    int bulls = 0;
    int cows = 0;
    bool correctGuess = false;
    while (correctGuess == false) {
        SetGuess();        
        if (guess == randNum) {
            correctGuess = true;
            PresentAward();
            break;
        }
        for (int i = 0; i < difficulty; i++) {
            if (guessDigits.at(i) == randNumDigits.at(i)) {
                bulls++;
            }
            else {
                for (int j = 0; j < difficulty; j++) {
                    if (j == i) {
                    }
                    else if (guessDigits.at(i) == randNumDigits.at(j)) {
                        cows++;
                    }
                }
            }
        }
        cout << "You have " << bulls << " bulls and " << cows << " cows." << endl;
        guessDigits.clear();
        bulls = 0;
        cows = 0;
        numGuesses++;
    }
    
}
void BullsAndCows::PresentAward() {
    cout << "Congratulations! You have guessed the bulls\nnumber in " << numGuesses << " guesses!" << endl;
    cout << "As a winner of the game Bulls and Cows," << endl;
    cout << "and a resident of the great state of Colorado\nwhich is home to the Rocky Mountains," << endl;
    cout << "I am proud to present to you, a plate full of your very own... wait for it..." << endl;
    cout << "5" << endl;
    //Sleep(1000); - Windows specific.  Commented out by Jake on Mac
    cout << "4" << endl;
    //Sleep(1000);
    cout << "3" << endl;
    //Sleep(1000);
    cout << "2" << endl;
    //Sleep(1000);
    cout << "1" << endl;
    //Sleep(1000);
    cout << "Rocky Mountain Oysters. Enjoy." << endl;
}
void BullsAndCows::RunBullsAndCows() {
    BullsAndCows user1;
    user1.ExplainRules();
    user1.SetupGameplay();
    user1.SetRandomNumber();
    user1.EvaluateGuess();
}
