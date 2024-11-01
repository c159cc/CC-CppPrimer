#include "../common/cc.h"

template <unsigned W, unsigned H>
class Screen
{
public:
    Screen() : width(W), height(H) {}

public:
    unsigned width, height;
};

int main()
{
    Screen<2, 3> sc;

    cout << "Hello, world!" << endl;

    cout << sc.width << " " << sc.height << endl;
    return 0;
}