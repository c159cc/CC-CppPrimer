#include "../common/cc.h"

void swap1(int *p, int *q);
void swap2(int *p, int *q);
void swap3(int *&p, int *&q);
int main()
{
    int a = 5, b = 10;
    int *p = &a, *q = &b;
    int *&r = p;

    // r引用一个指针, p代表那个指针
    cout << "p=" << p << " *p=" << *p << " r=" << r << " *r=" << *r << endl;

    return 0;
}

void swap1(int *p, int *q)
{
    int *temp = p;
    p = q;
    q = temp;
}

void swap2(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swap3(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
}