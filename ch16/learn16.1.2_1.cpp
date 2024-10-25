#include "../common/cc.h"

namespace ch16
{
    template <typename T>
    class Demo
    {
    public:
        static int me;
    };

    template <typename T>
    int Demo<T>::me = 100;

};

int main()
{
    ch16::Demo<int> d1, d1_1;
    ch16::Demo<int> d3;
    ch16::Demo<double> d2;
    d1.me = 200;
    std::cout << "d1.me = " << d1.me << std::endl;
    std::cout << "d1_1.me = " << d1_1.me << std::endl; 
    std::cout << "d3.me = " << d3.me << std::endl;

    std::cout << "d2.me = " << d2.me << std::endl; // 100
    return 0;
}