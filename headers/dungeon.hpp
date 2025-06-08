#ifndef DUNGEON_H
#define DUNGEON_H

#include "room.hpp"
#include "player.hpp"
#include "stack.hpp"

//keeps track of current room you are in plus backtrack
class Dungeon {
private:
    Room* head;
    Room* tail;
    Room* currentRoom;
    Stack roomStack; // Stack for backtracking
    bool escaped = false;


public:
    Dungeon();
    ~Dungeon();

    void addRoom(Room* newRoom);
    void move(Player& player, bool forward);
    void displayCurrentRoom() const;
    bool isEscaped() const;
    Room* getCurrentRoom() const;
    Stack& getRoomStack();
    void setEscaped(bool status);
};

#endif