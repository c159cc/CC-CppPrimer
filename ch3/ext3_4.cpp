#include "../common/cc.h"

int main()
{

    string s1;
    string s2;
    
    getline(cin, s1);
    getline(cin, s2);

    if(s1 == s2)
    {
        cout << "s1 == s2" << endl;
    }
    else if(s1 > s2)
    {
        cout << "s1 > s2" << endl;
    }
    else
    {
        cout << "s1 < s2" << endl;
    }

    return 0;
}