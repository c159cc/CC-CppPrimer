#include "../common/cc.h"

int main()
{

    string line;
    getline(cin, line); // 1234 + �س�
    cout << line << endl; // ���1234 + �س�  
    getline(cin, line); // 
    cout << "line=" << line << endl;

    return 0;
}