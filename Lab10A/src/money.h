/* CSCI261 Lab 10A: Money Class
*
* Description: Header file for Money Class
*
* Author: Jake Billings
*
*/
#pragma once
class Money {
private:
	int dollars;
	int cents;
public:
	Money();
	Money(const int& newDollars,const int& newCents);

	void SetDollars(const int& newDollars);
	void SetCents(const int& newCents);

	int GetDollars();
	int GetCents();
};
