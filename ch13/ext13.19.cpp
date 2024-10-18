#include "../common/cc.h"

struct Employee
{
    int id;
    string name;

    Employee() : id(++count), name("") {};
    Employee(const string &name) : id(++count), name(name) {};

    Employee(const Employee &other) : id(++count), name(other.name) {};
    Employee &operator=(const Employee &other);

private:
    static int count;
};

int Employee::count = 0;
Employee &Employee::operator=(const Employee &other) {
    if (this!= &other) {
        id = ++count;
        name = other.name;
    }
    return *this;
};
int main()
{
    Employee e1;
    Employee e2("John"); 
    cout << e1.id << " " << e1.name << endl;
    cout << e2.id << " " << e2.name << endl;

    return 0;
}