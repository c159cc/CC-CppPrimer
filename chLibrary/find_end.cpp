#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	vector<int> vi2 = { 2,3};
	auto it = find_end(vi1.begin(), vi1.end(), vi2.begin(), vi2.end());// 

	if(it != vi1.end())
		cout << *it << endl;
	else
		cout << "not found" << endl; 
	return 0;
}