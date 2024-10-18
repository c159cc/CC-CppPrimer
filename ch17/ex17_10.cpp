#include "../common/cc.h"

int main(){

    bitset<21> b;
    b.set(0);
    b.set(1);
    b.set(2);
    b.set(4);
    b.set(7);
    b.set(12);
    b.set(20);
    cout << b << endl; 

    bitset<21> b1;
    b1.flip();
    cout << b1 << endl;
    
    return 0;
}