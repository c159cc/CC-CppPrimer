#include "../common/cc.h"

int main()
{
 
    string line;
    cout << "请输入2行文本" << endl;
    getline(cin, line);
    cout << "第一行文本" << line << endl;
    getline(cin, line);
    cout << "第二行文本" << line << endl;
    return 0;
}