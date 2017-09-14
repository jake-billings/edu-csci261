#pragma once

#include <string>
#include "Date.h"

using namespace std;

class MyDate {
private:
	Date date;
	string name;
	int age;
	int rating;
public:
	static const int DEFAULT_AGE = 18;
	static const int DEFAULT_RATING = 5;

	static const int MINIMUM_AGE = 18;
	static const int MINIMUM_RATING = 1;
	static const int MAXIMUM_RATING = 5;

	Date getDate() const;
	void setDate(Date& date);

	string getName() const;
	void setName(string& name);

	int getAge() const;
	void setAge(int& age);

	int getRating() const;
	void setRating(int& rating);

	MyDate();
	MyDate(string name, Date date, int& age, int& rating);
};
