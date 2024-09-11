#include <iostream>
using namespace std;

int main() {
    double fahrenheit, celsius;

    cout << "화씨 온도: ";
    cin >> fahrenheit;

    celsius = (5.0 / 9.0) * (fahrenheit - 32);

    cout << "섭씨 온도 = " << celsius << endl;

    return 0;
}
