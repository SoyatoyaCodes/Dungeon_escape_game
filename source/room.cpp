#include "../headers/room.hpp"

#include <iostream>

Room::Room(const string& name, const Challenge& challenge, const Treasure& treasure)
    : name(name), challenge(challenge), treasure(treasure), next(nullptr), prev(nullptr) {
}

void Room::addEnemy(const Enemy& enemy) {
    enemies.enqueue(enemy);
    originalEnemies.push_back(enemy);
}

bool Room::hasEnemies() const {
    return !enemies.isEmpty();
}

Enemy& Room::getNextEnemy() {
    if (enemies.isEmpty()) {
        throw std::out_of_range("No enemies left in the room!");
    }
    return enemies.peek();
}

void Room::removeDefeatedEnemy() {
    if (!enemies.isEmpty()) {
        enemies.dequeue();
    }
}

Room* Room::getNext() const {
    return next;
}

Room* Room::getPrev() const {
    return prev;
}

void Room::setNext(Room* nextRoom) {
    next = nextRoom;
}

void Room::setPrev(Room* prevRoom) {
    prev = prevRoom;
}

string Room::getName() const {
    return name;
}

bool Room::triggerRoomEvents(Player& player) {
    cout << "You have entered: " << name << endl;

    // Handle Challenge
    if (!challenge.isSolved()) {
        cout << "**A challenge appears!**" << endl;
        bool correct = challenge.askQuestion();
        if (!correct) {
            cout << "Wrong answer! You lose 1 move!" << endl;
            player.decreaseMoves();
        }
        if (player.getMoves() <= 0) {
            return false;
        }
    }


    while (hasEnemies()) {

        cout << " A " << getNextEnemy().getName() << " attacks!" << endl;
        player.fight(getNextEnemy());
        if (!player.isAlive()) return false;
        removeDefeatedEnemy();
    }


    if (treasure.getName() != "") {
        cout << " You found a treasure: " << treasure.getName() << "!" << endl;
        player.collectTreasure(treasure);
    }
    else {
        cout << " No treasure in this room!" << endl;
    }
    if (player.getMoves() <= 0) {
        return false;
    }
    cout << " Moves remaining: " << player.getMoves() << endl;
    return true;
}


void Room::resetEnemies() {
    enemies.clear();
    for (const Enemy& e : originalEnemies) {
        enemies.enqueue(e);
    }
}