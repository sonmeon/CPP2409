#include "user.h"

GameUser::GameUser() : HP(20), itemCnt(0) {}

int GameUser::GetHP() const {
    return HP;
}

void GameUser::SetHP(int newHP) {
    HP = newHP;
}

void GameUser::DecreaseHP(int amount) {
    HP -= amount;
}

void GameUser::AddItem() {
    itemCnt++;
}

int GameUser::GetItemCnt() const {
    return itemCnt;
}

void GameUser::doAttack() const {
    cout << "Attack!" << endl;
}

ostream& operator<<(ostream& os, const GameUser& user) {
    os << "HP: " << user.HP << ", Items: " << user.itemCnt;
    return os;
}
