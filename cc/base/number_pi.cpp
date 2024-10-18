#include "../../common/cc.h"

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
  double x, y, r, pi;
  int n = 0, N = 1e7;
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    // 生成 -1 到 1 之间的随机数
    x = (double)rand() / RAND_MAX * 2 - 1; //[0, 1] => [0, 2] => [-1, 1]
    y = (double)rand() / RAND_MAX * 2 - 1; //[0, 1] => [0, 2] => [-1, 1]
    r = sqrt(x * x + y * y);
    if (r < 1)
    {
      n += 1;
    }
  }
  pi = n * 4.0 / N;
  cout << pi << endl;
  return 0;
}