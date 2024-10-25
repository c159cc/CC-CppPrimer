#include "../common/cc.h"

/**
 * 既然unique_ptr可以设置为nullptr
 * shared_ptr也应该可以设置为nullptr
 */
int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    // string* const p = alloc.allocate(10);
    string* q = p;

    // p为const, 不能改变指向还是对象?
    alloc.construct(p, "hello");
    alloc.construct(p + 1, "world");

    for(size_t i = 0; i < 10; ++i) {
        *p = "test";
        p++;
    }

    cout<<*p<<endl;
    cout<<*(p+1)<<endl;

    alloc.destroy(p + 1);
    alloc.destroy(p);
    alloc.deallocate(p, 10);

    return 0;
}