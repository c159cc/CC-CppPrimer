#include "../common/cc.h"

int main()
{

	vector<int> vi = {1, 2, 3, 4, 5};
	auto it = lower_bound(vi.begin(), vi.end(), 2.5); // 3

	cout << (it-vi.begin()) << endl;
	return 0;
}