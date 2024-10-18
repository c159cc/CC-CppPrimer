#include "../common/cc.h"
using namespace ::std;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDumps(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDumps(words);
    stable_sort(words.begin(), words.end(), isShorter);
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    cout << (wc - words.begin()) << endl;
    for_each(words.begin(), wc, [](const string &s) { cout << s << endl; });
}

int main()
{

    vector<string> vec = {"aa", "bb", "bac", "dd","bb"};
    string str = "123456";

    biggies(vec, 5); 

    return 0;
}