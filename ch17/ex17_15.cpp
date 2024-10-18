#include "../common/cc.h"

int main(){

    string pattern = "[[:alpha:]]*[^c]ie[[:alpha:]]*";
    regex r(pattern);
    smatch s;
    string str;
    while(cin>>str){
        if(regex_match(str, s, r)){
            cout<<s.str()<<endl;
        }else{
            cout << "不匹配" << endl;
        }
    }

    return 0;
}