#include "iostream"
#include "string"
#include "GradeBook.h"
#include "Student.h"

using namespace std;

// These constants are used only within this CPP, so we don't need to place them in the header
const string GRADE_MAP[12] = { "F", "D-", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};

/* Convert a grade percentage into the +/- grading scale */
static string GradeLetter(double finalGrade) {
    if(finalGrade < 60)
        return GRADE_MAP[0];
    else
        return GRADE_MAP[(int)((finalGrade - 60) / 10. * 3) + 1];
}

/* Extract a single field from a delimeted format, and remove that field
 * from the input. This can be used to consume CSV fields from a line.
 * The field is erased so that the function can be re-called on the same
 * input variable.
 */
static void Split(string& str, const string& delimiter, string& field) {
    short pos = str.find(delimiter);
    if(pos == string::npos) {
        field = str;
    } else {
        field = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
}

// Given a line from the file, initialize this student
void Student::InitFromLine(string line) {
    string field;
    // id
    Split(line, ",", field);    // get string ID in line (data until 1st comma)
    setId(stoi(field));

    // name
    Split(line, ",", field);    // get name in line (data until next comma)
    setName(field);

    // Extract the grades
    for (int j = 0; j < NUM_HOMEWORKS; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        homeworkGrades[j] = stoi(field);
    }

    for (int j = 0; j < NUM_QUIZZES; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        quizGrades[j] = stoi(field);
    }

    for (int j = 0; j < NUM_PROJECTS; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        projectGrades[j] = stoi(field);
    }

    for (int j = 0; j < NUM_MIDTERMS; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        midtermGrades[j] = stoi(field);
    }

    for (int j = 0; j < NUM_MIDTERM2S; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        midterm2Grades[j] = stoi(field);
    }

    for (int j = 0; j < NUM_FINALS; ++j) {
        Split(line, ",", field);   // get next grade (data until next comma)
        finalGrades[j] = stoi(field);
    }
}

void Student::PrintGrades() {
    cout << "Grade Report for " << id << " - " << name << endl;

    cout << "Homeworks = { ";
    int sumHwk = 0;
    for(int i = 0; i < NUM_HOMEWORKS; i++)
    {
        cout << homeworkGrades[i] << " ";
        sumHwk += homeworkGrades[i];
    }
    cout << "} = " << sumHwk << endl;

    cout << "Quiz = { ";
    int sumQuiz = 0;
    for(int i = 0; i < NUM_QUIZZES; i++)
    {
        cout << quizGrades[i] << " ";
        sumQuiz += quizGrades[i];
    }
    cout << "} = " << sumQuiz << endl;

    cout << "Projects = { ";
    int sumProject = 0;
    for(int i = 0; i < NUM_PROJECTS; i++)
    {
        cout << projectGrades[i] << " ";
        sumProject += projectGrades[i];
    }
    cout << "} = " << sumProject << endl;

    cout << "Midterms = { ";
    int sumMidterm = 0;
    for(int i = 0; i < NUM_MIDTERMS; i++)
    {
        cout << midtermGrades[i] << " ";
        sumMidterm += midtermGrades[i];
    }
    int sumMidterm2 = 0;
    for(int i = 0; i < NUM_MIDTERM2S; i++)
    {
        cout << midterm2Grades[i] << " ";
        sumMidterm2 += midterm2Grades[i];
    }
    cout << "} = " << sumMidterm+sumMidterm2 << endl;

    cout << "Finals = { ";
    int sumFinal = 0;
    for(int i = 0; i < NUM_FINALS; i++)
    {
        cout << finalGrades[i] << " ";
        sumFinal += finalGrades[i];
    }
    cout << "} = " << sumFinal << endl;

    cout << "Final grade = " << endl;
    cout << '\t' << (double)sumHwk << " / " << (NUM_HOMEWORKS * GradeBook::MAX_HOMEWORK_SCORE)
        << " * " << (GradeBook::HOMEWORK_WEIGHT) << " + " << endl;

    cout << '\t' << (double)sumQuiz << " / " << (NUM_QUIZZES * GradeBook::MAX_QUIZ_SCORE)
        << " * " << (GradeBook::QUIZ_WEIGHT) << " + " << endl;

    cout << '\t' << (double)sumProject << " / " << NUM_PROJECTS * GradeBook::MAX_PROJECT_SCORE << " * "
        << (GradeBook::PROJECT_WEIGHT) << " + " << endl;

    cout << '\t' << (double)sumMidterm << " / " << NUM_MIDTERMS * GradeBook::MAX_MIDTERM_SCORE << " * "
        << (GradeBook::MIDTERM_WEIGHT) << " + " << endl;

    cout << '\t' << (double)sumMidterm2 << " / " << NUM_MIDTERM2S * GradeBook::MAX_MIDTERM2_SCORE << " * "
        << (GradeBook::MIDTERM2_WEIGHT) << " + " << endl;

    cout << '\t' << (double)sumFinal << " / " << NUM_FINALS * GradeBook::MAX_FINAL_SCORE << " * "
        << (GradeBook::FINAL_WEIGHT) << " + " << endl;

    double finalGrade = 
        (double)sumHwk / (NUM_HOMEWORKS * GradeBook::MAX_HOMEWORK_SCORE) * GradeBook::HOMEWORK_WEIGHT +
        (double)sumQuiz / (NUM_QUIZZES * GradeBook::MAX_QUIZ_SCORE) * GradeBook::QUIZ_WEIGHT +
        (double)sumProject / (NUM_PROJECTS * GradeBook::MAX_PROJECT_SCORE) * GradeBook::PROJECT_WEIGHT +
        (double)sumMidterm / (NUM_MIDTERMS * GradeBook::MAX_MIDTERM_SCORE) * GradeBook::MIDTERM_WEIGHT +
        (double)sumMidterm2 / (NUM_MIDTERM2S * GradeBook::MAX_MIDTERM2_SCORE) * GradeBook::MIDTERM2_WEIGHT +
        (double)sumFinal / (NUM_FINALS * GradeBook::MAX_FINAL_SCORE) * GradeBook::FINAL_WEIGHT;

    cout << finalGrade << endl;
    cout << "Letter grade: " << GradeLetter(finalGrade) << endl << endl;
}


//Getters and setters generated by Eclipse IDE

const int* Student::getHomeworkGrades() const {
	return homeworkGrades;
}

const string& Student::getName() const {
	return name;
}

void Student::setName(const string& name) {
	this->name = name;
}

const int* Student::getQuizGrades() const {
	return quizGrades;
}

int Student::getId() const {
	return id;
}

const int* Student::getFinalGrades() const {
	return finalGrades;
}

const int* Student::getMidtermGrades() const {
	return midtermGrades;
}

const int* Student::getMidterm2Grades() const {
	return midtermGrades;
}

const int* Student::getProjectGrades() const {
	return projectGrades;
}

void Student::setId(int id) {
	this->id = id;
}
