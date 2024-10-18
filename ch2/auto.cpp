#include "../common/cc.h"

int main()
{
    const int i = 42;
    auto j = i;        // int
    const auto &k = i; // const int&
    auto *p = &i;      // cost int*
    const auto j2 = i, // const int
        &k2 = i;       // const int&

    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(j2).name() << endl;
    cout << typeid(k2).name() << endl;

    return 0;
}