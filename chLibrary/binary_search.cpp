#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 4, 5 }; 
	bool b = binary_search(vi1.begin(), vi1.end(),4); //

	cout << b << endl;
	return 0;
}