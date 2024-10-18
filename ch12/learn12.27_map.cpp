#include "../common/cc.h"

struct Foo
{
    Foo() { cout << "Foo()" << endl; }
    Foo(const Foo &) { cout << "Foo(const Foo&)" << endl; }
    Foo &operator=(const Foo &)
    {
        cout << "Foo& operator=(const Foo&)" << endl;
        return *this;
    }
    ~Foo() { cout << "~Foo()" << endl; }

    private:
        int val;
};

int main()
{

// Foo()会被调用2次
    map<int, Foo> m;
    m[1] = Foo();
    return 0;
}