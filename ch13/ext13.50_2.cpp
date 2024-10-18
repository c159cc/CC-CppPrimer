#include "../common/cc.h"

struct String
{
public:
    String();
    String(const String &s);
    String &operator=(const String &s);
    String(String &&s);
    String &operator=(String &&s);
    int data;

private:
    static int count;
};

int String::count = 0;
String::String()
{
    data = ++count;
    cout << "String()" << endl;
}

String::String(const String &s){
    data = ++count;
    cout << "String(const String &s)" << endl;
}

String &String::operator=(const String &s)
{
    data = s.count;
    cout << "operator=" << endl;
    return *this;
}

String::String(String &&s){
    cout << "String(String &&s)" << endl;
}
String &String::operator=(String &&s)
{
    cout << "operator=(String &&s)" << endl;
    return *this;
}

String baz()
{
    String s1;
    s1.data = 100;
    return s1;
}
int main()
{
 
    String s2 = baz(); 
    return 0;
}