#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;
    int attackCount; // Track attacks

public:
    Enemy(std::string name, int health, int attackPower);

    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;
    bool isAlive() const;
    void takeDamage(int damage);
    bool canAttack() const;
};

#endif