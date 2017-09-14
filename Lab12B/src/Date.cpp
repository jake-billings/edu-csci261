/*
 * Date.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */

#include <iostream>
#include "Date.h"

using namespace std;

const int Date::DAYS_IN_MONTHS[Date::MONTHS_IN_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 30, 30, 31};

int Date::getDay() {
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear() {
	return year;
}

int Date::getAdjustedYear() {
	return year+EPOCH_YEAR;
}

void Date::setDate(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year-EPOCH_YEAR;

	validate();
}

void Date::setAdjustedDate(int day, int month, int year) {
	setDate(day,month,year-EPOCH_YEAR);
}

bool Date::isValid() {
	if (getMonth()<1||getMonth()>MONTHS_IN_YEAR) return false;
	if (getDay()<1||getDay()>DAYS_IN_MONTHS[getMonth()]) return false;
	if (getAdjustedYear()<1) return false;

	return true;
}
void Date::validate() {
	if (!isValid()) {
		setDate(DEFAULT_DAY,DEFAULT_MONTH,DEFAULT_YEAR);
	}
}

string Date::toString() {
	return to_string(getMonth()) + "/" +
			to_string(getDay()) + "/" +
			to_string(getAdjustedYear());
}

Date::Date() {
	setDate(30,12,1950);
	cout << "Constructing default date: 12/30/1950, the date Vietnam, Laos, and Cambodia became independent states." << endl;
}

Date::Date(int day, int month, int year) {
	setDate(day,month,year);

	if (getDay()==1&&getMonth()==8&&getAdjustedYear()==1876) {
		cout << "Now constructing date: 12/1/1876, the date Colorado became a state." << endl;
	}
}
