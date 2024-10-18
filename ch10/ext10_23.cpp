#include "../common/cc.h"
using namespace ::std;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    string str = "123456";

    auto res = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));

    cout << "res=" << *res << endl;

    return 0;
}