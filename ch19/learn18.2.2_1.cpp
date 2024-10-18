#include "../common/cc.h"

 struct Base{
 };
 struct Derived : public Base{};

int main(){
    Derived *dp = new Derived();
    Base *bp = dp;

    if(typeid(*bp) == typeid(Derived))
        cout << "bp points to a Derived\n";
    else
        cout << "bp points to a Base\n";

    if (typeid(*dp) == typeid(*bp))
        cout << "*dp == *bp\n";
    else
        cout << "*dp != *bp\n";

    if (typeid(*dp) == typeid(Derived))
        cout << "*dp == Derived\n";
    else
        cout << "*dp != Derived\n";

    if(typeid(bp)==typeid(Derived))
        cout << "bp = Derived\n";
    else
        cout << "bp != Derived\n";

    if (typeid(bp) == typeid(Base))
        cout << "bp = Base\n";
    else
        cout << "bp != Base\n";
    return 0;
} 