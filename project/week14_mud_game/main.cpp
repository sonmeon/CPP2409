#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "user.h"

using namespace std;

const int mapX = 5; // Map width
const int mapY = 5; // Map height

// Function declarations
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, GameUser& user, int user_x, int user_y);
vector<vector<int>> loadMap(const string& filename);

int main() {
    vector<vector<int>> map;
    try {
        map = loadMap("map.txt");  // Load the map from "map.txt"
    } catch (const exception& e) {
        cerr << "Error loading map file: " << e.what() << endl;
        return 1; // Exit the program
    }

    int user_x = 0;
    int user_y = 0;

    GameUser user; // Create a GameUser object

    while (true) {
        string user_input;
        cout << "Enter a command (up, down, left, right, map, quit, info) [HP: " << user.GetHP() << "]: ";
        cin >> user_input;

        if (user_input == "up") {
            user_y--;
        } else if (user_input == "down") {
            user_y++;
        } else if (user_input == "left") {
            user_x--;
        } else if (user_input == "right") {
            user_x++;
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
            continue;
        } else if (user_input == "info") {
            cout << user << endl; // Display user info
            continue;
        } else if (user_input == "quit") {
            cout << "Ending the game." << endl;
            break;
        } else {
            cout << "Invalid input." << endl;
            continue;
        }

        // Check if the position is valid
        if (!checkXY(user_x, mapX, user_y, mapY)) {
            cout << "You have gone out of bounds. Returning to previous position." << endl;
            if (user_input == "up") user_y++;
            else if (user_input == "down") user_y--;
            else if (user_input == "left") user_x++;
            else if (user_input == "right") user_x--;
        } else {
            cout << "Moved " << user_input << "." << endl;
            user.DecreaseHP(1); // Decrease HP on move
            checkState(map, user, user_x, user_y); // Check the state of the position
            displayMap(map, user_x, user_y);
        }

        // End the game if HP is 0 or less
        if (user.GetHP() <= 0) {
            cout << "You have run out of HP. Game Over!" << endl;
            break;
        }

        // Check if the goal is reached
        if (checkGoal(map, user_x, user_y)) {
            cout << "You have reached the goal! Congratulations!" << endl;
            cout << "Ending the game." << endl;
            break;
        }
    }

    return 0;
}

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int y = 0; y < map.size(); ++y) {
        for (int x = 0; x < map[y].size(); ++x) {
            if (x == user_x && y == user_y) {
                cout << " Player   |"; // Display player position
            } else {
                int posState = map[y][x];
                switch (posState) {
                    case 0: cout << "          |"; break; // Empty space
                    case 1: cout << " Item     |"; break; // Item
                    case 2: cout << " Enemy    |"; break; // Enemy
                    case 3: cout << " Potion   |"; break; // Potion
                    case 4: cout << " Goal     |"; break; // Goal
                    case 5: cout << " Weapon   |"; break; // Weapon
                    case 6: cout << " Armor    |"; break; // Armor
                }
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------" << endl;
    }
}

bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4; // 4 is the goal
}

void checkState(vector<vector<int>>& map, GameUser& user, int user_x, int user_y) {
    if (map[user_y][user_x] == 1) { // 1 is an item
        cout << "You have collected an item!" << endl;
        user.AddItem();
        map[user_y][user_x] = 0; // Remove the item
    } else if (map[user_y][user_x] == 2) { // 2 is an enemy
        cout << "You encountered an enemy!" << endl;
        user.DecreaseHP(10); // Decrease HP when encountering an enemy
    } else if (map[user_y][user_x] == 3) { // 3 is a potion
        cout << "You have collected a potion!" << endl;
        user.DecreaseHP(-5); // Heal HP with a potion
    }
}

vector<vector<int>> loadMap(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open map file.");
    }

    vector<vector<int>> map(mapY, vector<int>(mapX, 0));
    for (int y = 0; y < mapY; ++y) {
        for (int x = 0; x < mapX; ++x) {
            file >> map[y][x];
        }
    }

    return map;
}
