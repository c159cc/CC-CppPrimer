#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 3, 5, 1, 2, 3, 4, 5}; 
	auto it = search_n(vi1.begin(), vi1.end(),2,3); //

	if (it != vi1.end())
		cout << (it-vi1.begin()) << endl;
	else
		cout << "not found" << endl;
	return 0;
}