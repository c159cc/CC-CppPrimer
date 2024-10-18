#include "../common/cc.h"

int main()
{
    // 创建一个 ifstream 对象，并以二进制模式打开文件
    std::ifstream infile("G:\\test.bin", std::ios::binary);

    // 检查文件是否成功打开
    if (!infile)
    {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    // 读取内容
    char data[sizeof(float)];
    infile.read(data, sizeof(data));

    // 将读取的数据转换为 float 类型
    float value = *reinterpret_cast<float *>(data);
    std::cout << "读取的值为: " << value << std::endl;

    // 关闭文件
    infile.close();

    return 0;
}