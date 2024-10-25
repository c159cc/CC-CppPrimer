#include "../common/cc.h"

#include "../cc/Sales_data h"
template <typename T>
int compare(T a, T b)
{
    if (a < b)
        return -1;
    if (b < a)
        return 1;
    return 0;
}

int main()
{
    Sales_data a, b;

    cout << compare(b, a) << endl; // 1
    cout << compare(a, b) << endl; // -1
    cout << compare(a, a) << endl; // 0
    return 0;
}