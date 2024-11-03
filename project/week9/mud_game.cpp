#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int HP = 20;  // 초기 HP 설정

// 주요 함수 선언
bool checkXY(int user_x, int user_y);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);
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

    int user_x = 0; // 유저 초기 x 위치
    int user_y = 0; // 유저 초기 y 위치

    while (true) {
        string user_input;
        // ③ 처음 명령문을 입력 받을 때 마다 HP 함께 출력
        cout << "Enter command (up, down, left, right, map, exit) [HP: " << HP << "]: ";
        cin >> user_input;

        if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
            // ① 상/하/좌/우 입력 시 해당 방향으로 이동
            adjustPlayerPosition(user_x, user_y, user_input);

            // ② 지도 밖으로 나가게 되면 에러 메시지 출력
            if (!checkXY(user_x, user_y)) {
                cout << "Out of bounds. Returning to previous position." << endl;
                revertToPreviousPosition(user_x, user_y, user_input);
            } else {
                cout << "Moving " << user_input << "." << endl;
                HP -= 1; // ② 이동할 때마다 체력 1 감소
                displayMap(map, user_x, user_y); // 지도 출력
                checkState(map, user_x, user_y); // 현재 위치 상태 체크
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y); // ① "지도" 입력 시 전체 지도 출력
        } else if (user_input == "exit") {
            cout << "Exiting the game." << endl;
            break;
        } else {
            // ① 잘못된 입력 시 에러 메시지 출력
            cout << "Invalid input. Please retry" << endl;
            continue;
        }

        // ③ 목적지에 도착하면 "성공" 출력하고 종료
        if (checkGoal(map, user_x, user_y)) {
            cout << "You've reached the goal! Congratulations!" << endl;
            break;
        }

        // ④ HP가 0이 되면 "실패" 출력하고 종료
        if (HP <= 0) {
            cout << "HP is 0. You have failed. Exiting the game." << endl;
            break;
        }
    }

    return 0;
}

// 사용자의 위치를 지정 방향으로 조정하는 함수
void adjustPlayerPosition(int& x, int& y, const string& direction) {
    if (direction == "up") y -= 1;
    else if (direction == "down") y += 1;
    else if (direction == "left") x -= 1;
    else if (direction == "right") x += 1;
}

// 사용자의 위치를 이전 위치로 복구하는 함수
void revertToPreviousPosition(int& x, int& y, const string& direction) {
    if (direction == "up") y += 1;
    else if (direction == "down") y -= 1;
    else if (direction == "left") x += 1;
    else if (direction == "right") x -= 1;
}

// ② 전체 지도와 현재 위치를 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
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

// ③ 지도 밖으로 나가지 않도록 위치를 체크하는 함수
bool checkXY(int user_x, int user_y) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

// ③ 목적지에 도착했는지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// ⑤ 현재 위치의 상태를 체크하고, 적, 포션, 무기, 갑옷 등에 대한 메시지 출력
void checkState(int map[][mapX], int user_x, int user_y) {
    switch (map[user_y][user_x]) {
    case 1:
        cout << "There is an item here." << endl;
        break;
    case 2:
        HP -= 2; // 적을 만날 경우 HP가 2 줄어듬
        cout << "Encountered an enemy! HP decreased by 2." << endl;
        break;
    case 3:
        HP += 2; // 포션을 만날 경우 HP가 2 증가
        cout << "Found a potion, HP increased by 2." << endl;
        break;
    case 5:
        cout << "You found a weapon!" << endl;
        map[user_y][user_x] = 0; // 무기 획득 후 해당 칸을 빈 칸으로 변경
        break;
    case 6:
        cout << "You found armor!" << endl;
        map[user_y][user_x] = 0; // 갑옷 획득 후 해당 칸을 빈 칸으로 변경
        break;
    }
}
