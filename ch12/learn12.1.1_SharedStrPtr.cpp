#include "../common/cc.h"

class SharedStrPtr
{
public:
    SharedStrPtr() : ptr(nullptr), count(new size_t(1)) {}
    SharedStrPtr(string *p) : ptr(p), count(new size_t(1)) {}
    size_t use_count() const { return count ? *count : 0; }

    SharedStrPtr(const SharedStrPtr &other) : ptr(other.ptr), count(other.count)
    {
        if (count)
        {
            ++(*count);
        }
    };
    SharedStrPtr &operator=(const SharedStrPtr &other);
    ~SharedStrPtr();

private:
    size_t *count;
    string *ptr;
    void release();
};

SharedStrPtr::~SharedStrPtr()
{
    release();
}

SharedStrPtr &SharedStrPtr::operator=(const SharedStrPtr &other)
{
    if (this != &other)
    {
        release();
        ptr = other.ptr;
        count = other.count;
        if (count)
        {
            ++(*count);
        }
    }
    return *this;
}
void SharedStrPtr::release()
{
    cout << "release " << (*count-1) << endl;
    if (count && --(*count) == 0)
    {
        delete ptr;
        delete count;
    }
}

int main()
{
    SharedStrPtr ptr(new string("hello1"));
    SharedStrPtr ptr2 = ptr;
    cout << "after ptr2 = ptr " << ptr.use_count() << endl;
    SharedStrPtr ptr3 = ptr2;
    cout << "after ptr3 = ptr2 " << ptr.use_count() << endl;

    return 0;
}