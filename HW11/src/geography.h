/* CSCI 261 HW11: Class Fun
*
* Author: Jake Albers, Section B
*
* Header file for the Geography Trivia Class
*/

#include <iostream>
#include <string>
using namespace std;

class Geography{
private:
	string question;
	string answer;
	string prize;
    string wrong;
	

public:
	Geography();
	bool CheckAnswer(const string);
	void GetQuestion();
	string GetPrize();
    string WrongAnswer();
	void Introduction();
    
};