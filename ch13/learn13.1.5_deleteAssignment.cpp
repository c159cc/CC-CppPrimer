#include "../common/cc.h"

/**
 * 为什么有引用的类不能被复制？
 * 因为复制操作符的默认实现是拷贝所有成员变量，而引用成员变量是不能拷贝的。
 * 因此，如果类中有引用成员变量，则该类不能被复制。
 */
struct Foo{
    Foo(int i);
    void hello() const { cout << "Hello, world!" << endl; }
    int &r;
};

Foo::Foo(int i) : r(i) {};

int main()
{
 
    Foo f(42);
    f.hello();

    Foo f2(12);
    f2 = f; // error: assignment of reference member 'r' is not allowed
    f2.hello();  

    return 0;
}