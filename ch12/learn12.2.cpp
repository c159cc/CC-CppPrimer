#include "../common/cc.h"

// 全局对象作用域, 程序启动到main函数结束, 全局对象才会被释放
// 程序启动是在main
// 全局对象在main函数之前创建, 全局对象在main函数结束后释放
int cc = 2;
void display()
{
    cout << cc << endl; // 2
};

// cout << cc << endl; // 2
// display();

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