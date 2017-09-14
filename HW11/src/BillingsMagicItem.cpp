/*
 * BillingsMagicItem.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: jakebillings
 */

#include "BillingsMagicItem.h"
#include <random>
#include <iostream>

using namespace std;

int BillingsMagicItem::generateRandomNumber() {
	return rand()%MAX_RANDOM_NUMBER+1;
}

char BillingsMagicItem::generateRandomOperation() {
	int id = rand() % 3;
	switch (id) {
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	//Exclude division
	//case 3:
	//	return '/';
	}
	return 'e'; //e for error cause it shouldn't ever happen
}
int BillingsMagicItem::performOperation(char op, int a, int b) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	return 0;
}

void BillingsMagicItem::Introduction() {
	cout << "Welcome to Jake's Arithmetic Quiz." << endl;
	cout << "You will be asked to perform an arithmetic operation on two numbers" << endl;
	cout << getRequiredScore() << " correct answers are required to win." << endl;
	cout << "Good Luck!" << endl;
}

void BillingsMagicItem::RunRound() {
	int a = generateRandomNumber();
	int b = generateRandomNumber();
	char op = generateRandomOperation();

	int answer = performOperation(op,a,b);

	int userAnswer;

	cout << "What is " << a << " " << op << " " << b << "?" << endl;
	cout << "Answer: ";

	cin >> userAnswer;

	if (answer==userAnswer) {
		cout << "Correct!" << endl;
		setScore(getScore()+1); //We could access the field directly, but user getters and setters for formality
	} else {
		cout << "Incorrect." << endl;
	}
}

int BillingsMagicItem::getRequiredScore() {
	return requiredScore;
}

void BillingsMagicItem::setRequiredScore(int requiredScore) {
	this->requiredScore = requiredScore;
}

int BillingsMagicItem::getScore() {
	return score;
}

void BillingsMagicItem::setScore(int score) {
	this->score = score;
}

bool BillingsMagicItem::hasReceivedPrize() {
	return getScore() >= 10;
}

void BillingsMagicItem::init(int score, int requiredScore) {
	setScore(score);
	setRequiredScore(requiredScore);
}

BillingsMagicItem::BillingsMagicItem() {
	init(0,10);
}

