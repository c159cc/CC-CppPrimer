#include "../common/cc.h"

/**
 * 既然unique_ptr可以设置为nullptr
 * shared_ptr也应该可以设置为nullptr
 */
int main()
{
    int *i(new int(1024));
    auto p2 = shared_ptr<int>(i);
    // p2 = nullptr; // 正确，shared_ptr可以设置为nullptr
    cout<<" i="<<*i<<endl; // 输出1024

    return 0;
}