#include "../common/cc.h"

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr &hp);

    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};
 
    HasPtr& HasPtr::operator=(const HasPtr &hp){
        if (this == &hp) return *this;
        delete ps;
        ps = new string(*hp.ps);
        i = hp.i;
        return *this;
    }

int main()
{ 


    return 0;
}