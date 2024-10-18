#include "../common/cc.h"

int main(){

    regex r("[[:alnum:]]+\\.(cpp|cc|cxx)$", regex::icase); //
    r = ".*(\\d+)cc*";
    smatch rst;
    string filename;
    while (cin >> filename)
        if (regex_match(filename, rst, r)){
            cout << rst.size() << endl;
            cout << rst.str() << endl;
        }
          

    return 0;
}