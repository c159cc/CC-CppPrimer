#include <iostream>
#include <regex>

int main() {
    std::regex range_regex("\\s*\\[(\\d+\\.?\\d*),(\\d+\\.?\\d*)\\](万)?.*");

    std::string test1 = "[2.2,3]万";
    std::string test2 = "[4.8,6]万";
    std::string test3 = "[300,750]";
    std::string test4 = "[0.03,0.07]";
    std::string test5 = "[2.2,3.3]";
    std::string test6 = "[2.2,3]";
    std::string test7 = "[0.03,0.07]";
    std::string test8 = "[0.03,0.07]";

    std::smatch matchRst;

    bool rst1 = std::regex_match(test1, matchRst, range_regex);
    bool rst2 = std::regex_match(test2, matchRst, range_regex);
    bool rst3 = std::regex_match(test3, matchRst, range_regex);
    bool rst4 = std::regex_match(test4, matchRst, range_regex);
    bool rst5 = std::regex_match(test5, matchRst, range_regex);
    bool rst6 = std::regex_match(test6, matchRst, range_regex);
    bool rst7 = std::regex_match(test7, matchRst, range_regex);
    bool rst8 = std::regex_match(test8, matchRst, range_regex);

    std::cout << "Test 1: " << (rst1 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 2: " << (rst2 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 3: " << (rst3 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 4: " << (rst4 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 5: " << (rst5 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 6: " << (rst6 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 7: " << (rst7 ? "Matched" : "Not matched") << std::endl;
    std::cout << "Test 8: " << (rst8 ? "Matched" : "Not matched") << std::endl;

    return 0;
}