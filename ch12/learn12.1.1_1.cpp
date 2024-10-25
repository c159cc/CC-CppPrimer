#include "../common/cc.h"

int main()
{

    shared_ptr<vector<int>> p1;

    if(!p1){
        cout<<"p1 is null"<<endl;
    }
    cout << p1.get() << endl;
    //p1->push_back(10); // 指针初始化了, 但是指向的对象并没有初始化
    cout << "end" << endl;

    double a{2};
    cout << a << endl;

    return 0;
}