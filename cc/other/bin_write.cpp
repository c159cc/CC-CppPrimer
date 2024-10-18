#include "../common/cc.h"
 

int main() {
    // 创建一个 ofstream 对象，并以二进制模式打开文件
	std::ofstream outfile("G:\\test.bin", std::ios::binary);

	// 检查文件是否成功打开
    if (!outfile) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    // 写入内容
	unsigned char data[] = {0xe8, 0x6f, 0x00, 0x20};
	outfile.write(reinterpret_cast<char*>(&data), sizeof(data));

    // 关闭文件
    outfile.close();

    return 0;
}