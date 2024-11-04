// user.h
#ifndef USER_H
#define USER_H

class User {
private:
    int hp; // 사용자 HP 상태 (private 속성)

public:
    User(); // 생성자: 초기 HP 설정
    void IncreaseHP(int inc_hp); // HP 증가 함수
    void DecreaseHP(int dec_hp); // HP 감소 함수
    int GetHP() const; // 현재 HP 반환 함수
};

#endif // USER_H
