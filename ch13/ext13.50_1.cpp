#include "../common/cc.h"
class String
{
public:
    String() : String("") {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    // String(String &&) noexcept;
    // String &operator=(String &&) noexcept;
    ~String();

    const char *c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void range_initializer(const char *, const char *);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

// String::String(String &&s) noexcept : elements(s.elements), end(s.end)
// {
//     s.elements = s.end = nullptr;
// }
// String &String::operator=(String &&rhs) noexcept
// {
//     if (this != &rhs)
//     {
//         free();
//         elements = rhs.elements;
//         end = rhs.end;
//         rhs.elements = rhs.end = nullptr;
//     }
//     return *this;
// }
std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    cout << "Constructor called" << endl;
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}


void String::free()
{
    if (elements)
    {
        std::for_each(elements, end, [this](char &c)
                      { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String &String::operator=(const String &rhs)
{
    cout << "Copy assignment operator called" << endl;
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    return *this;
}





String::String(const String &rhs)
{
    cout << "Copy constructor called" << endl;
    range_initializer(rhs.elements, rhs.end);
}

String baz()
{
    String s1("hello");
    return s1;
}
int main(){

    String s2 = baz();

    return 0;
}