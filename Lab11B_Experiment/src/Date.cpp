/*
 * Date.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */

#include <iostream>
#include "Date.h"

const int Date::DAYS_IN_MONTHS[Date::MONTHS_IN_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 30, 30, 31};

long long Date::getDay() {
	return day;
}

void Date::setDay(long long day) {
	this->day = day;
}

int Date::getDayOfMonth() {
	int dayOfMonth = day;

	int month = 0;
	while (dayOfMonth>DAYS_IN_MONTHS[month]) {
		dayOfMonth-=DAYS_IN_MONTHS[month=(month+1)%MONTHS_IN_YEAR];
	}

	std::cout<<day<<std::endl;
	return day%(DAYS_IN_MONTHS[month]+1);
}

int Date::getMonthOfYear() {
	return day/30%12;
}

int Date::getYear() {
	return day/30;
}

int Date::getDayOfWeek() {
	return day%7;
}

void Date::setDate(int day, int month, int year) {
	int monthI = 0;
	int dayOfMonth;
	int dayCount;

	while (day>DAYS_IN_MONTHS[monthI]) {
		dayCount += DAYS_IN_MONTHS[monthI];
		day-=DAYS_IN_MONTHS[monthI=(monthI+1)%MONTHS_IN_YEAR];
	}

	this->day = day + 30*month + 365*year;
}

Date::Date() {
	setDate(30,12,1950);
}
