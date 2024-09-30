#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    // 사용자로부터 회원 정보 입력 받기
    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int choice;
    bool running = true;

    while (running) {
        // 메뉴 출력
        cout << "\n메뉴 선택:\n";
        cout << "1. 나이가 가장 많은 사람 출력\n";
        cout << "2. 나이가 가장 적은 사람 출력\n";
        cout << "3. 종료\n";
        cout << "선택: ";
        cin >> choice;

        if (choice == 1) {
            // 나이가 가장 많은 사람 찾기
            int maxAgeIndex = 0;
            for (int i = 1; i < maxPeople; i++) {
                if (ages[i] > ages[maxAgeIndex]) {
                    maxAgeIndex = i;
                }
            }
            cout << "나이가 가장 많은 사람: " << names[maxAgeIndex] << " (" << ages[maxAgeIndex] << "세)\n";
        } 
        else if (choice == 2) {
            // 나이가 가장 적은 사람 찾기
            int minAgeIndex = 0;
            for (int i = 1; i < maxPeople; i++) {
                if (ages[i] < ages[minAgeIndex]) {
                    minAgeIndex = i;
                }
            }
            cout << "나이가 가장 적은 사람: " << names[minAgeIndex] << " (" << ages[minAgeIndex] << "세)\n";
        } 
        else if (choice == 3) {
            // 종료 선택
            cout << "프로그램을 종료합니다." << endl;
            running = false;
        } 
        else {
            // 잘못된 입력 처리
            cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
            running = false;
        }
    }

    return 0;
}
