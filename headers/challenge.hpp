#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <iostream>
using namespace std;

class Challenge {
private:
    string question;
    string answer;
    bool solved;

public:
    Challenge(string q, string a);
    bool askQuestion();
    bool isSolved() const;
};

#endif 