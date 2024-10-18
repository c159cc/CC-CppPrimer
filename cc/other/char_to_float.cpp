#include "../common/cc.h"

int main()
{

	// 96 18 00 00
	unsigned char arr[] = {0x96, 0x18, 0x00, 0x00};
	float &fValue = *(float *)(arr);
	cout << fValue << endl;

	// 创建二进制文件写入内容为e86f0020
	return 0;
}