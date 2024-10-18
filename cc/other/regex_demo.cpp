#include "../common/cc.h"

int main() {

	std::regex range_regex("\\s*\\[(\\d+\\.?\\d*),(\\d+\\.?\\d*)\\](万)?.*");
	// string str = "[2.2,3]万";
	string str = "[4.8,6]万";
	std::smatch matchRst;
	auto rst = std::regex_match(str, matchRst, range_regex);
	if (rst && matchRst.size() >= 3)
	{
		cout << "ok" << endl;
	}
	return 0;
}