#include "../common/cc.h"

int main()
{

    string str = "123";
    decltype(str.size()) s1 = 0;
    decltype(string::value_type) s2 = 0;
    return 0;
}