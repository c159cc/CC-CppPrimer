#include "../common/cc.h"

int main(){

    // find the characters ei that follow a character other than c
    string pattern("[^c]ei");
    // we want the whole word in which our pattern appears
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern); // construct a regex to find pattern
    smatch results;   // define a object to hold the results of a search
    string test_str = "receipt freind theif receive";
    if (regex_search(test_str, results, r))
    {
        cout << results.str() << endl;
    }


    return 0;
}