#include "../common/cc.h"

template <typename T>
ostream &print(T const &t, ostream &os = cout)
{
    for (typename T::size_type i = 0; i < t.size(); ++i){
        os << t[i] << " ";
    }

    os << endl;
    return os;
};
// template <typename T>
// std::ostream &print(T const &container, std::ostream &os)
// {
//     for (typename T::size_type i = 0; i != container.size(); ++i)
//         os << container[i] << " ";
//     return os;
// }

int main()
{ 
    vector<int> v = {1, 2, 3, 4, 5};
    print(v, cout );
 
    return 0;
}