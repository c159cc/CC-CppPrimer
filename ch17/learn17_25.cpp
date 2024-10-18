#include "../common/cc.h"


int main(){

    vector<string> vec{
        "morgan (201) 555-2368 862-555-0123", "drew (973)555.0130", "lee(609) 555-0132 2015550175 800.555-0000"};

    string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(pattern);
    for (size_t i = 0; i != 3; i++)
    {
        // cout << regex_replace(vec[i], r, "$2.$5.$7\t", match_any) << endl;

        string str = vec[i];
        sregex_iterator it(str.begin(), str.end(), r), end_it;
       
        for (it++; it != end_it; ++it)
        {
            cout << it->str() + "\t";
        }
        cout << endl;
    }
    

    return 0;
} 