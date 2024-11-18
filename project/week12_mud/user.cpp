#include "user.h"

User::User() : hp(20), itemCnt(0) {} // 생성자: 초기값 설정

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int User::GetHP() const {
    return hp;
}

int User::GetItemCount() const {
    return itemCnt;
}

void User::AddItem() {
    itemCnt++;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() 
       << "이고, 먹은 아이템은 총 " << user.GetItemCount() << "개 입니다.";
    return os;
}
