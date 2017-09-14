/* CSCI261 Lab 10A: Money Class
 *
 * Description: Implementation file for Money Class
 *
 * Author: Jake Billings
 *
 */
#include "money.h"


Money::Money() {
	dollars=0;
	cents=0;
}
Money::Money(const int& newDollars,const int& newCents) {
	dollars=newDollars;
	cents=newCents;
}

void Money::SetDollars(const int& newDollars){
	dollars = newDollars;
}
void Money::SetCents(const int& newCents) {
	cents = newCents;
}

int Money::GetDollars() {
	return dollars;
}
int Money::GetCents() {
	return cents;
}

