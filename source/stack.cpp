#include "../headers/stack.hpp"


Stack::Stack() : topNode(nullptr) {}

Stack::~Stack() {
    clear();
}

void Stack::push(Room* room) {
    Node* newNode = new Node(room);
    newNode->next = topNode;
    topNode = newNode;
}

void Stack::pop() {

    if (topNode) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}

Room* Stack::top() const {
    return (topNode) ? topNode->room : nullptr;
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}