#include "../common/cc.h"

// int move(string s1)
// {
//     return 123;
// };
string move(string s1, string s12)
{
    return "123";
};
string hello(string s1)
{
    return "hello cc";
};

int main(){
 
    string s="str";
    string &&rs = move(12);
    cout << rs << endl;
    cout << hello(s) << endl;

    return 0;
} 