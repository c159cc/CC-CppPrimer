#include <iostream>
using namespace std;

class Student
{
public:
  int *m_age; // 指针成员：管理动态内存
  // 构造函数中申请堆内存
  Student() : m_age(new int(18)) // 3 执行构造函数
  {
  }
  Student::Student(const Student& from):m_age(new int(*from.m_age)){}
  ~Student() // 5 析构函数释放堆内存
  {
    delete m_age; // 释放栈变量m_age所指向的堆内存。并不是指删除栈指针变量。
  }
};

int main()
{
  try{
    // 1 main函数开始执行
    Student stu; // 2 在栈上创建新对象stu（分配内存），接下来调用构造函数
    Student stu2;
    stu = stu2;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  return 0;
} // 4 stu对象超出作用域，接下来调用析构函数