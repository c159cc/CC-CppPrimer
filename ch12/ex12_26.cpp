#include "../common/cc.h"
// 要看懂: 将分配和构造区分开来的好处
int main()
{
    // size_t n = 10;
    // string *const p = new string[n]; // 表示p不能++, --
    // string s;
    // string *q = p;
    // while (cin >> s && q != p + n)
    //     *q++ = s;
    // const size_t size = q - p;
    // delete[] p;

    size_t n = 10;
    allocator<string> a;
    string *p = a.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n)
        a.construct(q++, s);

    while (q != p)
    {
        cout << *q << " ";
        a.destroy(--q);
    }
    cout << endl;
    a.deallocate(p, n);

    return 0;
}