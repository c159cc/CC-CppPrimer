#include "../common/cc.h"

class String
{
    friend ostream &operator<<(ostream &os, const String &s);
    allocator<char> alloc; // use default allocator
    char *elements;        // pointer to character array
    char *eleEnd;
    pair<char *, char *> alloc_n_copy(const char *begin, const char *end);
    void free();
    void range_initializer(const char *s, const char *p);

public:
    String() : elements(nullptr), eleEnd(nullptr) {} // default constructor
    String(const char *s);
    ~String()
    {
        free();
    }
    String &operator=(const String &s);
    String(const String &s);
};

String::String(const char *s)
{

    range_initializer(s, s + strlen(s) + 1);
}

void String::range_initializer(const char *s, const char *p)
{
    auto p2 = alloc_n_copy(s, p);
    elements = p2.first;
    eleEnd = p2.second;
}

ostream &operator<<(ostream &os, const String &s)
{

    // 构造一个cstyle string
    size_t len = s.eleEnd - s.elements;
    char *cstr = new char[len + 1];
    std::copy(s.elements, s.eleEnd, cstr);
    cstr[len] = '\0';
    // 输出cstyle string
    os << cstr;

    // 释放cstyle string
    delete[] cstr;

    return os;
};

void String::free()
{
    for_each(elements, eleEnd, [this](char &c)
             { alloc.destroy(&c); });
    alloc.deallocate(elements, eleEnd - elements); 
}

pair<char *, char *> String::alloc_n_copy(const char *begin, const char *end)
{
    size_t len = end - begin;
    auto data = alloc.allocate(len);           // allocate memory for string
    std::uninitialized_copy(begin, end, data); // copy characters to string
    return {data, data + len};
}

String::String(const String &s)
{ // copy constructor

    range_initializer(s.elements, s.eleEnd);
}

String &String::operator=(const String &s)
{
    auto newdata = alloc_n_copy(s.elements, s.eleEnd);
    free();
    elements = newdata.first;
    eleEnd = newdata.second; 

    return *this;
}

int main()
{

    String s2("world"), s1("hello");
    String s3 = s2;
    cout << "s2->s3:" << s3 << endl;
    s3 = s1;
    cout << "s1->s3:" << s3 << endl;
    return 0;
}