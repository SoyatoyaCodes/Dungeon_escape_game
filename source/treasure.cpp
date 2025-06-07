#include "../headers/treasure.hpp"

Treasure::Treasure(std::string name) : name(name) {}
string Treasure::getName() const {
    return name;
}