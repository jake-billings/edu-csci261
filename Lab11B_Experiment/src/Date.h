/*
 * Date.h
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */

#pragma once

class Date {
private:
	long long day;

public:
	const static int MONTHS_IN_YEAR = 12;
	const static int DAYS_IN_MONTHS[MONTHS_IN_YEAR];

	Date();

	long long getDay();
	void setDay(long long day);

	int getDayOfMonth();
	int getMonthOfYear();
	int getYear();
	int getDayOfWeek();

	void setDate(int day, int month, int year);
};
