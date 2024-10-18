#include "../common/cc.h"
class QueryResult;
class TextQuery
{
private:
    map<string, shared_ptr<set<size_t>>> word_map; // word -> set of occurrences
    shared_ptr<vector<string>> lines;
public:
    TextQuery(ifstream &infile);
    QueryResult query(const string &word) const;
};

class QueryResult
{
    friend ostream &print(ostream &os, const QueryResult &qr);
    shared_ptr<set<size_t>> line_numbers;
    shared_ptr<vector<string>> lines;
    string word;

public:
    QueryResult(string wd, shared_ptr<set<size_t>> numbers, shared_ptr<vector<string>> nLines) : line_numbers(numbers), lines(nLines), word(wd) {};
};

ostream &print(ostream &os, const QueryResult &qr);
