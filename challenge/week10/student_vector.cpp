#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int score;

    while (true) {
        cout << "성적을 입력하세요 (-1 입력 시 종료): ";
        cin >> score;
        if (score == -1) break; // -1 입력 시 종료
        scores.push_back(score);
    }

    // 성적이 하나도 입력되지 않았을 경우
    if (scores.empty()) {
        cout << "입력된 성적이 없습니다." << endl;
    } else {
        // 평균 계산
        int sum = 0;
        for (int s : scores) {
            sum += s;
        }
        double average = static_cast<double>(sum) / scores.size();
        cout << "평균 성적: " << average << endl;
    }

    return 0;
}
