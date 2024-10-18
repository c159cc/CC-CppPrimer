#include "../common/cc.h"

int main()
{
    auto p1 = make_shared<int>(100);
    auto p2 = p1;
    auto p3 = p2;

    cout << "p1: " << p1.use_count() << endl;

    p2 = p1;
    cout << "p1: " << p1.use_count() << endl;
    return 0;
}