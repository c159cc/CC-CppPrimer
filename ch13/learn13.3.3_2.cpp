#include "../common/cc.h"

class Screen
{
public:
    void some_member() const;
    size_t non_const();

private:
    mutable size_t access_ctr=0;
};

void Screen::some_member() const
{
    ++access_ctr;
}

size_t Screen::non_const()
{
    return ++access_ctr;
}

int main()
{
    /**
     * 为什么const对象不能访问普通方法?
     * 因为普通成员函数可以修改this所指对象的属性, 而const成员函数限制了this为const指针, 不允许修改指向的对象
     */
    // const Screen cScreen;
    // cScreen.some_member();
    // cScreen.non_const();

    Screen nscreen;
    nscreen.some_member();
    auto rst = nscreen.non_const();
    cout << rst << endl;
    return 0;
}