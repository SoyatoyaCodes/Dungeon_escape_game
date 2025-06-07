#include "../headers/enemy.hpp"
using namespace std;

Enemy::Enemy(std::string name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower), attackCount(0) {
}

string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getAttackPower() const { return attackPower; }
bool Enemy::isAlive() const { return health > 0; }

void Enemy::takeDamage(int damage) { health -= damage; }

bool Enemy::canAttack() const { return attackCount < 2; }