#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

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
        cout << "\n메뉴 선택:\n";
        cout << "1. 나이가 가장 많은 사람 출력\n";
        cout << "2. 나이가 가장 적은 사람 출력\n";
        cout << "3. 종료\n";
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int maxAge = ages[0];
                for (int i = 1; i < maxPeople; i++) {
                    if (ages[i] > maxAge) {
                        maxAge = ages[i];
                    }
                }
                cout << "나이가 가장 많은 사람(들): " << endl;
                for (int i = 0; i < maxPeople; i++) {
                    if (ages[i] == maxAge) {
                        cout << names[i] << " (" << ages[i] << "세)\n";
                    }
                }
                break;
            }
            case 2: {
                int minAge = ages[0];
                for (int i = 1; i < maxPeople; i++) {
                    if (ages[i] < minAge) {
                        minAge = ages[i];
                    }
                }
                cout << "나이가 가장 적은 사람(들): " << endl;
                for (int i = 0; i < maxPeople; i++) {
                    if (ages[i] == minAge) {
                        cout << names[i] << " (" << ages[i] << "세)\n";
                    }
                }
                break;
            }
            case 3:
                cout << "프로그램을 종료합니다." << endl;
                running = false;
                break;

            default:
                cout << "잘못된 입력입니다. 프로그램을 종료합니다." << endl;
                running = false;
                break;
        }
    }

    return 0;
}
