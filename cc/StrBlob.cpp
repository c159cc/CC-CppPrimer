#include "../common/cc.h"
#include "./StrBlob.h"
 
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const
{
  if (i >= data->size())
  {
    throw out_of_range(msg);
  }
}
string &StrBlob::front()
{
  check(1, "front on empty StrBlob");
  return data->front();
}
string &StrBlob::back()
{
  check(1, "back on empty StrBlob");
  return data->back();
} 
void StrBlob::pop_back()
{
  check(1, "pop_back on empty StrBlob");
  data->pop_back(); 
}

string &StrBlob::front() const
{
  check(1, "front on empty StrBlob");
  return data->front();
}
string &StrBlob::back() const
{ 
  check(1, "back on empty StrBlob");
  return data->back();
}
