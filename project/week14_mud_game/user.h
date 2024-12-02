#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class GameUser {
private:
    int HP;
    int itemCnt;
public:
    GameUser();
    int GetHP() const;
    void SetHP(int newHP);
    void DecreaseHP(int amount);
    void AddItem();
    int GetItemCnt() const;
    void doAttack() const;
    friend ostream& operator<<(ostream& os, const GameUser& user);
};

#endif // USER_H
