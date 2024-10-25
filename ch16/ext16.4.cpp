#include "../common/cc.h"

#include "../cc/Sales_data h"
template <typename T, typename U>
T ffind(T it, T end, U value)
{
    while (it != end)
    {
        if (*it == value)
        {
            return it;
        }
        it++;
    }
    return it;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    list<int> lst{1, 2, 3, 4, 5};

    auto res = ffind(vec.begin(),vec.end(), 3);
    if (res != vec.end())
        cout << "found " << *res << endl;

    auto res2 = ffind(lst.begin(), lst.end(), 5);
    if (res2 != lst.end())
        cout << "found " << *res2 << endl;
    return 0;
}