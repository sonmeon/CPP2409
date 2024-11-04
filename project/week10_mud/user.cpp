// user.cpp
#include "user.h"

User::User() : hp(20) {} // 생성자: 초기 HP를 20으로 설정

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp; // inc_hp 만큼 HP 증가
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // HP가 0 아래로 내려가지 않도록 설정
}

int User::GetHP() const {
    return hp; // 현재 HP 반환
}
