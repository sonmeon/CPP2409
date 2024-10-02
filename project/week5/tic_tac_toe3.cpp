#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;

    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (int x = 0; x < numCell; x++) {
        for (int y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누가 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while (true) {
        // 1. 누가 차례인지 출력
        switch (k % 3) {
            case 0:
                cout << "첫 번째 유저(X)의 차례입니다 ~" << endl;
                currentUser = 'X';
                break;
            case 1:
                cout << "두 번째 유저(O)의 차례입니다 ~" << endl;
                currentUser = 'O';
                break;
            case 2:
                cout << "세 번째 유저(V)의 차례입니다 ~" << endl;
                currentUser = 'V';
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(y, x) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << "범위를 벗어났습니다." << endl;
            cout << "x와 y 둘 중 하나가 값을 벗어났습니다." << endl;
            continue;
        }

        if (board[x][y] != ' ') {
            cout << "(x, y) : 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << " " << board[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << " |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        k++;
        
        //6. 빙고 시 승자 출력 후 종료 (행, 열, 대각선)
        int cntX = 0, cntO = 0, cntV = 0;

        // 행 방향 체크
        for (int j = 0; j < numCell; j++) {
            cntX = 0; cntO = 0; cntV = 0;
            for (int i = 0; i < numCell; i++) {
                if (board[i][j] == 'X')
                    cntX++;
                else if (board[i][j] == 'O')
                    cntO++;
                else if (board[i][j] == 'V')
                    cntV++;
            }

            if (cntX == numCell || cntO == numCell || cntV == numCell) {
                cout << "종료" << endl;
                switch (currentUser) {
                    case 'X':
                        cout << "첫 번째 유저(X) 승리!" << endl;
                        break;
                    case 'O':
                        cout << "두 번째 유저(O) 승리!" << endl;
                        break;
                    case 'V':
                        cout << "세 번째 유저(V) 승리!" << endl;
                        break;
                }
                return 0;
            }
        }

        // 열 방향 체크
        for (int j = 0; j < numCell; j++) {
            cntX = 0; cntO = 0; cntV = 0;
            for (int i = 0; i < numCell; i++) {
                if (board[j][i] == 'X')
                    cntX++;
                else if (board[j][i] == 'O')
                    cntO++;
                else if (board[j][i] == 'V')
                    cntV++;
            }

            if (cntX == numCell || cntO == numCell || cntV == numCell) {
                cout << "종료" << endl;
                switch (currentUser) {
                    case 'X':
                        cout << "첫 번째 유저(X) 승리!" << endl;
                        break;
                    case 'O':
                        cout << "두 번째 유저(O) 승리!" << endl;
                        break;
                    case 'V':
                        cout << "세 번째 유저(V) 승리!" << endl;
                        break;
                }
                return 0;
            }
        }

        // 대각선 방향 체크
        cntX = 0; cntO = 0; cntV = 0;

        for (int i = 0; i < numCell; i++) {
            if (board[i][i] == 'X')
                cntX++;
            else if (board[i][i] == 'O')
                cntO++;
            else if (board[i][i] == 'V')
                cntV++;
        }

        if (cntX == numCell || cntO == numCell || cntV == numCell) {
            cout << "종료" << endl;
            switch (currentUser) {
                case 'X':
                    cout << "첫 번째 유저(X) 승리!" << endl;
                    break;
                case 'O':
                    cout << "두 번째 유저(O) 승리!" << endl;
                    break;
                case 'V':
                    cout << "세 번째 유저(V) 승리!" << endl;
                    break;
            }
            return 0;
        }

        cntX = 0; cntO = 0; cntV = 0;

        for (int i = 0; i < numCell; i++) {
            if (board[i][numCell - 1 - i] == 'X')
                cntX++;
            else if (board[i][numCell - 1 - i] == 'O')
                cntO++;
            else if (board[i][numCell - 1 - i] == 'V')
                cntV++;
        }

        if (cntX == numCell || cntO == numCell || cntV == numCell) {
            cout << "종료" << endl;
            switch (currentUser) {
                case 'X':
                    cout << "첫 번째 유저(X) 승리!" << endl;
                    break;
                case 'O':
                    cout << "두 번째 유저(O) 승리!" << endl;
                    break;
                case 'V':
                    cout << "세 번째 유저(V) 승리!" << endl;
                    break;
            }
            return 0;
        }

        // 7. 모든 칸이 찼으면 실행 종료
        bool isBoardFull = true;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    isBoardFull = false;
                    break;
                }
            }
            if (!isBoardFull) break;
        }

        if (isBoardFull) {
            cout << "모든 칸이 꽉 찼습니다. 무승부!" << endl;
            return 0;
        }
    }
}
