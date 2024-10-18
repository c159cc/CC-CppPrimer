#include "../common/cc.h"

int main()
{

    string str = "abcde";
    const char *pstr = str.c_str();
    cout << pstr << endl;
    str[1] = toupper(str[1]);
    cout << pstr << endl;
    return 0;
}