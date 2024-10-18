#include "../../common/cc.h"

#include <ios>
int main()
{

  std::ios oldState(nullptr);
  oldState.copyfmt(std::cout);

 
  double i = 100 / 3.0;   // 33.33333333....
  double you = 200 / 3.0; // 66.66666666....
  // cout << fixed << setprecision(4)
  //      << i << endl
  //      << you << endl;
  cout << i << endl << you << endl;

  cout << setfill('x') << setw(10) << 77 << endl;
  cout << false << endl;
  cout<<boolalpha<<false<<endl;
  std::cout.copyfmt(oldState); 
  return 0;
}