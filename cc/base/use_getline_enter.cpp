#include "../common/cc.h"

int main()
{

    int i;
    cin >> i; // 1234 + �س�
    cout << i << endl;// ���1234 + �س�
    string line;
    cin.ignore(); // ���cin�س�
    getline(cin, line); // 
    cout << "line=" << line << endl;

    return 0;
}