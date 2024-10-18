#include "../common/cc.h"
using namespace ::std;
using namespace std::placeholders;
 
int main()
{

    vector<string> vec = {"aa", "bb", "bac", "dd","bb"};
    list<string> lst;

    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    for_each(lst.begin(), lst.end(), [](const string &s) { cout << s << endl; });

    return 0;
}