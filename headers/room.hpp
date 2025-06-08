#ifndef ROOM_H
#define ROOM_H

#include "enemy.hpp"
#include "challenge.hpp"
#include "treasure.hpp"
#include "player.hpp"
#include "queue.hpp"
#include <string>

using namespace std;

class Room {
private:
    string name;
    Queue enemies;
    vector<Enemy> originalEnemies; //this stores all the enimes in the room
    Challenge challenge;
    Treasure treasure;
    Room* next;
    Room* prev;

public:
    Room(const string& name, const Challenge& challenge, const Treasure& treasure);

    void addEnemy(const Enemy& enemy);
    bool hasEnemies() const;
    Enemy& getNextEnemy();
    void removeDefeatedEnemy(); //removing enimes from room

    Room* getNext() const;
    Room* getPrev() const;
    void setNext(Room* nextRoom);
    void setPrev(Room* prevRoom);

    bool triggerRoomEvents(Player& player);
    string getName() const;
    void resetEnemies();
};

#endif