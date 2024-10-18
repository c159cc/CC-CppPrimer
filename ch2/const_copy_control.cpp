#include "../common/cc.h"

int main()
{
    int i = 13;
    const int *const cic = &i;
    const int *const cic2 = cic;
    const int *cic3 = cic;
    int *const cic4 = cic;// error: invalid conversion from ‘const int*’ to ‘int*’

    cout << i << endl;
    return 0;
}