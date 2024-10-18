#include "../common/cc.h"

int main()
{

    int i;
    cin >> i; // 1234 + 回车
    cout << i << endl;// 输出1234 + 回车
    string line;
    cin.ignore(); // 清空cin回车
    getline(cin, line); // 
    cout << "line=" << line << endl;

    return 0;
}