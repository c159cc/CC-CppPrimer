#include "../common/cc.h"

/**
 * 9.5.1.3 string的末尾是不是自带null terminated
 */

bool hasNullTerminator(const std::string &str)
{
    return str.back() == '\0';
}

int main()
{
    char noNull[] = {'H', 'i'}; 
    string s2(noNull, 2); // "Hi"
    cout << " s2 = " << s2 << endl;
    cout << " length = " << s2.length() << endl; // 2
    cout << " size = " << s2.size() << endl;     // 2
    cout << " hasNullTerminator = " << hasNullTerminator(s2) << endl;

    const char *cp = "Hi";
    string s3(cp);
    auto c3 = s3.c_str();
    cout << " s3 = " << s3 << endl;
    cout << " length = " << s3.length() << endl; // 2
    cout << " size = " << s3.size() << endl;     // 2
    cout << " hasNullTerminator = " << hasNullTerminator(s3) << endl;

    char src[] = "hello";
    string s4(src);
    cout << " s4 = " << s4 << endl;
    cout << " length = " << s4.length() << endl; // 5
    cout << " size = " << s4.size() << endl;     // 5
    cout << " hasNullTerminator = " << hasNullTerminator(s4) << endl;
    return 0;
}