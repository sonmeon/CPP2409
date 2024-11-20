#include <iostream>
#include <string>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int x, int y);
void displayMap(int map[][mapX], int magicianX, int magicianY, int warriorX, int warriorY);
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

    Magician magician; // 마법사 객체
    magician.SetHP(20); // HP를 20으로 설정
    Warrior warrior;   // 전사 객체
    warrior.SetHP(20); // HP를 20으로 설정

    int magicianX = 0, magicianY = 0; // 마법사 초기 위치
    int warriorX = 4, warriorY = 4;   // 전사 초기 위치

    bool magicianTurn = true; // 첫 번째 턴은 마법사부터 시작

    while (true) {
        User& currentUser = magicianTurn ? static_cast<User&>(magician) : static_cast<User&>(warrior);
        int& currentX = magicianTurn ? magicianX : warriorX;
        int& currentY = magicianTurn ? magicianY : warriorY;

        string user_input;
        cout << (magicianTurn ? "[마법사 차례]" : "[전사 차례]") << endl;
        cout << "명령어 입력 (up, down, left, right, map, info, exit) [HP: " << currentUser.GetHP() << "]: ";
        cin >> user_input;

        if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
            adjustPlayerPosition(currentX, currentY, user_input);

            if (!checkXY(currentX, currentY)) {
                cout << "맵을 벗어났습니다. 이전 위치로 돌아갑니다." << endl;
                revertToPreviousPosition(currentX, currentY, user_input);
            } else {
                cout << user_input << "로 이동합니다." << endl;
                currentUser.DecreaseHP(1); // 이동 시 HP 1 감소
                displayMap(map, magicianX, magicianY, warriorX, warriorY);
            }
        } else if (user_input == "map") {
            displayMap(map, magicianX, magicianY, warriorX, warriorY);
        } else if (user_input == "info") {
            cout << currentUser << endl; // 현재 사용자 정보 출력
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // HP 체크
        if (currentUser.GetHP() <= 0) {
            cout << (magicianTurn ? "마법사" : "전사") << "의 HP가 0입니다. 게임 종료." << endl;
            break;
        }

        // 턴 변경
        magicianTurn = !magicianTurn;
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

void displayMap(int map[][mapX], int magicianX, int magicianY, int warriorX, int warriorY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == magicianY && j == magicianX && i == warriorY && j == warriorX) {
                // 마법사와 전사가 같은 위치에 있을 경우
                cout << " Both     |";
            } else if (i == magicianY && j == magicianX) {
                // 마법사 위치
                cout << " Magician |";
            } else if (i == warriorY && j == warriorX) {
                // 전사 위치
                cout << " Warrior  |";
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
