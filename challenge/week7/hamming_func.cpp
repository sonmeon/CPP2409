#include <iostream>
#include <string>
using namespace std;

// 소문자로 변환하는 함수 (수동 구현)
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

// 대문자로 변환하는 함수 (수동 구현)
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str;
}

// 해밍 거리를 계산하는 함수
int calcHammingDist(string s1, string s2) {
    if (s1.length() != s2.length()) {
        cout << "문자열의 길이가 같지 않습니다.\n";
        return -1;
    }
    
    // 대소문자 구분 없이 비교하기 위해 소문자로 변환
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    int hammingDist = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            hammingDist++;
        }
    }
    return hammingDist;
}

int main() {
    string s1, s2;
    
    // 문자열의 길이가 같을 때까지 반복해서 입력 받기
    do {
        cout << "첫 번째 문자열을 입력하세요: ";
        cin >> s1;
        cout << "두 번째 문자열을 입력하세요: ";
        cin >> s2;
        if (s1.length() != s2.length()) {
            cout << "문자열의 길이가 다릅니다. 다시 입력해주세요.\n";
        }
    } while (s1.length() != s2.length());

    // 해밍 거리 계산
    int count = calcHammingDist(s1, s2);
    if (count != -1) {
        cout << "해밍 거리는 " << count << " 입니다." << endl;
    }
    
    return 0;
}
