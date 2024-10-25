#include "../common/cc.h"

int main()
{
    string arr3[2][2] = {{"hello", "world"}, {"c++", "primer"}};

    cout << &arr3[0] << endl; // 0x62fca0
    cout << &arr3[0][0] << endl; // 0x62fca0
    cout << &arr3 << endl;       // 0x62fca0

    auto p1 = &arr3[0];
    auto p2 = &arr3[0][0];
    ++p1;
    ++p2;

    cout << (*p1) << endl; // 0x62fce0
    cout << (*p1)[0] << endl; // c++
    cout << *p2 << endl;      // world
    cout << &arr3[1] << endl; // 0x62fce0
    cout << arr3[1] << endl; // 0x62fce0
    return 0;
}