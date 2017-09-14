/* CSCI-261 HW 11: Class fun
*  Author: Steven Clark Section B
*  Header file for magic class
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class MagicThing{
    private:
        string songLineOne, songLineTwo;
        string answerOne, answerTwo;
        string prize;
        void Introduction();

    public:
        MagicThing();
        string GetSongLineOne();
        string GetSongLineTwo();
        string GetPrize();
        bool CheckAnswerOne(const string&);
        bool CheckAnswerTwo(const string&);
};