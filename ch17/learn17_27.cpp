#include "../common/cc.h"

// ���������������Ӵ�, ����ָ����ʽ���
int main(){
 

    string pattern = "(\\d{2})(\\d{3})";
    regex r(pattern);
    string s; 
    cout << "������:";
    while(getline(cin, s)){
        sregex_iterator it(s.begin(), s.end(), r), end_it;
        for (; it != end_it; it++)
        {
            cout << (*it).format("$1-$2") << endl;
        }
        cout << "������:";
    }
    return 0;
} 