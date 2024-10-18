#include "../common/cc.h"

int main()
{

	vector<int> vi = {1, 2, 3, 4, 5};
	auto it = find_if_not(vi.begin(), vi.end(), [](int i){return i < 3;}); // 3

	cout << *it << endl;
	return 0;
}