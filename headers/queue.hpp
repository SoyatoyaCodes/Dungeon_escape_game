#ifndef QUEUE_H
#define QUEUE_H

#include "../headers/enemy.hpp"
#include <stdexcept>

class Queue {
private:
    struct Node {
        Enemy data;  // Store Enemy object directly
        Node* next;

        Node(const Enemy& enemy) : data(enemy), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    ~Queue();

    void enqueue(const Enemy& enemy);
    void dequeue();
    Enemy& peek();
    bool isEmpty() const;
    int getSize() const;
    void clear();
};

#endif 