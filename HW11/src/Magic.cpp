/* CSCI-261 HW 11: Class fun
*  Author: Steven Clark Section B
*  Implementation of magic class
*/

#include "Magic.h"

MagicThing::MagicThing(){
    songLineOne = "Oh baby you, you got what I (????)";
    answerOne = "need";
    songLineTwo = "When I find myself in times of trouble, Mother Mary comes to me, speaking words of (????), let it be.";
    answerTwo = "wisdom";
    prize = "A pat on the back!";
    Introduction();
}

void MagicThing::Introduction(){
    cout << "Welcome! I am a Magic Thing from the land of Something Else!" << endl;
    cout << "I'll give you the best prize you've ever received if you can fill in the missing";
    cout << " words to two popular songs!" << endl;
    cout << "(Enter your answers all lower case, filling in the (????).)" << endl;
    return;
}

string MagicThing::GetSongLineOne(){
    return songLineOne;
}

string MagicThing::GetSongLineTwo(){
    return songLineTwo;
}

string MagicThing::GetPrize(){
    return prize;
}

bool MagicThing::CheckAnswerOne(const string &guessOne){
    return guessOne == answerOne;
}

bool MagicThing::CheckAnswerTwo(const string &guessTwo){
    return guessTwo == answerTwo;
}