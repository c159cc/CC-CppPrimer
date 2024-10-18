#include "../common/cc.h"

 namespace cc1{
    class Boo{
        public:
            int age = 10;
            std::string name = "bare";
    };

    void hello(Boo b){
        std::cout << "hello " <<b.age<<" "<<b.name<< std::endl;
    }

    void hello2()
    {
        std::cout << "hello2 "  << std::endl;
    }
    void hello()
    {
        std::cout << "hello single " << std::endl;
    }
 };

int main(){
    cc1::Boo b1;
    hello(b1);
    // 所以除了名字相同之外, 还必须包含一个条件, 参数为class类型
    //  hello2();
    //  hello();

    return 0;
} 