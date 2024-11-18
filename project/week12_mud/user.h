#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    int hp;
    int itemCnt; // 먹은 아이템 횟수 저장

public:
    User(); // 생성자: 초기값 설정
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP() const;
    int GetItemCount() const; // 아이템 개수 반환
    void AddItem(); // 아이템 개수 증가

    // << 연산자 중복 정의
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif
