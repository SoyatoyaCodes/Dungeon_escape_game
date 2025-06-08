#include "../headers/challenge.hpp"
#include <algorithm>
#include <limits>

Challenge::Challenge(string q, string a) : question(q), answer(a), solved(false) {}

//prompts the question and checks if the answer is correct

bool Challenge::askQuestion() {

    cout << question << endl;
    string userAnswer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userAnswer);
    transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (userAnswer == answer) {
        solved = true;
        cout << "Correct!" << endl;
        return true;
    }
    else {
        cout << "Wrong!" << endl;
        return false;
    }
}

bool Challenge::isSolved() const { return solved; }