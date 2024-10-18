#include "../common/cc.h"
#include "./StrBlobPtr.h"

StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
};
StrBlobPtr StrBlob::end()
{
  return StrBlobPtr(*this, data->size());
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
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

string &StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
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

  StrBlobPtr bg = strBlob.begin();
  StrBlobPtr ed = strBlob.end();

  while (bg != ed)
  {
    cout << bg.deref() << endl;
    bg.incr();
  }
  return 0;
}