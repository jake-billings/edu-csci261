#include "MyDate.h"
#include "Date.h"
#include <string>

using namespace std;

Date MyDate::getDate() const {
	return date;
}
void MyDate::setDate(Date& date) {
	this->date = date;
}

string MyDate::getName() const {
	return name;
}
void MyDate::setName(string& name) {
	this->name = name;
}

int MyDate::getAge() const {
	return age;
}
void MyDate::setAge(int& age) {
	if (age < MINIMUM_AGE) {
		this->age = DEFAULT_AGE;
	} else {
		this->age = age;
	}
}

int MyDate::getRating() const {
	return rating;
}

void MyDate::setRating(int& rating) {
	if (rating < MINIMUM_RATING || rating > MAXIMUM_RATING) {
		this->rating = DEFAULT_RATING;
	} else {
		this->rating = rating;
	}
}

MyDate::MyDate(string name, Date date, int& age, int& rating) {
	setName(name);
	setDate(date);
	setAge(age);
	setRating(rating);
}
