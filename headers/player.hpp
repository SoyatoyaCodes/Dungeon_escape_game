#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "treasure.hpp"
#include "enemy.hpp"

using namespace std;

class Player {
private:
    string name;
    int health;
    int moves;
    vector<Treasure> inventory;

public:
    Player(string name, int health = 100, int moves = 10);

    void fight(Enemy& enemy);
    void takeDamage(int damage);
    bool isAlive() const;
    string getname() const;
    void collectTreasure(const Treasure& treasure);
    void showInventory() const;
    bool hasItem(const std::string& itemName) const;
    void removeItem(const std::string& itemName) ;
    void heal(int amount) ;
    int getHealth() const;
    int getMoves() const;
    void decreaseMoves();
    void waitforenter();
};

#endif


   