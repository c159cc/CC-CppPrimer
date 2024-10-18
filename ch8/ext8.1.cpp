#include "../common/cc.h"

istream &func(istream &is) {
    string s;
    while (is >> s) {
        cout << s << endl;
    }
    is.clear();
    return is;
};
int main()
{
    func(cin);
    return 0;
} 