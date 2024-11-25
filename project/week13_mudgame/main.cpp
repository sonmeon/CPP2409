#include <iostream>
#include <string>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int x, int y);
void displayMap(int map[][mapX], int playerX, int playerY);
void adjustPlayerPosition(int& x, int& y, const string& direction);
void revertToPreviousPosition(int& x, int& y, const string& direction);

int main() {
    int map[mapY][mapX] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 5, 0},
        {0, 0, 0, 6, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 5, 0, 2}
    };

    // 직업 선택 (영어로 변경)
    cout << "Select your class (Magician or Warrior): ";
    string choice;
    cin >> choice;

    User* player = nullptr;

    // 직업 선택에 따라 객체 생성
    if (choice == "Magician") {
        player = new Magician(); // 마법사 객체 생성
    } else if (choice == "Warrior") {
        player = new Warrior(); // 전사 객체 생성
    } else {
        cout << "Invalid choice. Please select either 'Magician' or 'Warrior'." << endl;
        return 1;
    }

    player->SetHP(20); // HP 설정

    int playerX = 0, playerY = 0; // 플레이어 초기 위치

    while (true) {
        string user_input;
        cout << "[Current turn: Player]" << endl;
        cout << "Enter command (up, down, left, right, map, info, exit) [HP: " << player->GetHP() << "]: ";
        cin >> user_input;

        if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
            adjustPlayerPosition(playerX, playerY, user_input);

            if (!checkXY(playerX, playerY)) {
                cout << "Out of bounds. Returning to previous position." << endl;
                revertToPreviousPosition(playerX, playerY, user_input);
            } else {
                cout << "Moving " << user_input << "." << endl;
                player->DecreaseHP(1); // 이동 시 HP 1 감소
                displayMap(map, playerX, playerY);
            }
        } else if (user_input == "map") {
            displayMap(map, playerX, playerY);
        } else if (user_input == "info") {
            cout << *player << endl; // 현재 사용자 정보 출력
        } else if (user_input == "exit") {
            cout << "Exiting the game." << endl;
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        // HP 체크
        if (player->GetHP() <= 0) {
            cout << "Player's HP is 0. Game over." << endl;
            break;
        }
    }

    delete player; // 동적 할당된 메모리 해제
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

void displayMap(int map[][mapX], int playerX, int playerY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == playerY && j == playerX) {
                // 플레이어 위치
                cout << " Player   |";
            } else {
                // 일반 맵 상태 출력
                int posState = map[i][j];
                switch (posState) {
                case 0: cout << "          |"; break; // 빈칸
                case 1: cout << " Item     |"; break; // 아이템
                case 2: cout << " Enemy    |"; break; // 적
                case 3: cout << " Potion   |"; break; // 포션
                case 4: cout << " Goal     |"; break; // 목표 지점
                case 5: cout << " Weapon   |"; break; // 무기
                case 6: cout << " Armor    |"; break; // 갑옷
                }
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------" << endl;
    }
}

bool checkXY(int x, int y) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}
