#include "../common/cc.h"

// 符合条件的所有子串, 按照指定格式输出
int main(){
 

    string pattern = "(\\d{2})(\\d{3})";
    regex r(pattern);
    string s; 
    cout << "请输入:";
    while(getline(cin, s)){
        sregex_iterator it(s.begin(), s.end(), r), end_it;
        for (; it != end_it; it++)
        {
            cout << (*it).format("$1-$2") << endl;
        }
        cout << "请输入:";
    }
    return 0;
} 