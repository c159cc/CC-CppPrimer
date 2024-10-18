#include "../common/cc.h"

std::string convertToHexString(const unsigned char *data, size_t size)
{
    std::stringstream ss;

    for (size_t i = 0; i < size; ++i)
    {
        if (i != 0)
        {
            ss << " ";
        }
        ss << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]);
    }

    return ss.str();
}

int main() {

    unsigned char data[] = {0xe8, 0x6f, 0x00, 0x20};
    std::string hexString = convertToHexString(data, sizeof(data));

cout << hexString << endl;

    return 0;
}