#include "../common/cc.h"
#include "./StrBlob.h"

class ConstStrBlobPtr
{
public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  shared_ptr<vector<string>> check(size_t i, const string &msg) const;
  string &deref() const;
  ConstStrBlobPtr &incr();
  bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }

private:
  weak_ptr<vector<string>> wptr;
  size_t curr;
};

ConstStrBlobPtr StrBlob::begin() const
{
  return ConstStrBlobPtr(*this);
};
ConstStrBlobPtr StrBlob::end() const
{
  return ConstStrBlobPtr(*this, data->size());
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if (!ret)
  {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (i >= ret->size())
  {
    throw std::out_of_range(msg);
  }
  return ret;
}

string &ConstStrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

int main()
{
  ifstream in("g:/hello.txt");
  string line;
    StrBlob strBlob;
  while (getline(in, line))
  {
    strBlob.push_back(line);
  }

  const StrBlob &cStrBlob = strBlob;

  ConstStrBlobPtr bg = cStrBlob.begin();
  ConstStrBlobPtr ed = cStrBlob.end();

  while (bg != ed)
  {
    cout << bg.deref() << endl;
    bg.incr();
  }
  return 0;
}