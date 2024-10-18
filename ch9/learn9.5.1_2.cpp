#include "../common/cc.h"

/**
 * 9.5.1.2  非null结尾的字符数组能不能构造string?
 */
int main()
{
    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i'};
    string s1(cp);
    string s2(noNull, 2); // "Hi"
    string s3(noNull);    // undefined
    cout <<  " s1 = " << s1 << endl;
    cout <<  " s2 = " << s2 << endl;
    cout <<  " s3 = " << s3 << endl; // 未定义
    return 0;
}