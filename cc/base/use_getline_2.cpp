#include "../common/cc.h"

int main()
{

    string line;
    getline(cin, line); // 1234 + 回车
    cout << line << endl; // 输出1234 + 回车  
    getline(cin, line); // 
    cout << "line=" << line << endl;

    return 0;
}