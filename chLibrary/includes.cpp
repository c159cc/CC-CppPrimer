#include "../common/cc.h"

int main()
{

	vector<int> vi1 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	vector<int> vi2 = {2, 3};
	bool b = includes(vi1.begin(), vi1.end(), vi2.begin(), vi2.end()); //

	cout << b << endl;
	return 0;
}