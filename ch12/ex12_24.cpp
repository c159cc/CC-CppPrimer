#include "../common/cc.h"
 
int main()
{

    cout<<"please input a number: ";
    int num;
    cin>>num;
    // cin.ignore(); // 忽略缓冲区剩余字符
    cout<<"you input "<<num<<endl;
    char* ch = new char[num+1];
    cout<<"please input a string: "<<endl;
    string str;
    cin.get(ch, num+1);
    cout<<"you input "<<ch<<endl;
    delete[] ch;
    return 0;
}