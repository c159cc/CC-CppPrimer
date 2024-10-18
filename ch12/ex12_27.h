#pragma once
#include "../common/cc.h"
#ifndef EX12_27_H
#define EX12_27_H

using line_no = vector<string>::size_type;

class QueryResult;
class TextQuery{ 
    public:
    // set中存放line_no而不是int
    TextQuery(ifstream&);   
    QueryResult query(const string&) const;
    private:
    shared_ptr<vector<string>> lines;
    // 这里为什么不是shared整个map?
    map<string, shared_ptr<set<line_no>>> wordMap;
};

class QueryResult{ 
    friend ostream& print(ostream&, const QueryResult&);
    public:
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):word(s), line_set(p), lines(f){}
    private:
       string word;
       shared_ptr<set<line_no>> line_set;
       shared_ptr<vector<string>> lines;
};

ostream &print(ostream &, const QueryResult &);

void hello();

#endif