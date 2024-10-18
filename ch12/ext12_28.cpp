#include "../common/cc.h"

int main()
{
    using line_no = vector<string>::size_type;
    vector<string> lines;
    map<string, set<line_no>> wp;

    ifstream infile("..\\data\\letter.txt");
    string line;
    while (getline(infile, line))
    {
        lines.push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            // set从哪里来的?
            wp[word].insert(lines.size() - 1);
        }
    }

    string s;
    cout << "请输入需要查询的单词, q退出" << endl;
    while (getline(cin, s))
    {
        if (s == "q")
        {
            break;
        }

        if (wp.find(s) == wp.end())
        {
            cout << "没有找到该单词" << endl;
        }
        else
        {
            auto loc = wp.find(s);
            cout << "单词" << s << "出现了" << loc->second.size() << "次" << endl;
            for (auto num : loc->second)
            {
                cout << "在第" << num + 1 << "行 " << lines[num] << endl;
            }
        }
    }

    return 0;
}