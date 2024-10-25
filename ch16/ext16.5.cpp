#include "../common/cc.h"

// template <typename T, unsigned N>
// void print_array(const T (&arr)[N])
// {
//     for (unsigned i = 0; i != N; ++i)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }


template <typename Arr>
void print_array(const Arr& arr){
    for(auto& elem : arr){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    print_array(arr1);

    double arr2[3] = {1.1, 2.2, 3.3};
    print_array(arr2);

    string arr3[4] = {"hello", "world", "c++", "primer"};
    print_array(arr3);

    return 0;
}