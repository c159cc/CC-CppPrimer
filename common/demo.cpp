#include "./cc.h"

int main() {
    int i = 0;
    typedef decltype(i) itype;
    typedef decltype(0) itype1;

    return 0;
}