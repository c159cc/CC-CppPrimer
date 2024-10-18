#include "../common/cc.h"
using namespace ::std;
using namespace std::placeholders;
bool foo(size_t len, string s)
{
    if(s.length()==len){
        return true;
    }

    return false;
}

int main()
{

     vector<string> svec= {"aa", "bbbbbb", "cc", "dd"};
     size_t sz = 6;
    //  auto res = find_if(svec.begin(),  svec.end(), [sz](string s){return s.size() == sz;});

     // bind返回的函数假设为fb; 调用fb的时候第一个参数会传递给foo作为foo的第2个参数
     auto res = find_if(svec.begin(), svec.end(), bind(foo, sz, _1));

     cout << "res=" << *res << endl;

     return 0;
}