#include "../headers/queue.hpp"

// queue implementation through linked-list
Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(const Enemy& enemy) {
    Node* newNode = new Node(enemy);  // Store Enemy object directly
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty!");
    }

    Node* temp = front;
    front = front->next;

    delete temp;  // Delete the node

    size--;

    // prevent dangling pointer
    if (front == nullptr) {
        rear = nullptr;
    }
}

Enemy& Queue::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty!");
    }
    return front->data;  // Return reference to Enemy object
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

int Queue::getSize() const {
    return size;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

