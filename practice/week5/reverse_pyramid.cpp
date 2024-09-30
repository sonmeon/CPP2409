#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100):";
    cin >> floor;
    
    int i = floor;
    while (i > 0) {
        int j = 0;
        while (j < floor - i) {
            cout << "5";
            j++;
        }
        
        int k = 0;
        while (k < i * 2 - 1) {
            cout << "*";
            k++;
        }
        
        cout << endl;
        i--;
    }
    
    return 0;
}
