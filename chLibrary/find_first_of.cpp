#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 4, 5};
	vector<int> vi2 = {3,9};
	auto it = find_first_of(vi1.begin(), vi1.end(), vi2.begin(), vi2.end(), [](int i1, int i2){
		return i1 == i2;
	});// 3 (first element of vi2 is found in vi1 

	cout << *it << endl;
	return 0;
}