#include <iostream>
using namespace std;

int current_id = 0;

struct Student
{
  Student(void) : id(current_id)
  {
    cout << "Student() id=" << id << endl;
    ++current_id;
  }
  ~Student()
  {
    cout << "~Student() id=" << id << endl;
  }
  int id = 0;
};

/**
 * Student() id=0
Student() id=1
Student() id=2
~Student() id=2
~Student() id=1
Student() id=3
~Student() id=3
~Student() id=0
 */
int main(void)
{
  //(1) your code.
  // 提示创建对象之后，更早释放的办法之一就是使用大括号作用域（在大括号内创建对象）；
  // 或者使用动态内存手动管理决定何时释放
  Student stu0;
  {
    Student stu1;
    {
      Student stu2;
    } 
  }
  {
    Student stu3;
  }

  return 0;
}