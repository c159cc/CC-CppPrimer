#include "../common/cc.h"

class DebugDelete
{
public:
    DebugDelete(ostream &os=cerr) : os(os) {}
    template <typename T>
    void operator()(T *ptr) const
    {
        os << "deleting "  << std::endl;
        delete ptr;
    }

private:
    ostream &os;
};

int main()
{ 
    unique_ptr<int, DebugDelete> p(new int, DebugDelete(cout));
    return 0;
}