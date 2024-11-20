#include "user.h"

// User 기본 생성자
User::User() : hp(10), itemCnt(0) {}

// HP 조회
int User::GetHP() const {
    return hp;
}

// HP 설정
void User::SetHP(int newHP) {
    hp = newHP;
}

// HP 감소
void User::DecreaseHP(int amount) {
    hp -= amount;
}

// 아이템 추가
void User::AddItem() {
    itemCnt++;
}

// 아이템 개수 조회
int User::GetItemCnt() const {
    return itemCnt;
}

// 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP: " << user.GetHP() << ", 아이템 개수: " << user.GetItemCnt();
    return os;
}

// Magician 생성자
Magician::Magician() {
    hp = 20;
    itemCnt = 0;
}

// Magician 공격
void Magician::doAttack() const {
    std::cout << "마법사가 마법을 사용합니다!" << std::endl;
}

// Warrior 생성자
Warrior::Warrior() {
    hp = 20;
    itemCnt = 0;
}

// Warrior 공격
void Warrior::doAttack() const {
    std::cout << "전사가 칼로 공격합니다!" << std::endl;
}
