#include <iostream>
#include <string>
using namespace std;

// 세 자리 수의 자릿수가 모두 다른지 확인하는 함수
bool numCheck(int num) {
    int firstNum = num / 100;
    int secondNum = (num / 10) % 10;
    int thirdNum = num % 10;

    return (firstNum != secondNum) && (firstNum != thirdNum) && (secondNum != thirdNum);
}

int main() {
    int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
    int firstNum, secondNum, thirdNum; // 정답의 각 자리수

    // 서로 다른 자릿수를 가진 난수 생성
    while (1) {
        randomNum = rand() % 900 + 100; // 100~999 사이의 난수 생성
        if (numCheck(randomNum)) {
            firstNum = randomNum / 100;
            secondNum = (randomNum / 10) % 10;
            thirdNum = randomNum % 10;
            break;
        }
    }

    int turn = 0;
    while (1) {
        cout << turn + 1 << "번째 시도입니다." << endl;

        int userNumber; // 사용자가 입력한 세자리수 저장 변수
        int guessFirst, guessSecond, guessThird;

        // 사용자에게 세자리 수를 입력받는 코드 블록
        while (1) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            if (to_string(userNumber).length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
                continue;
            }

            if (numCheck(userNumber)) { // 자릿수가 모두 다르면 반복문 탈출
                guessFirst = userNumber / 100;
                guessSecond = (userNumber / 10) % 10;
                guessThird = userNumber % 10;
                break;
            } else {
                cout << "각 자리 수는 서로 달라야 합니다. 다시 입력하세요." << endl;
            }
        }

        int strike = 0, ball = 0;

        // 스트라이크와 볼 계산
        if (guessFirst == firstNum) strike++;
        if (guessSecond == secondNum) strike++;
        if (guessThird == thirdNum) strike++;

        if (guessFirst == secondNum || guessFirst == thirdNum) ball++;
        if (guessSecond == firstNum || guessSecond == thirdNum) ball++;
        if (guessThird == firstNum || guessThird == secondNum) ball++;

        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼입니다." << endl;

        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
