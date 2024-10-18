#include "../common/cc.h"

std::string convertToHexString(const unsigned char ch, size_t size)
{
    std::stringstream ss;

    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ch);

    return ss.str();
}

int main() {

    unsigned char data[] = {0xe8, 0xa5, 0x00, 0x20};
    std::string hexString = convertToHexString(data[1], sizeof(data));
    // hexString倒序
    reverse(hexString.begin(), hexString.end());
    cout << hexString << endl;

    return 0;
}