#include "../common/cc.h"

namespace MyNamespace
{
    int nonDynamicVar = 42;     // 普通命名空间变量
    static int staticVar = 100; // 静态命名空间变量

    void display()
    {
        std::cout << "Non-Dynamic Variable: " << nonDynamicVar << std::endl;
        std::cout << "Static Variable: " << staticVar << std::endl;
    }
}
 