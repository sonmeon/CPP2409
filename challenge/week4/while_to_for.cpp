#include <iostream>
using namespace std;

int main() {
    int userInput;

    cout << "정수를 10번 입력하시오 (0을 입력하면 종료):" << endl;

    for (int i = 0; i < 10; i++) {
        cin >> userInput;

        if (userInput == 0) {
            break; // 0을 입력하면 루프 종료
        }

        cout << "입력값: " << userInput << " 횟수: " << i + 1 << endl;
    }

    cout << "종료 되었습니다" << endl;

    return 0;
}