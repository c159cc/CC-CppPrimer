#include "../common/cc.h"

struct Employee
{
    int id;
    string name;

    Employee() : id(++count), name("") {};
    Employee(const string &name) : id(++count), name(name) {};

    private:
        static int count;
};

int Employee::count = 0; 
int main()
{
    Employee e1;
    Employee e2("John"); 
    cout << e1.id << " " << e1.name << endl;
    cout << e2.id << " " << e2.name << endl;

    return 0;
}