/* CSCI 261 HW 06: Reading and Writing Data Files
 *
 * Author: Jake Billings
 * 01/30/2015
 * CSCI261
 */
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
	//Open data file
	ifstream data("input1.txt");

	if ( data.fail() ) {
		cerr << "Error opening input file";
		exit(1);
	}

	//Read initial data to begin loop
	string buf;
	data >> buf;

	string firstName,lastName; //The first and last name of the current student
	double averageGrade = 0; //The average grade of a student
	double sumGrade = 0; //The sum of the score in each of the student's classes
	double countGrades = 0; //The number of classes a student is taking

	int enrollments = 0; //The number of times a student is enrolled in a class
	int graduateEnrollments = 0; //The number of graduate level enrollments

	const int NUMBER_OF_CLASSES=7; //The number of classes offered by Mines CS
	const string CLASS_NAMES[NUMBER_OF_CLASSES] = {
			"CSCI-261: Programming Concepts (C++)",
			"CSCI-262: Data Structures",
			"CSCI-306: Software Engineering",
			"CSCI-442: Operating Systems",
			"CSCI-562: Applied Algorithms & Data Structures",
			"CSCI-565: Distributed Computing Systems",
			"CSCI-580: Advanced High Performance Computing"}; //The names of classes offered at Mines CS
	int classCount[NUMBER_OF_CLASSES]; //The number of students taking each CS class

	while ( !data.eof() ) {
		//If we encounter a name, we are reading a new student
		if (buf=="Name:") {
			//Read new name
			data >> firstName;
			data >> lastName;

			//Reset grade calculations
			sumGrade=0;
			countGrades=0;
		}

		//Check if we are reading a grade
		if (buf.find("CSCI")!=-1) {
			//Record grade for average calculation later
			double grade;
			data >> grade;
			sumGrade+=grade;
			countGrades++;

			//For each offered class, check if this class is the offered class
			//and increment the number of students in that class if it is
			for (int i=0;i<sizeof(classCount);i++) {
				if (CLASS_NAMES[i].find(buf)!=-1) {
					classCount[i]++;
				}
			}

			enrollments++;
			if (buf.substr(5,1)=="5") graduateEnrollments++;
			//cout<<buf<<" "<<grade<<" "<<countGrades<<endl;
		}

		//Record new data
		data >> buf;

		//If the data is a name, we will be reading a new student,
		//so print the data of the old student
		if (buf=="Name:") {
			//Calculate average grade
			averageGrade=sumGrade/static_cast<double>(countGrades);

			//Calculate letter grade
			char letterGrade = 'F';
			if (averageGrade>=90) {
				letterGrade = 'A';
			} else if (averageGrade>=80) {
				letterGrade = 'B';
			} else if (averageGrade>=70) {
				letterGrade = 'C';
			} else if (averageGrade>=60) {
				letterGrade = 'D';
			}

			//Output student info
			cout << lastName << ", " << firstName << endl;
			cout << "Average Score: " << averageGrade << endl;
			cout << "Grade: " << letterGrade << endl;
			cout << endl;
		}
	}

	//Output graduate level information
	cout << "There are " << enrollments-graduateEnrollments << " instances of student taking undergraduate level courses." << endl;
	cout << "There are " << graduateEnrollments << " instances of students taking graduate level courses." << endl;
	cout << endl;

	//Output class enrollment numbers
	for (int i=0;i<NUMBER_OF_CLASSES;i++) {
		cout << CLASS_NAMES[i] << " has " << classCount[i] << " students." << endl;
	}

	return 0;

}
