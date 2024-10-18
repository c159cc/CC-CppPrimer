#include "../common/cc.h"

int main()
{

    string s1;
    string s2;

    int i = 0;
    while (++i < 3)
    {
        getline(cin, s1);
        s2 += s1+" ";
    }

    cout << s2 << endl;
    return 0;
}