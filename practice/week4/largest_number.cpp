#include <iostream>
using namespace std;
int main()
{
    int a,b,c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a>> b>> c;

    if (a > b && a > c)
        largest = a;
    else if (b > c)
        largest = b;//b가 a보다 작거나 같은 것은 필요 없다.
    else
        largest = c;

    cout << "가장 큰 정수는" << largest << endl;
    return 0;

}