//============================================================================
// Name        : Lab12B
// Author      : Jake Billings
//============================================================================

#include "MyDate.h"
#include "Date.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void PrintDate(const MyDate& date);

int main() {
	vector<MyDate> dates;

	ifstream data("dates.txt");

	//Exit gracefully on IO error
	if ( data.fail() ) {
		cerr << "Error opening input file";
		return false;
	}

	while (!data.eof()) {

		string name;
		string dateOfDateStr;
		int age;
		int rating;

		string junk;
		data >> junk;

		data >> dateOfDateStr;

		data >> junk;
		data >> name;

		data >> junk;
		data >> age;

		data >> junk;
		data >> rating;

		data.ignore(256,'D');

		Date dateOfDate(stoi(dateOfDateStr.substr(dateOfDateStr.find("/")+1,dateOfDateStr.rfind("/")-2)),
				stoi(dateOfDateStr.substr(0,dateOfDateStr.find("/"))),
				stoi(dateOfDateStr.substr(dateOfDateStr.rfind("/")+1)));

		MyDate date(name,dateOfDate,age,rating);


		dates.push_back(date);
	}

	for (int i=0; i<dates.size(); i++) {
		PrintDate(dates.at(i));
	}
}

void PrintDate(const MyDate& date) {
	cout << "Date:\t" << date.getDate().toString() << endl;
	cout << "Name:\t" << date.getName() << endl;
	cout << "Age:\t" << date.getAge() << endl;
	cout << "Rating:\t" << date.getRating() << endl;
}
