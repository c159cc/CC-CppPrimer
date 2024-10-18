#include "../common/cc.h"


int add(int a){
    return ++a;
}

int b = 0;
const int test( )
{
    return ++b;
}
int main()
{
    int v1 = 42;
    auto f = [v1]()  
    { return ++v1; };

    
    v1 = 0;
    auto j = f();

    cout << "j" << j << endl;
    cout<<"v1" << v1 << endl;
    return 0;
}