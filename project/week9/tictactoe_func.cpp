#include <iostream>
#include <vector>
using namespace std;

bool isValid(int x, int y, const vector<vector<char>>& board) {
	if (x >= board.size() || y >= board.size() || x < 0 || y < 0) {
		cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
		return false;
	}
	if (board[x][y] != ' ') {
		cout << x << "," << y << ": 이미 돌이 차 있습니다." << endl;
		return false;
	}
	return true;
}

bool checkWin(char currentUser, const vector<vector<char>>& board) {
	int numCell = board.size();
	// 가로/세로 체크
	for (int i = 0; i < numCell; i++) {
		bool rowWin = true, colWin = true;
		for (int j = 0; j < numCell; j++) {
			if (board[i][j] != currentUser) rowWin = false;
			if (board[j][i] != currentUser) colWin = false;
		}
		if (rowWin || colWin) return true;
	}
	// 대각선 체크
	bool diag1 = true, diag2 = true;
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] != currentUser) diag1 = false;
		if (board[i][numCell - i - 1] != currentUser) diag2 = false;
	}
	return diag1 || diag2;
}

int main() {
	int numCell;
	cout << "보드 크기를 입력하세요 (예: 3): ";
	cin >> numCell;

	vector<vector<char>> board(numCell, vector<char>(numCell, ' '));
	int k = 0;
	char currentUser;

	while (true) {
		switch (k % 3) {
			case 0: currentUser = 'X'; break;
			case 1: currentUser = 'O'; break;
			case 2: currentUser = 'Y'; break;
		}
		cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";
		
		int x, y;
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;

		if (!isValid(x, y, board)) continue;

		board[x][y] = currentUser;

		// 보드판 출력
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j != numCell - 1) cout << " | ";
			}
			cout << endl;
			if (i != numCell - 1) {
				for (int j = 0; j < numCell; j++) cout << "---";
				cout << endl;
			}
		}

		if (checkWin(currentUser, board)) {
			cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 모든 칸이 다 찼는지 확인
		int checked = 0;
		for (int i = 0; i < numCell; i++)
			for (int j = 0; j < numCell; j++)
				if (board[i][j] == ' ') checked++;

		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
			break;
		}

		k++;
	}

	return 0;
}
