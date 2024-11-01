#include "../common/cc.h"

template <typename T>
ostream &print(T const &t, ostream &os = cout)
{

    auto it = t.begin();
    while (it != t.end())
    {
        os << *it << " ";
        ++it;
    }

    os << endl;
    return os;
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    print(v, cout);

    return 0;
}