#include "../common/cc.h"
 
int main()
{
    const char *cp = "hello";
    const char *cp2 = "world";

    char *pc = new char[20];
    size_t idx = 0;
    while (*cp && idx < 20) {
        pc[idx] = *cp++;
        idx++;
    }
    pc[idx] = '\0';
    std::cout << "pc: " << pc << std::endl;

    while (*cp2 && idx < 20) {
        pc[idx] = *cp2++;
        idx++;
    }
    pc[idx] = '\0';
    std::cout << "pc: " << pc << std::endl;

    delete[] pc;

    string s1 = "hello";
    string s2 = "world";

    string s3 = s1 + s2;
    std::cout << "s3: " << s3 << std::endl;
    return 0;
}