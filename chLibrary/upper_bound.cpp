#include "../common/cc.h"

int main()
{

	vector<int> vi = {1, 2, 3, 4, 5};
	auto it = upper_bound(vi.begin(), vi.end(),4); 
	cout << *it << endl;
	return 0;
}