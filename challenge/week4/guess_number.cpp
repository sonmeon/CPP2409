#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); 

    int answer = rand() % 100; 
    int tries = 0; 
    int guess; 

    do {
        cout << "숫자를 입력하세요 (0-99): ";
        cin >> guess; 
        tries++; 

        if (guess > answer) {
            cout << "더 작은 수를 입력하세요." << endl;
        } else if (guess < answer) {
            cout << "더 큰 수를 입력하세요." << endl;
        }

    } while (guess != answer); 

    cout << "축하합니다. 시도 횟수 = " << tries << endl;

    return 0;
}