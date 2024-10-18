#include "../common/cc.h"

class numbered
{
public:
    numbered( ) : mysn(++si) {}
    numbered(const numbered& other) : mysn(++si) {}
    int get_num() const { return mysn; }
    

private:
    int mysn;
    static int si;
};

int numbered::si = 0;

void  f(numbered &s ){
    cout<<s.get_num()<<endl;
}

int main()
{
    numbered a,b=a,c=b;
    f(a);
    f(b);
    f(c);
    return 0;
}