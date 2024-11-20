#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name; // protected로 변경
    string address;
};

class Student : public Person
{
public:
    void SetAddress(string add)
    {
        address = add;
    }

    string GetAddress()
    {
        return address;
    }

    void SetName(string name)
    {
        this->name = name; // protected로 되어 있어 접근 가능
    }

    string GetName()
    {
        return name; // 이름 반환
    }
};

int main()
{
    Student obj;
    obj.SetName("미수"); // 이제 정상 작동
    obj.SetAddress("서울시 종로구 1번지");

    cout << "이름: " << obj.GetName() << endl;
    cout << "주소: " << obj.GetAddress() << endl;

    return 0;
}
