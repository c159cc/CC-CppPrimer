#include "../common/cc.h"

namespace MyNamespace
{
    void display();
    extern int nonDynamicVar;
    static int staticVar;
}
int main()
{
    MyNamespace::display();

    cout << MyNamespace::nonDynamicVar << endl;
    cout << MyNamespace::staticVar << endl;

    return 0;
}