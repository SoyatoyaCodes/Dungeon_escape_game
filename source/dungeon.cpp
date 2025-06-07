#include "../headers/dungeon.hpp"
#include <iostream>

using namespace std;

Dungeon::Dungeon() : head(nullptr), tail(nullptr), currentRoom(nullptr) {}


Dungeon::~Dungeon() {
    Room* temp = head;
    while (temp) {
        Room* nextRoom = temp->getNext();
        delete temp;
        temp = nextRoom;
    }
}

void Dungeon::addRoom(Room* newRoom) {
    if (!head) {
        head = tail = newRoom;
    }
    else {

        tail->setNext(newRoom);
        newRoom->setPrev(tail);
        tail = newRoom;
    }

    if (!currentRoom) {
        currentRoom = head;
    }
}

void Dungeon::move(Player& player, bool forward) {
    if (!currentRoom) {
        cout << "There are no rooms in the dungeon!" << endl;
        return;
    }

    if (forward) {

        if (currentRoom->getNext()) {
            roomStack.push(currentRoom);
            currentRoom = currentRoom->getNext();
            player.decreaseMoves();

            cout << "You move forward to: " << currentRoom->getName() << endl;
            currentRoom->resetEnemies();

            if (!currentRoom->triggerRoomEvents(player)) {
                cout << "You failed the challenge! Moves reduced." << endl;
            }
        }
        else {
            cout << "There are no more rooms ahead!" << endl;
            currentRoom == tail;
        }
    }
    else {
        if (!roomStack.isEmpty()) {
            currentRoom = roomStack.top();
            roomStack.pop();
            player.decreaseMoves();

            cout << "You move back to: " << currentRoom->getName() << endl;

            currentRoom->resetEnemies();

            if (!currentRoom->triggerRoomEvents(player)) {
                cout << "You failed the challenge! Moves reduced." << endl;
            }
        }
        else {
            cout << "You can't go back any further!" << endl;
        }
    }
}


void Dungeon::displayCurrentRoom() const {
    if (currentRoom) {
        cout << " Current Room: " << currentRoom->getName() << endl;
    }
    else {
        cout << "Dungeon is empty!" << endl;
    }
}

bool Dungeon::isEscaped() const {
    return currentRoom == tail;
}

Room* Dungeon::getCurrentRoom() const {
    return currentRoom;
}
Stack& Dungeon::getRoomStack() {
    return roomStack;
}