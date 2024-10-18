#include "../common/cc.h"

int main()
{

    unsigned char uc = 200;
    char *pc = reinterpret_cast<char *>(&uc);
    unsigned char *puc = reinterpret_cast<unsigned char *>(pc);

    std::cout << "原始值: " << static_cast<int>(uc) << std::endl;
    std::cout << "转换后的值: " << static_cast<int>(*puc) << std::endl;

    return 0;
}