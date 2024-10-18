#include "../common/cc.h"

/**
 * 9.5.2 insert的args参数
 */

int main()
{
    string rst = "00";
    string str = "12345";
    const char *cstr = "12345";
    string arr[] = {"1", "2", "3", "4", "5"};

    rst.insert(1, str);
    cout << " 00 1 str" << rst << endl;
    // rst = "00";
    // rst.insert(1, str, 1);
    // cout << " 00 1  str 1  " << rst << endl;

    rst = "00";
    rst.insert(1, str, 1, 2);
    cout << " 00 1  str 1  2 =" << rst << endl;

    rst = "00";
    rst.insert(1, cstr);
    cout << " 00 1 cstr =" << rst << endl;
    rst = "00";
    rst.insert(1, cstr, 1);
    cout << " 00 1  cstr 1   =" << rst << endl;

    rst = "00";
    rst.insert(1, cstr, 1, 2);
    cout << " 00 1  cstr 1  2 =" << rst << endl;
    return 0;
}