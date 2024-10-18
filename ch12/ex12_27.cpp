#include "./ex12_27.h"



TextQuery::TextQuery(ifstream &infile):lines(new vector<string>) {
    // lines需要初始化, wordMap为什么不需要初始化?
    string line;
    while(getline(infile, line)){
        lines->push_back(line);
        int n = lines->size() - 1;
        istringstream iss(line);
        string word;
        while(iss>>word){
            // 判断map中是否存在
            auto &s = wordMap[word];
            if(!s){
                // 这里s可以直接调用reset吗?
                s.reset(new set<line_no>);
            }
            s->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const{
	// we'll return a ponter to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    
    auto loc = wordMap.find(sought);
    if(loc==wordMap.end()){
        return QueryResult(sought, nodata, lines);
    }else
        return QueryResult(sought, loc->second, lines);
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.word << " occurs " << qr.line_set->size() << " " << make_plural(qr.line_set->size(), "time", "s") << endl;
    for (auto num : *qr.line_set)
    {
        os << "\t(line " << num + 1 << ")"
           << *(qr.lines->begin() + num) << endl;
    }
    return os;
}

void hello()
{
    cout << "helloc cc 123" << endl;
}