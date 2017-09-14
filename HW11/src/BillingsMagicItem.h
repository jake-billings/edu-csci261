/*
 * BillingsMagicItem.h
 *
 *  Created on: Apr 7, 2015
 *      Author: jakebillings
 */
#pragma once

class BillingsMagicItem {
private:
	int score;
	int requiredScore;

	int generateRandomNumber();
	char generateRandomOperation();
	int performOperation(char op, int a, int b);

	void init(int score, int requiredScore);
public:
	static const int MAX_RANDOM_NUMBER = 20;

	BillingsMagicItem();

	void Introduction();
	void RunRound();

	int getRequiredScore();
	void setRequiredScore(int requiredScore);
	int getScore();
	void setScore(int score);

	bool hasReceivedPrize();
};

