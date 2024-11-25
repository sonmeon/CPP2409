#include "user.h"

// Magician 생성자
Magician::Magician() {
    hp = 20;
    itemCnt = 0;
}

int Magician::GetHP() const {
    return hp;
}

void Magician::SetHP(int newHP) {
    hp = newHP;
}

void Magician::DecreaseHP(int amount) {
    hp -= amount;
}

void Magician::AddItem() {
    itemCnt++;
}

int Magician::GetItemCnt() const {
    return itemCnt;
}

void Magician::doAttack() const {
    std::cout << "마법사가 마법을 사용합니다!" << std::endl;
}

// Warrior 생성자
Warrior::Warrior() {
    hp = 20;
    itemCnt = 0;
}

int Warrior::GetHP() const {
    return hp;
}

void Warrior::SetHP(int newHP) {
    hp = newHP;
}

void Warrior::DecreaseHP(int amount) {
    hp -= amount;
}

void Warrior::AddItem() {
    itemCnt++;
}

int Warrior::GetItemCnt() const {
    return itemCnt;
}

void Warrior::doAttack() const {
    std::cout << "전사가 칼로 공격합니다!" << std::endl;
}
