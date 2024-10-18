#include "../common/cc.h"

/**
 * 字符数组可不可指定坐标和长度?
 * 可以的
 */
int main()
{

    char c1[] = {'a', 'b', 'c', 'd'};
    string s1 = string(c1 , 2, 2);
    cout <<  " s1 = " << s1 << endl;
    return 0;
}