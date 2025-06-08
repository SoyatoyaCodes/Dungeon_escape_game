#include "../headers/dungeon.hpp"
#include "../headers/player.hpp"
#include "../headers/room.hpp"
#include "../headers/challenge.hpp"
#include "../headers/enemy.hpp"
#include "../headers/treasure.hpp"
#include <iostream>
#include <stdexcept>  // for runtime_error
#include <limits>     // for numeric_limits
using namespace std;

//for a clean build
//cd build
//rm -r * or rm -rf *
//to prevent errors if a file does not exist
//cmake ..
//ninja
//./game.exe
//to run : cd build && ninja && 
#include <vector>
#include <cmath>
//NEW SHIT

//FOR THE GRID 
//OLD SHIT
bool isSafe(const vector<pair<int, int>>& queens, int row, int col) {
    for (auto& q : queens) {
        if (q.first == row || q.second == col || abs(q.first - row) == abs(q.second - col))
            return false;
    }
    return true;
}

void displayGrid(const vector<pair<int, int>>& queens, int unsafeRow = -1, int unsafeCol = -1) {
    cout << "\nCurrent Grid:\n";
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            bool isQueen = false;
            for (auto& q : queens) {
                if (q.first == r && q.second == c) {
                    isQueen = true;
                    break;
                }
            }
            if (r == unsafeRow && c == unsafeCol) {
                cout << " X ";
            }
            else if (isQueen) {
                cout << " Q ";
            }
            else {
                cout << " . ";
            }
        }
        cout << endl;
    }
}

// void room2_darkCorridorFootstepPuzzle(Player& player) {
//     cout << "\n You enter the DARK CORRIDOR. Strange tiles glow faintly...\n";
//     cout << " Step on correct tiles only! It's a 4x4 grid, each step must be N-Queen safe!\n";
//     cout << "4 steps to cross safely...\n";

//     vector<pair<int, int>> queens;
//     int steps = 4;


void room2_darkCorridorFootstepPuzzle(Player& player) {
    cout << "\n now..... inside the DARK CORRIDOR..... Strange tiles glow faintly...\n";
    cout << " Step on correct tiles only! It's a 4x4 grid, each step must be N-Queen safe!\n";
    cout << "4 steps to cross safely...\n";

    vector<pair<int, int>> queens;
    int steps = 4;

    while (steps--) {
        displayGrid(queens);

        int row, col;
        cout << "\nPick a tile (row [0-3], col [0-3]): MAKE SURE ITS IN 2 3 FORMAT ";

        try {
            cin >> row >> col;
            if (cin.fail()) {
                cin.clear(); // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
                throw runtime_error("Invalid input format. Please enter two numbers separated by space.");
            }

            if (row < 0 || row >= 4 || col < 0 || col >= 4) {
                cout << " Invalid input! You trip and lose 5 HP.\n";
                player.takeDamage(5);
                continue;
            }

            if (!isSafe(queens, row, col)) {
                cout << " Trap triggered! That's not a safe step. -5 HP.\n";
                player.takeDamage(5);
                displayGrid(queens, row, col); // show X where they messed up
            }
            else {
                cout << " Step safe. You proceed forward.\n";
                queens.push_back({ row, col });
                displayGrid(queens);
            }
        }
        catch (const exception& e) {
            cout << " Error: " << e.what() << " You trip and lose 5 HP.\n";
            player.takeDamage(5);
            continue;
        }

        cout << " Current Health: " << player.getHealth() << "\n";
        if (!player.isAlive()) {
            cout << "\n You collapse from injuries in the corridor...\n";
            return;
        }
    }

    cout << "\n You made it across the dark corridor using your mind!\n";
}

//     while (steps--) {
//         displayGrid(queens);

//         int row, col;
//         cout << "\nPick a tile (row [0-3], col [0-3]): MAKE SURE ITS IN 2 3 FORMAT ";
//         cin >> row >> col;

//         if (row < 0 || row >= 4 || col < 0 || col >= 4) {
//             cout << " Invalid input! You trip and lose 5 HP.\n";
//             player.takeDamage(5);
//             continue;
//         }

//         if (!isSafe(queens, row, col)) {
//             cout << " Trap triggered! That's not a safe step. -5 HP.\n";
//             player.takeDamage(5);
//             displayGrid(queens, row, col); // show X where they messed up
//         }
//         else {
//             cout << " Step safe. You proceed forward.\n";
//             queens.push_back({ row, col });
//             displayGrid(queens);
//         }

//         cout << " Current Health: " << player.getHealth() << "\n";
//         if (!player.isAlive()) {
//             cout << "\n You collapse from injuries in the corridor...\n";
//             return;
//         }
//     }

//     cout << "\n You made it across the dark corridor using your mind!\n";
// }



void showInstructions() {
    string dummy;
    cout << "\n(0o0) PLAYER'S GUIDE ~(0>0)~\n";
    cout << "1 Your goal is to defeat the Dragon in the final room.\n";
    cout << "2 You'll face enemies and collect items along the way.\n";
    cout << "ALSO!! DONT FORGET TO CLICK ENTER TO CONTINUE FURTHER\n";
    cin.ignore();
    getline(cin, dummy);
    cout << " Each room may contain:\n";
    cout << "   - Enemies to fight \n";
    cout << "   - Challenges to solve \n";
    cout << "   - Treasures to collect \n IMPORTANT INFO AHEAD! ->";
    getline(cin, dummy);
    cout << " Moving forward or backward decreases moves.\n";
    getline(cin, dummy);
    cout << " If your health reaches 0 or you run out of moves, you lose.\n";
    getline(cin, dummy);
    cout << " Collect key items to progress (like the room5 key).\n";
    getline(cin, dummy);
    cout << " Defeat all enemies in a room before proceeding.\n";
    getline(cin, dummy);
    cout << " Reach the final room to defeat the Dragon and win! LETS GOOOO!! \n\n";
    getline(cin, dummy);
}

void displayQuatro() {
    cout << "\nQUATRO-OTOPUS:  Hola compi! I'm gonna wipe you off the map!\n";
    cout << "\n   __      \n  /o_)     \n  |         \n  |         \n /|\\         <== Quatro in action\n";
}

void displayQuatroDead() {
    cout << "\nYou destroyed Quatro-Otopus!\n";
}

void displayDragon() {
    cout << "\nDRAGON: You dare challenge me?!\n";
}

void displayDragonDead() {
    cout << "\nYou defeated the DRAGON! \n";
}
bool room3_quatroFight(Player& player) {
    displayQuatro();
    int tentacles = 4;
    string input;
    srand(time(0));

    while (tentacles > 0 && player.isAlive()) {
        int attackType = rand() % 2;
        if (attackType == 0) {
            cout << "\nQuatro hits you with a TENTACLE! You lose 15 health.\n";
            player.takeDamage(15);
        }
        else {
            cout << "\nQuatro tickles you... You lose 5 health.\n";
            player.takeDamage(5);
        }
        cout << "Your current health: " << player.getHealth() << "\n";

        if (!player.isAlive()) {
            cout << "\nYou were defeated by Quatro... Game Over.\n";
            return false;  // player died
        }

        for (int i = 0; i < 2 && tentacles > 0; ++i) {
            cout << "\nPress D to destroy a tentacle: ";
            cin >> input;
            if (input == "D" || input == "d") {
                tentacles--;
                cout << "You destroyed one of Quatro's tentacles! Remaining: " << tentacles << "\n";
            }
        }
    }

    displayQuatroDead();
    player.collectTreasure(Treasure("Quatro Tentacle"));
    return true;  // survived
}


void room4_npcInteraction(Player& player) {
    cout << "\nAn NPC appears! It's Mario!\n";
    cout << "(Mario waves his stick arms)\n";
    cout << "\nMario: Hello! To defeat the dragon, you need a sword and shield.\n";
    cout << "Do you want to collect them? (yes/no): ";
    string input;
    cin >> input;

    if (input == "yes") {
        player.collectTreasure(Treasure("Sword"));
        player.collectTreasure(Treasure("Shield"));
        cout << "\nYou collected a sword and shield!\n";
    }

    player.showInventory();
    player.collectTreasure(Treasure("Key to Room 5"));
    cout << "Mario: Here's a key to Room 5! \n";

    cout << "\nYou find a treasure chest with a scroll: 'Type this spell to receive a potion:'\n";
    cout << "\nSPELL: dragonbegone\n> ";
    cin >> input;

    transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (input == "dragonbegone") {
        player.collectTreasure(Treasure("Magic Potion"));
        cout << "You obtained a magic potion! \n";
    }
}

bool room5_dragonBoss(Player& player) {
    if (!player.hasItem("Key to Room 5")) {
        cout << "You need a key to enter the Dragon's Lair.\n";
        return false;
    }

    displayDragon();
    string input;
    if (player.hasItem("Magic Potion")) {
        cout << "\nUse magic potion to kill the dragon instantly? (yes/no): ";
        cin >> input;
        if (input == "yes") {
            player.removeItem("Magic Potion");
            displayDragonDead();
            cout << "\n Congratulations, you won the game! \n";
            return true;
        }
    }

    int dragonHP = 20;
    while (dragonHP > 0 && player.isAlive()) {
        cout << "\nYour move (attack [A] / shield [S] / potion [P]): ";
        cin >> input;
        if (input == "A" || input == "a") {
            if (player.hasItem("Sword")) {
                dragonHP -= 5;
                cout << "You attacked the dragon! HP left: " << dragonHP << "\n";
            }
            else {
                cout << "You need a sword to attack.\n";
            }
        }
        else if (input == "S" || input == "s") {
            if (player.hasItem("Shield")) {
                cout << "You used your shield to block the attack!\n";
                continue;
            }
            else {
                cout << "You don't have a shield!\n";
            }
        }
        else if (input == "P" || input == "p") {
            if (player.hasItem("Magic Potion")) {
                cout << "You used the magic potion to heal. Health restored to 100.\n";
                player.heal(100 - player.getHealth());
                player.removeItem("Magic Potion");
                continue;
            }
            else {
                cout << "You don't have any potion left.\n";
            }
        }

        cout << "Dragon breathes fire! You lose 5 health.\n";
        player.takeDamage(5);
        cout << "Your current health: " << player.getHealth() << "\n";
    }

    if (!player.isAlive()) {
        cout << "\n You were killed by the dragon... \n";
        return false;
    }
    else {
        displayDragonDead();
        cout << "\n You defeated the dragon and won the game! \n";
        return true;
    }
}



int main() {
    cout << "\n=== Welcome to Soha's dungeon escape game!!\n";
    cout << "Who is this legend daring to escape the dungeon? TELL YOUR NAME: ";
    string name;
    cin >> name;
    Player player(name);
    cout << "Welcome, " << name << "!\n";

    Dungeon dungeon;
    cout << "WELCOME TO THE DRAGON'S LAIR\n";

    showInstructions();
    cout << "LET'S START THE GAME!!\n";

    Room* room1 = new Room("Entrance Hall", Challenge("What has keys but can't open locks?", "piano"), Treasure("Health Potion"));
    Room* room2 = new Room("Dark Corridor", Challenge("The more you take, the more you leave behind. What am I?", "footsteps"), Treasure("Torch"));
    Room* room3 = new Room("Quatro's Lair", Challenge("What has a head, a tail, but no body?", "coin"), Treasure(""));
    Room* room4 = new Room("Treasure Room", Challenge("What gets wet while drying?", "towel"), Treasure(""));
    Room* room5 = new Room("Dragon's Den", Challenge("What can you catch but not throw?", "cold"), Treasure("Dragon's Hoard"));

    // Add enemies
    room1->addEnemy(Enemy("Goblin", 20, 5));
    room2->addEnemy(Enemy("Skeleton", 15, 8));
    room4->addEnemy(Enemy("Guardian", 25, 10));
    // Dragon is handled separately in room5

    // Link rooms
    dungeon.addRoom(room1);
    dungeon.addRoom(room2);
    dungeon.addRoom(room3);
    dungeon.addRoom(room4);
    dungeon.addRoom(room5);

    dungeon.getRoomStack().push(room1);
    room1->triggerRoomEvents(player);

    bool running = true;

    while (running && player.isAlive() && player.getMoves() > 0 && !dungeon.isEscaped()) {
        dungeon.displayCurrentRoom();

        string roomName = dungeon.getCurrentRoom()->getName();

        if (roomName == "Quatro's Lair") {
            if (!room3_quatroFight(player)) {
                cout << "\n Game Over: You were defeated by Quatro.\n";
                break;
            }
            dungeon.move(player, true);
            continue;
        }
        else if (roomName == "Treasure Room") {
            room4_npcInteraction(player);
            dungeon.move(player, true);
            continue;
        }
        else if (roomName == "Dragon's Den") {
            if (!room5_dragonBoss(player)) {
                cout << "\n Game Over: The dragon defeated you.\n";
                break;
            }
            dungeon.setEscaped(true);
            break;
        }
        else if (roomName == "Dark Corridor") {
            room2_darkCorridorFootstepPuzzle(player);
            if (!player.isAlive()) {
                cout << "\n Game Over: You died in the dark corridor.\n";
                break;
            }
            dungeon.move(player, true);
            continue;
        }

        cout << "\nChoose an action:\n";
        cout << "1. Move Forward\n2. Move Backward\n3. Check Inventory\n4. Quit Game\n> ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            dungeon.move(player, true);
            break;
        case 2:
            dungeon.move(player, false);
            break;
        case 3:
            player.showInventory();
            break;
        case 4:
            cout << "Game quit by player.\n";
            running = false;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    // Ending messages
    if (!player.isAlive()) {
        cout << "\n  You have died! Game Over.\n";
    }
    else if (player.getMoves() <= 0) {
        cout << "\n You ran out of moves! Game Over.\n";
    }
    else if (dungeon.isEscaped()) {
        cout << "\n CONGRATULATIONS " << player.getname() << "! You defeated the dragon and escaped the dungeon. YOU WIN!\n";
    }
    else {
        cout << "\n You exited the game or something unexpected happened.\n";
    }

    return 0;
}
