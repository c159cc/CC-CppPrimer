#include "../common/cc.h"
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

public:
  typedef vector<string>::size_type size_type;
  StrBlob();
  StrBlob(initializer_list<string> il);
  size_t size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const string &s) { data->push_back(s); }
  void pop_back();
  string &front();
  string &back();
  string &front() const;
  string &back() const;
  StrBlobPtr begin();
  StrBlobPtr end();

  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

private:
  shared_ptr<vector<string>> data;
  void check(size_type i, const string &msg) const;
};

