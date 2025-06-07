#ifndef STACK_H
#define STACK_H

#include "room.hpp"

class Stack {
private:
    struct Node {
        Room* room;
        Node* next;
        Node(Room* r) : room(r), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack();
    ~Stack();

    void push(Room* room);
    void pop();
    Room* top() const;
    bool isEmpty() const;
    void clear();
};

#endif