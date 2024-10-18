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

    string str = "1A 03 11 F1 A1 62 01 00 00 00 86 DC";
    vector<string> tokens;
    istringstream iss(str);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

    unsigned char ch1[] = {0x5A, 0x03, 0x11, 0xF1, 0xA1, 0x62, 0x01, 0x00, 0x00, 0x00, 0x86, 0xDC};

    for (int i = 0; i < tokens.size(); i++)
    {
        int value = stoi(tokens[i], nullptr, 16);
        ch1[i] = static_cast<char>(value);
    }
    string ss = convertToHexString(ch1 , 12);
    cout << ss << endl;
    return 0;
}