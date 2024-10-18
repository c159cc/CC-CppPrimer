#include "../common/cc.h"
#include "./StrBlob.h"

class StrBlobPtr
{
public:
StrBlobPtr( ): curr(0) {}
StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

shared_ptr<vector<string>> check(size_t i, const string &msg) const;
string & deref() const;
StrBlobPtr & incr();
bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

private:
weak_ptr<vector<string>> wptr;
size_t curr;
};
 