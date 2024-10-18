#include "../common/cc.h"

int main()
{

    string s1;
    string s2;
    
    getline(cin, s1);
    getline(cin, s2);

    if(s1.size() == s2.size())
    {
        cout << "s1.size() == s2.size()" << endl;
    }
    else if(s1.size() > s2.size())
    {
        cout << "s1.size() > s2.size()" << endl;
    }
    else
    {
        cout << "s1.size() < s2.size()" << endl;
    }

    return 0;
}