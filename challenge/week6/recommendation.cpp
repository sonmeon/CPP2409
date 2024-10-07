#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_USERS = 3;  // 사용자 수
const int NUM_ITEMS = 5;  // 항목 수

// 전역 변수: 사용자 선호도 배열
int userPreferences[NUM_USERS][NUM_ITEMS];

// 사용자 선호도 입력 함수
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; i++) {
        cout << "사용자 " << i + 1 << "의 선호도를 입력하세요 (예: 3 1 4 2 5): ";
        for (int j = 0; j < NUM_ITEMS; j++) {
            cin >> preferences[i][j];
        }
    }
}

// 사용자별 추천 항목 찾는 함수
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {
    srand(time(0));  // 랜덤 선택을 위한 시드 설정
    
    for (int i = 0; i < NUM_USERS; i++) {
        int maxPreference = preferences[i][0];
        int recommendedItemIndex = 0;

        // 선호도가 가장 높은 항목 찾기
        for (int j = 1; j < NUM_ITEMS; j++) {
            if (preferences[i][j] > maxPreference) {
                maxPreference = preferences[i][j];
                recommendedItemIndex = j;
            }
            else if (preferences[i][j] == maxPreference) {
                // 선호도가 동일한 경우 랜덤 선택
                if (rand() % 2 == 0) {
                    recommendedItemIndex = j;
                }
            }
        }

        cout << "사용자 " << i + 1 << "에게 추천된 항목: " << recommendedItemIndex + 1 << endl;
    }
}

int main() {
    // 사용자 선호도 초기화
    initializePreferences(userPreferences);

    // 사용자에게 추천할 항목 찾기
    findRecommendedItems(userPreferences);

    return 0;
}
