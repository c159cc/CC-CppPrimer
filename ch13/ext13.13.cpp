#include "../common/cc.h"

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(X x)
{
    std::cout << "f(X x)" << std::endl;
}

void f2(X& x){
    std::cout << "f2(X& x)" << std::endl;
}


void shared_ptr_test(){
    shared_ptr<X> p1(new X);
    cout << "p1.use_count() = " << p1.use_count() << endl;
}
int main()
{
    shared_ptr_test();
    return 0;
}