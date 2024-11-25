#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int hp; // HP 저장
    int itemCnt; // 아이템 개수 저장

public:
    virtual ~User() {}

    virtual int GetHP() const = 0;          // HP 조회
    virtual void SetHP(int newHP) = 0;      // HP 설정
    virtual void DecreaseHP(int amount) = 0; // HP 감소
    virtual void AddItem() = 0;             // 아이템 추가
    virtual int GetItemCnt() const = 0;     // 아이템 개수 조회

    virtual void doAttack() const = 0; // 순수 가상 함수: 상속받은 클래스에서 구현 필요

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "현재 HP: " << user.GetHP() << ", 아이템 개수: " << user.GetItemCnt();
        return os;
    }
};

class Magician : public User {
public:
    Magician();
    int GetHP() const override;
    void SetHP(int newHP) override;
    void DecreaseHP(int amount) override;
    void AddItem() override;
    int GetItemCnt() const override;
    void doAttack() const override;
};

class Warrior : public User {
public:
    Warrior();
    int GetHP() const override;
    void SetHP(int newHP) override;
    void DecreaseHP(int amount) override;
    void AddItem() override;
    int GetItemCnt() const override;
    void doAttack() const override;
};

#endif // USER_H
