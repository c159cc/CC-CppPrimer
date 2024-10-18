#include "../../common/cc.h"

int main()
{

  double i = 100 / 3.0;   // 33.33333333....
  double you = 200 / 3.0; // 66.66666666....
  // cout << fixed << setprecision(4)
  //      << i << endl
  //      << you << endl;
  cout << i << endl << you << endl;

  cout << setfill('x') << setw(10) << 77 << endl;
  cout << false << endl;
  cout<<boolalpha<<false<<endl;
  return 0;
}