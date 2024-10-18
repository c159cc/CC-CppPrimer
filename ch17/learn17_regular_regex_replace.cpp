#include "../common/cc.h"

int main(){

    string pattern = "\\d{3}";
    regex r(pattern);
    string str = "abc123def456ghi789";
    auto rst = regex_replace(str, r, "000");
    cout << rst << endl;

    string dest;
    regex_replace(back_inserter(dest), str.begin(), str.end(), r, "000"); 
    cout << dest << endl;

    return 0;
}