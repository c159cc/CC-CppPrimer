#include "../common/cc.h"

int main()
{
    const char *cp = "hello";
    const char *cp2 = "world";

    char *pc = new char[strlen(cp) + strlen(cp2) + 1]();
    strcat(pc, cp);
    strcat(pc, cp2);
    std::cout << "pc: " << pc << std::endl;

    delete[] pc;

    string s1 = "hello";
    string s2 = "world";

    string s3 = s1 + s2;
    std::cout << "s3: " << s3 << std::endl;
    return 0;
}