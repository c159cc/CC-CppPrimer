#include "../common/cc.h"

int main()
{

    // Error
    string arr[] = {"aa", "bb", "cc", "dd"};
    auto sum = accumulate(begin(arr), end(arr), "myStr_", [](string a, string b)
                          { return a + b; });
    cout << "sum=" << sum << endl;

    return 0;
}