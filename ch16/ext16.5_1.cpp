#include "../common/cc.h"

int main()
{
    string arr3[4] = {"hello", "world", "c++", "primer"};

    for (auto elem : arr3)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << &arr3[0] << endl; // 0x62fcb0
    cout << arr3[0] << endl;  // hello
    cout << arr3 << endl;
    cout << &arr3 << endl;

    string* p1 = arr3;
    string(*p2)[4] = &arr3;
    cout << *p1 << endl;
    return 0;
}