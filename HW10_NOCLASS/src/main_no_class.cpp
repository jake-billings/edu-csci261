/* CSCI261 HW10 - Example with NO classes
*
* Description: a procedural-based implementation of a program that 
* generates grade reports for students. 
*
* YOU SHOULD NOT MODIFY THIS CODE.
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// constants definitions
const string DATA_FILE = "data/grades.csv";
const int NUMBER_STUDENTS = 10;  // number of lines in your data file
const int NUMBER_HOMEWORKS = 10; 
const int NUMBER_QUIZ = 5;
const int NUMBER_GRADES = NUMBER_HOMEWORKS + NUMBER_QUIZ + 4; 
const int MAX_SCORES[6] = { 25, 10, 100, 200, 200, 200 };
const double WEIGHTS[6] = { .3, .12, .1, .15, .15, .18};
const string GRADE_MAP[12] = { "F", "D-", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};

// functions prototypes
void split(string& str, const string& delimiter, string& field);
int str2int(const string& str);
bool readGrades(string fileName, int ids[NUMBER_STUDENTS], string names[], 
    int grades[NUMBER_STUDENTS][NUMBER_GRADES], int numberStudents, int numberGrades); 
int searchId(int id, const int ids[NUMBER_STUDENTS], int numberStudents);
void gradeReport(int id, string name, const int grades[NUMBER_GRADES], 
    const int maxScores[6], const double weights[6], int numberHomeworks, int numberQuiz);
string gradeLetter(double finalGrade);

// the main function
int main()
{
	cout<<"No class"<<endl;
    // students arrays
    string names[NUMBER_STUDENTS];
    int ids[NUMBER_STUDENTS];
    int grades[NUMBER_STUDENTS][NUMBER_GRADES];

    // read data into the students arrays
    bool dataRead; 
    dataRead = readGrades(DATA_FILE, ids, names, grades, NUMBER_STUDENTS, NUMBER_GRADES);
    if (!dataRead)
    {
    	cout << "Error in reading file!!" << endl;
    	exit(1); 
    }

    // user interface
    int id, index;
    while(true)
    {
        cout << "Enter the student ID for grade report (-1 quits): ";
        cin >> id;
        if(id == -1)
            break;
        index = searchId(id, ids, NUMBER_STUDENTS);
        if(index == -1)
            cout << "Couldn't find student!" << endl;
        else // print grade report 
            gradeReport(ids[index], names[index], grades[index], MAX_SCORES, 
            		WEIGHTS, NUMBER_HOMEWORKS, NUMBER_QUIZ);
    }

    cout << "Goodbye!" << endl;
    return EXIT_SUCCESS;
}

/* this function computes the first substring field from a string 
   based on a provided delimiter; it also erases the field found from 
   the original string. */
void split(string& str, const string& delimiter, string& field)
{
    short pos = str.find(delimiter);
    if(pos == string::npos)        
        field = str;
    else
    {
        field = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
}

/* this function returns an integer of the string passed as an argument. */
int str2int(const string& str)
{
    int anInt;
    stringstream ss;
    ss << str;
    ss >> anInt;
    return anInt;    
}

/* this function reads data from the file (filename passed as am 
	argument) into the students' arrays */
bool readGrades(string fileName, int ids[NUMBER_STUDENTS], string names[], 
	int grades[NUMBER_STUDENTS][NUMBER_GRADES], int numberStudents, int numberGrades)
{
    ifstream dataFile(fileName);
    if(!dataFile)
    	return false; 
    string line, field;
    for(int i = 0; i < numberStudents && !dataFile.eof(); i++)
    {
        getline(dataFile, line);
        // id
        split(line, ",", field);    // get string ID in line (data until 1st comma) 
        ids[i] = str2int(field);    // translate ID (as a string) to ID (as an int)
        // name
        split(line, ",", field);    // get name in line (data until next comma) 
        names[i] = field;           
        // grades
        for(int j = 0; j < numberGrades; j++)
        {
            split(line, ",", field);   // get next grade (data until next comma) 
            grades[i][j] = str2int(field);  // grade (as string) to grade (as int)
        }
    }
    dataFile.close();
    return true;
}

/* this function searches for the student id in the array (passed as argument) 
	and returns the correspondent index (if found) or -1 (if NOT found) */
int searchId(int id, const int ids[NUMBER_STUDENTS], int numberStudents)
{
    for(int i = 0; i < numberStudents; i++)
        if(ids[i] == id)
            return i;
    return -1;    
}

/* this function prints a student's grade report */
void gradeReport(int id, string name, const int grades[NUMBER_GRADES], 
    const int maxScores[6], const double weights[6], int numberHomeworks, int numberQuiz)
{
    cout << "Grade Report for " << id << " - " << name << endl;

    cout << "Homeworks = { ";
    int sumHwk = 0;
    for(int i = 0; i < numberHomeworks; i++)
    {
        cout << grades[i] << " ";
        sumHwk += grades[i];
    }
    cout << "} = " << sumHwk << endl;

    cout << "Quiz = { ";
    int sumQuiz = 0;
    for(int i = numberHomeworks; i < numberHomeworks + numberQuiz; i++)
    {
        cout << grades[i] << " ";
        sumQuiz += grades[i];
    }
    cout << "} = " << sumQuiz << endl;

    cout << "Final project = { " << grades[15] << " }" <<endl;

    cout << "Midterms: { " << grades[16] << " " << grades[17] << " }" << endl;

    cout << "Final exam = { " << grades[18] << " }" << endl;

    cout << "Final grade = " << endl;
    cout << '\t' << (double)sumHwk << " / " << (numberHomeworks * maxScores[0]) 
    	<< " * " << (weights[0] * 100) << " + " << endl;
    cout << '\t' << (double)sumQuiz << " / " << (numberQuiz * maxScores[1]) 
    	<< " * " << (weights[1] * 100) << " + " << endl;
    cout << '\t' << (double)grades[15] << " / " << maxScores[2] << " * " 
    	<< (weights[2] * 100) << " + " << endl;
    cout << '\t' << (double)grades[16] << " / " << maxScores[3] << " * " 
    	<< (weights[3] * 100) << " + " << endl;
    cout << '\t' << (double)grades[17] << " / " << maxScores[4] << " * " 
    	<< (weights[4] * 100) << " + " << endl;
    cout << '\t' << (double)grades[18] << " / " << maxScores[5] << " * " 
    	<< (weights[5] * 100) << " = ";
    double finalGrade = 
        (double)sumHwk / (numberHomeworks * maxScores[0]) * weights[0] * 100 +
        (double)sumQuiz / (numberQuiz * maxScores[1]) * weights[1] * 100 + 
        (double)grades[15] / maxScores[2] * weights[2] * 100 +
        (double)grades[16] / maxScores[3] * weights[3] * 100 + 
        (double)grades[17] / maxScores[4] * weights[4] * 100 +
        (double)grades[18] / maxScores[5] * weights[5] * 100;
    cout << finalGrade << endl;
    cout << "Letter grade: " << gradeLetter(finalGrade) << endl << endl;
}

/* this function returns a grade letter from the final grade (passed as argument) */
string gradeLetter(double finalGrade)
{
    if(finalGrade < 60)
        return GRADE_MAP[0];
    else
        return GRADE_MAP[(int)((finalGrade - 60) / 10. * 3) + 1];
}
