#include "../common/cc.h"

int main()
{
    int i = 42;
    const int &r = i;
    int &r2 = i;
    r2 = 3;

    cout << i << endl;
    cout << r << endl;

    i = 9;
    cout << i << endl;
    cout << r << endl;
    return 0;
}