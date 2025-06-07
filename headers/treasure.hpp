#ifndef TREASURE_H
#define TREASURE_H

#include <string>
using namespace std;
class Treasure {
private:
    string name;

public:
    Treasure(string name);
    string getName() const;
};

#endif