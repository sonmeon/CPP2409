#include <iostream>
using namespace std;

int main() {
    int money, candyPrice;
    
    cout << "현재 가지고 있는 돈: ";
    cin >> money;
    cout << "캔디의 가격 : ";
    cin >> candyPrice;
    
    int maxCandies = money / candyPrice;
    int remainingMoney = money % candyPrice;
    
    cout << "최대로 살 수 있는 캔디 = " << maxCandies << endl;
    cout << "캔디 구입 후 남은 돈 = " << remainingMoney << endl;
    
    return 0;
}