#include "../common/cc.h"
 
 struct NoDefault{
     NoDefault(int i):m_i(i){}
     int m_i;
 };
int main()
{
    vector<NoDefault> v(10);
    cout << v.size() << endl;
    return 0;
} 