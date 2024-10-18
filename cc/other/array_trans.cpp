#include "../common/cc.h"

int main()
{

    string arr= {"1", "2"};
    string *arr2 = &arr;
    cout << arr2[1] << endl;
    return 0;
}