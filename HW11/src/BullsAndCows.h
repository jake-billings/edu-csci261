/*Author: Luke Peterson
CSCI 261 Section F
Bulls and Cows Header File*/

#include <vector>

class BullsAndCows {
public:
    BullsAndCows();
    void ExplainRules();
    void SetupGameplay();
    void SetDifficulty(int d);
    int GetDifficulty();
    void SetRandomNumber();
    int GetRandomNumber();
    void SetGuess();
    void SplitGuessDigits();
    void SplitRandNumDigits();
    void EvaluateGuess();
    void PresentAward();
    void RunBullsAndCows();

private:
    int guess;
    std::vector<int> guessDigits;
    int difficulty;
    int randNum;
    std::vector<int> randNumDigits;
    int numGuesses;
};