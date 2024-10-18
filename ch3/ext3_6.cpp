#include "../common/cc.h"

int main()
{

    string str = "123";
    string::size_type s1 = 0;
    for(auto &r:str)
    {
        r = 'X';
    }
    cout << str << endl;
    return 0;
}