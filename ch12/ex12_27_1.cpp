#include "ex12_27_1.h"

TextQuery::TextQuery(std::ifstream &infile) : lines(make_shared<vector<string>>()), word_map(map<string, shared_ptr<set<size_t>>>())
{
  string line;
  size_t line_number = 1;
  while (std::getline(infile, line))
  {
    istringstream iss(line);
    string word;
    while (iss >> word)
    {
      // map中是否存在这个word
      auto &wSet = word_map[word]; // 避免shared_ptr的拷贝 
      if(!wSet){
        // 表示还没有指向对象, 是一个空指针
        wSet = make_shared<set<size_t>>();
      }
      wSet->insert(line_number);
    }

    lines->push_back(line);
    ++line_number;
  }

  cout << "Text Query created." << endl;
}

QueryResult TextQuery::query(const string &word) const
{ 
  auto found = word_map.find(word);
  if (found == word_map.end()) return QueryResult(word, make_shared<set<size_t>>(), lines);

  return QueryResult(word, found->second, lines); 
}

ostream &print(ostream &os, const QueryResult &qr)
{
  os << "The word: " << qr.word << " occurs " << qr.line_numbers->size() << " times in the file." << endl;
  for (auto line_number : *qr.line_numbers)
  { 
    os << "Line: " << qr.lines->at(line_number - 1) << endl;
  }
  return os;
}