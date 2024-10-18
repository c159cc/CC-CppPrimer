#include "../common/cc.h"

void swap1(int *p, int *q);
void swap2(int *p, int *q);
void swap3(int *&p, int *&q);
int main()
{
    {
        int a = 5, b = 10;
        int *p = &a, *q = &b;
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
        swap1(p, q);
        // p和q的指向改变 Error
        // p和q什么都不变
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
    }
    {
        int a = 5, b = 10;
        int *p = &a, *q = &b;
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
        swap2(p, q);
        // p和q的值改变
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
    }

    {
        int a = 5, b = 10;
        int *p = &a, *q = &b;
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
        swap3(p, q);
        // p和q的值改变 Error
        // p和q的地址和值都改变
        cout << "\tp=" << p << "\t*p=" << *p << "\tq=" << q << "\t*q=" << *q << endl;
    }
    return 0;
}

void swap1(int *p, int *q){
    int* temp = p;
    p = q;
    q = temp;
}

void swap2(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swap3(int *&r1, int *&r2){
    // r1表示引用等于p, r1表示地址
    int *temp = r1;
    r1 = r2;
    r2 = temp;
}