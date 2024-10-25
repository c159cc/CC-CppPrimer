#include "../common/cc.h"

namespace ch16
{
    template <typename T, unsigned N>
    constexpr unsigned size(T (&arr)[N])
    {
        return N;
    }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    int res = ch16::size(p);
    cout << "Size of array is: " << res << endl; // 5
    return 0;
}