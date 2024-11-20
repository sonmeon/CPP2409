#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int hp; // HP 저장
    int itemCnt; // 아이템 개수 저장

public:
    User(); // 기본 생성자
    virtual ~User() {}

    int GetHP() const;          // HP 조회
    void SetHP(int newHP);      // HP 설정
    void DecreaseHP(int amount); // HP 감소
    void AddItem();             // 아이템 추가
    int GetItemCnt() const;     // 아이템 개수 조회

    virtual void doAttack() const = 0; // 순수 가상 함수: 상속받은 클래스에서 구현 필요

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class Magician : public User {
public:
    Magician();
    void doAttack() const override; // 마법사 공격
};

class Warrior : public User {
public:
    Warrior();
    void doAttack() const override; // 전사 공격
};

#endif // USER_H
