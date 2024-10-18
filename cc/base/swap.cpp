#include "../../common/cc.h"

#include <iostream>
using namespace std;

void Swap(int &i, int &j) // 注意这里一定要传递引用，否则传值是不能完成任务的
{
  int t = i;
  i = j;
  j = t;
}
int main()
{
  int a = 2;
  int b = 3;
  cout << "a=" << a << ", b=" << b << endl;

  Swap(a, b);
  cout << "a=" << a << ", b=" << b << endl;

  return 0;
}