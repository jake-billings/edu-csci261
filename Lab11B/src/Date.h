/*
 * Date.h
 *
 *  Created on: Apr 6, 2015
 *      Author: jakebillings
 */

#pragma once

class Date {
private:
	int day;
	int month;
	int year;

	void validate();
	bool isValid();

public:
	const static int MONTHS_IN_YEAR = 12;
	const static int DAYS_IN_MONTHS[MONTHS_IN_YEAR];

	const static int EPOCH_YEAR=1970;

	const static int DEFAULT_DAY=0; //First day of month
	const static int DEFAULT_MONTH=0; //January
	const static int DEFAULT_YEAR=0; //YEAR 0 IS 1970, the epoch

	Date();
	Date(int day, int month, int year);

	int getDay();
	int getMonth();
	int getYear(); //Returns the year relative to the EPOCH_YEAR

	int getAdjustedYear(); //Get the year adjusted for the epoch

	void setDate(int day, int month, int year);

	void setAdjustedDate(int day, int month, int adjustedYear); //Set date adjusted for epoch
};
