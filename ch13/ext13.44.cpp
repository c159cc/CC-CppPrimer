#include "../common/cc.h"

class String
{
    friend ostream &operator<<(ostream &os, const String &s);
    allocator<char> alloc; // use default allocator
    char *data;            // pointer to character array
    void alloc_n_copy(const char *s);
    void free();

public:
    String() : data(nullptr) {} // default constructor
    ~String()
    {
        free();
    }
    String(const String &s);
    String &operator=(const String &s);
    String(const char *s) : data(nullptr)
    { // constructor with string argument
        if (s)
        {
            alloc_n_copy(s);
        }
    }
};

ostream &operator<<(ostream &os, const String &s)
{
    if(s.data){
        os << s.data;
    }  
    return os;
}

void String::free()
{
    if (data){
        alloc.deallocate(data, strlen(data) + 1); // deallocate memory for string
        data = nullptr;
    }

}

void String::alloc_n_copy(const char *s)
{
    size_t len = strlen(s);
    data = alloc.allocate(len + 1); // allocate memory for string
    std::copy(s, s + len, data);    // copy characters to string
    data[len] = '\0';               // add null terminator
}

String::String(const String &s) : data(nullptr)
{ // copy constructor
    if (s.data)
    {
        alloc_n_copy(s.data);
    }
}

String &String::operator=(const String &s)
{
    if (this == &s)
    {
        return *this;
    }
    free();
    if (s.data)
    {
        alloc_n_copy(s.data);
    }
    return *this;
}

int main()
{

    String s1;
    String s2("world");
    cout << s2 << endl;
    return 0;
}