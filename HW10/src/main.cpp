/* CSCI261 HW10 - Object-Oriented Grade Calculations
 *
 * Description: An object-oriented implementation of a program that
 * generates grade reports for students.
 *
 * YOU SHOULD NOT MODIFY THIS CODE.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "GradeBook.h"

using namespace std;

const string DATA_FILE = "data/grades.csv";

int main() {
    GradeBook grades;
    if (!grades.LoadGrades(DATA_FILE)) {
        cerr << "Could not load grades from " << DATA_FILE << endl;
        return -1;
    }

    // user interface
    int id, index;
    while(true) {
        cout << "Enter the student ID for grade report (-1 quits): ";
        cin >> id;
        if(id == -1)
            break;
        int index = grades.SearchId(id);
        if (index == -1)
            cout << "Couldn't find student" << endl;
        else
            grades.PrintGradeReport(index);
    }

    cout << "Goodbye!" << endl;
    return EXIT_SUCCESS;
}
