#include "../common/cc.h"
 
 struct NoDefault{
     NoDefault(int i):m_i(i){}
     int m_i;
 };
int main()
{
    char ch1[128] = {0};
    cout<<sizeof(ch1)<<endl;
    return 0;
} 