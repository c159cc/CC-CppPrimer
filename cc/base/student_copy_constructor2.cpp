#include <iostream>

using namespace std;

int current_pencil_box_id = 0;
int current_student_id = 0;
// 文具盒
struct PencilBox
{
  PencilBox(void) : id(++current_pencil_box_id)
  {
    cout << "PencilBox() id=" << id << endl;
  }
  PencilBox(const PencilBox &box) : id(++current_pencil_box_id)
  {
    cout << "PencilBox(const PencilBox& " << box.id << ") id=" << id << endl;
  }
  ~PencilBox()
  {
    cout << "~PencilBox() id=" << id << endl;
  }
  int id = 0;
};
// 学生
struct Student
{
  Student(void) : id(++current_student_id)
  {
    cout << "Student() id=" << id << endl;
  }
  Student(const Student &stu) : id(++current_student_id)
  {
    cout << "Student(const Student& " << stu.id << ") id=" << id << endl;
  }
  ~Student()
  {
    cout << "~Student() id=" << id << endl;
  }
  int id = 0;
  PencilBox m_pencilBox;
};

void pass_by_value(Student stu)
{
  cout << "pass_by_value stu " << stu.id << endl;
}
void pass_by_reference(Student &stu)
{
  cout << "pass_by_reference stu " << stu.id << endl;
}

/**
 * main begin
PencilBox() id=1 创建Stu1
Student() id=1 

PencilBox() id=2
Student(const Student& 1) id=2 拷贝构造stu2

PencilBox() id=3
Student(const Student& 1) id=3  // 拷贝构造stu3

pass_by_value stu 3
~Student() id=3 // 删除stu3
~PencilBox() id=3

pass_by_reference stu 1

main end
~Student() id=2
~PencilBox() id=2
~Student() id=1
~PencilBox() id=1
 */
int main(void)
{
  cout << "main begin" << endl;
  //(1) your code. 
  Student stu1;
  Student stu2(stu1);
  pass_by_value(stu1);
  pass_by_reference(stu1); // stu1的id已经被改为3了啊?

  cout << "main end" << endl;

  return 0;
}