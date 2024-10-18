#include "../common/cc.h"

bool myfunction(int i, int j)
{
	return (i == j);
}

template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end2(ForwardIterator1 first1, ForwardIterator1 last1,
						  ForwardIterator2 first2, ForwardIterator2 last2)
{
	if (first2 == last2)
		return last1; // specified in C++11

	ForwardIterator1 ret = last1;

	while (first1 != last1)
	{
		ForwardIterator1 it1 = first1;
		ForwardIterator2 it2 = first2;
		while (*it1 == *it2)
		{ // or: while (pred(*it1,*it2)) for version (2)
			++it1;
			++it2;
			if (it2 == last2)
			{
				ret = first1;
				break;
			}
			if (it1 == last1)
				return ret;
		}
		++first1;
	}
	return ret;
}

int main()
{ 
	vector<int> haystack = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	vector<int> needle1 = {1, 2, 3};

	// using default comparison:
	vector<int>::iterator it;
	it = find_end2(haystack.begin(), haystack.end(), needle1.begin(), needle1.end());

	if (it != haystack.end()){
		cout << "needle1 found at position " << (it - haystack.begin()) << endl;
	} else {
		cout << "needle1 not found" << endl;
	}

	return 0;
}