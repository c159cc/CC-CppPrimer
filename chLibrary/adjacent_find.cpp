#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 3, 4, 5, 1, 2, 3, 4, 5}; 
	auto it = adjacent_find(vi1.begin(), vi1.end() );// 

	if(it != vi1.end())
		cout << (it-vi1.begin()) << endl;
	else
		cout << "not found" << endl; 
	return 0;
}