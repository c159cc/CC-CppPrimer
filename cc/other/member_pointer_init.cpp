#include "../common/cc.h"

struct Boo{
    void sayHello(){
        cout << "hello" << endl;
    };
};

struct Foo{
    Boo *boo;
    void hello(){
        boo->sayHello();
    };
};

int main()
{
    Foo foo;
    // 为什么foo.boo没有初始化就能调用?
    foo.boo->sayHello(); // 这个能调用成功吗?

    return 0;
}