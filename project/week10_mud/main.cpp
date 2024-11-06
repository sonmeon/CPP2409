#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int user_y);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user);
void adjustPlayerPosition(int& x, int& y, const string& direction);
void revertToPreviousPosition(int& x, int& y, const string& direction);
bool CheckUser(const User& user);

int main() {
    vector<vector<int>> map = { 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 5, 0},
        {0, 0, 0, 6, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 5, 0, 2} 
    };

    User user; // User 객체 생성
    int user_x = 0;
    int user_y = 0;

    while (true) {
        string user_input;
        cout << "Enter command (up, down, left, right, map, exit) [HP: " << user.GetHP() << "]: ";
        cin >> user_input;

        if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
            adjustPlayerPosition(user_x, user_y, user_input);

            if (!checkXY(user_x, user_y)) {
                cout << "Out of bounds. Returning to previous position." << endl;
                revertToPreviousPosition(user_x, user_y, user_input);
            } else {
                cout << "Moving " << user_input << "." << endl;
                user.DecreaseHP(1); // 이동 시 HP 1 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "exit") {
            cout << "Exiting the game." << endl;
            break;
        } else {
            cout << "Invalid input." << endl;
            continue;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "You've reached the goal! Congratulations!" << endl;
            break;
        }

        if (!CheckUser(user)) {
            cout << "HP is 0. You have failed. Exiting the game." << endl;
            break;
        }
    }

    return 0;
}

void adjustPlayerPosition(int& x, int& y, const string& direction) {
    if (direction == "up") y -= 1;
    else if (direction == "down") y += 1;
    else if (direction == "left") x -= 1;
    else if (direction == "right") x += 1;
}

void revertToPreviousPosition(int& x, int& y, const string& direction) {
    if (direction == "up") y += 1;
    else if (direction == "down") y -= 1;
    else if (direction == "left") x += 1;
    else if (direction == "right") x -= 1;
}

void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                int posState = map[i][j];
                switch (posState) {
                case 0: cout << "      |"; break;
                case 1: cout << "Item  |"; break;
                case 2: cout << "Enemy |"; break;
                case 3: cout << "Potion|"; break;
                case 4: cout << "Goal  |"; break;
                case 5: cout << "Weapon|"; break;
                case 6: cout << "Armor |"; break;
                }
            }
        }
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

bool checkXY(int user_x, int user_y) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user) {
    switch (map[user_y][user_x]) {
    case 1:
        cout << "There is an item here." << endl;
        break;
    case 2:
        user.DecreaseHP(2);
        cout << "Encountered an enemy! HP decreased by 2." << endl;
        break;
    case 3:
        user.IncreaseHP(2);
        cout << "Found a potion, HP increased by 2." << endl;
        break;
    case 5:
        cout << "You found a weapon!" << endl;
        map[user_y][user_x] = 0;
        break;
    case 6:
        cout << "You found armor!" << endl;
        map[user_y][user_x] = 0;
        break;
    }
}

bool CheckUser(const User& user) {
    return user.GetHP() > 0;
}
