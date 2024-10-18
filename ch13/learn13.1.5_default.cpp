#include "../common/cc.h"


struct Foo{
    Foo();
    void hello() const { cout << "Hello, world!" << endl; }
};

Foo::Foo()=default;

int main()
{
 
    Foo f;
    f.hello();
    return 0;
}