#include "../common/cc.h"

namespace ch16
{
    template <typename T, unsigned N>
    T* begin(  T (&arr)[N])
    {
        return &arr[0];
    }

    template <typename T, unsigned N>
    T *end(  T (&arr)[N])
    {
        T *r = &arr[N - 1];
        return ++r;
    }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = ch16::begin(arr);
    int *q = ch16::end(arr);
    for (; p != q; ++p)
    {
        std::cout << *p << " ";
    }
    cout<<endl;
    return 0;
}