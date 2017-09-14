#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"

using namespace std;

/* A GradeBook stores all the students, and provides loading/searching/reporting on them */
class GradeBook {
private:
    const static int NUM_STUDENTS = 10;  // number of lines in your data file

    Student students[NUM_STUDENTS];

public:
    const static int MAX_HOMEWORK_SCORE = 25;
    const static int MAX_QUIZ_SCORE = 10;
    const static int MAX_PROJECT_SCORE = 100;
    const static int MAX_MIDTERM_SCORE = 200;
    const static int MAX_MIDTERM2_SCORE = 200;
    const static int MAX_FINAL_SCORE = 200;

    const static int HOMEWORK_WEIGHT = 30;
    const static int QUIZ_WEIGHT = 12;
    const static int PROJECT_WEIGHT = 10;
    const static int MIDTERM_WEIGHT = 15;
    const static int MIDTERM2_WEIGHT = 15;
    const static int FINAL_WEIGHT = 18;


    bool LoadGrades(string fileName);
    int SearchId(int studentId);
    void PrintGradeReport(int studentId);

};
