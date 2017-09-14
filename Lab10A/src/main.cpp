/* CSCI261 Lab 10A: Money Class
*
* Author: Tracy Camp
*
* Purpose: give students practice to (1) define classes with
* public member variables and (2) define and implement constructors.
*
* YOU SHOULD NOT MODIFY THIS CODE.
*/

#include <iostream>
#include "money.h"

using namespace std;

int main() {

    cout << "Who doesn't love money?" << endl << endl;

    Money myMoney;
    myMoney.SetDollars(999);
    myMoney.SetCents(99);
    cout << "I have $" << myMoney.GetDollars() << ".";
    cout << myMoney.GetCents() << endl;

    Money yourMoney(987, 65); // dollars and cents
    cout << "You have $" << yourMoney.GetDollars();
    cout << "." << yourMoney.GetCents() << endl;
    cout << endl;

    cout << "I have $" << (myMoney.GetDollars() - yourMoney.GetDollars()) << ".";
    cout << (myMoney.GetCents() - yourMoney.GetCents()) << " more money than you!" << endl;

    return 0;

}
