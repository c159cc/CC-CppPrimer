#include "../common/cc.h"

int main()
{

	vector<int> vi = {1, 2, 3,3, 4, 5};
	auto pr = equal_range(vi.begin(), vi.end(),7);
	// cout << *pr.first << endl; // 3
	// cout << *pr.second << endl;// 4
	return 0;
}