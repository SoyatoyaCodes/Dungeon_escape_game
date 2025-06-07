#include "../headers/player.hpp"
#include <limits> 

#include <iostream>

using namespace std;

void Player::waitforenter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


Player::Player(string name, int health, int moves)
    : name(name), health(health), moves(moves) {
}

int Player::getHealth() const { return health; }
int Player::getMoves() const { return moves; }
bool Player::isAlive() const { return health > 0; }

void Player::decreaseMoves() {
    if (moves > 0) {
        moves--;
    }
}

bool Player::hasItem(const std::string& itemName) const {
    for (const auto& item : inventory) {
        if (item.getName() == itemName) {
            return true;
        }
    }
    return false;
}

void Player::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
}

void Player::removeItem(const std::string& itemName) {
    inventory.erase(
        std::remove_if(inventory.begin(), inventory.end(),
            [&itemName](const Treasure& item) { return item.getName() == itemName; }),
        inventory.end()
    );
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;  // Prevent negative health
}

void Player::collectTreasure(const Treasure& treasure) {
    inventory.push_back(treasure);
    cout << " You collected: " << treasure.getName() << "!\n";
}

void Player::showInventory() const {
    if (inventory.empty()) {
        cout << " Inventory is empty.\n";
    }
    else {
        cout << " Inventory: ";
        for (const auto& item : inventory) {
            cout << item.getName() << " ";
        }
        cout << "\n";
    }
}


void Player::fight(Enemy& enemy) {
    int blockCount = 0;  // Track blocks to limit defense

    while (isAlive() && enemy.isAlive()) {
        cin.clear();
        cout << "\nChoose your action: \n(1) Block  |  (2) Attack  |  (3) Make a Deal\n";
        showInventory();
        int action;
        cin >> action;

        switch (action) {
        case 1: {  // Block
            cout << " You block the attack!\n";
            int damage = enemy.getAttackPower();
            int reducedDamage = damage / 2;
            takeDamage(reducedDamage);
            cout << "You take " << reducedDamage << " damage.  Health: " << getHealth() << "\n";

            blockCount++;
            if (blockCount >= 3) {
                cout << enemy.getName() << " grows tired of your defenses and leaves!\n";
                waitforenter();
                return;
            }
            waitforenter();
            break;
        }

        case 2: {  // Attack
            if (inventory.empty()) {
                cout << " You have no weapons! The enemy attacks twice!\n";

                for (int i = 0; i < 2 && isAlive(); i++) {
                    cout << enemy.getName() << " attacks!\n";
                    takeDamage(enemy.getAttackPower());
                    cout << "You take " << enemy.getAttackPower() << " damage.  Health: " << getHealth() << "\n";

                    if (!isAlive()) {
                        cout << " You have been defeated!\n";
                        waitforenter();
                        return;
                    }
                }

                cout << enemy.getName() << " loses interest and leaves.\n";
                waitforenter();
                return;
            }

            cout << " Choose a weapon to attack with:\n";
            for (size_t i = 0; i < inventory.size(); ++i) {
                cout << i + 1 << ": " << inventory[i].getName() << "\n";
            }
            cout << "Enter the number of your weapon: ";
            int weaponIndex;
            cin >> weaponIndex;

            if (weaponIndex < 1 || weaponIndex > inventory.size()) {
                cout << " Invalid choice!\n";
                waitforenter();
            }
            else {
                Treasure weapon = inventory.at(weaponIndex - 1);
                cout << " You attack with " << weapon.getName() << "!\n";
                enemy.takeDamage(enemy.getHealth());
                inventory.erase(inventory.begin() + (weaponIndex - 1));  // Remove weapon
                cout << " You defeated the " << enemy.getName() << "!\n";
                waitforenter();
                return;
            }
            break;
        }

        case 3: {  // Make a Deal
            if (inventory.empty()) {
                cout << " You have no items to offer! The enemy attacks twice!\n";

                for (int i = 0; i < 2 && isAlive(); i++) {
                    cout << enemy.getName() << " attacks!\n";
                    takeDamage(enemy.getAttackPower());
                    cout << "You take " << enemy.getAttackPower() << " damage.  Health: " << getHealth() << "\n";

                    if (!isAlive()) {
                        cout << " You have been defeated!\n";
                        waitforenter();
                        return;
                    }
                }

                cout << enemy.getName() << " grows bored and leaves.\n";
                waitforenter();
                return;
            }

            cout << " Choose an item to offer:\n";
            for (size_t i = 0; i < inventory.size(); ++i) {
                cout << i + 1 << ": " << inventory[i].getName() << "\n";
            }
            cout << "Enter the number of the item: ";
            int itemIndex;
            cin >> itemIndex;

            if (itemIndex < 1 || itemIndex > inventory.size()) {
                cout << " Invalid choice!\n";
                waitforenter();
            }
            else {
                Treasure item = inventory.at(itemIndex - 1);
                cout << " You offer " << item.getName() << " to " << enemy.getName() << ".\n";
                inventory.erase(inventory.begin() + (itemIndex - 1));
                cout << " The " << enemy.getName() << " accepts your gift and lets you go!\n";
                waitforenter();
                return;
            }
            break;
        }

        default:
            cout << " Invalid action. Choose again.\n";
            waitforenter();
            break;
        }
    }
}
