#include "../common/cc.h"

int main()
{

    int i = 10;
    int *ri = &i;
    const int *cri = ri;

    cout << "cri: " << *cri << endl;
    return 0;
}