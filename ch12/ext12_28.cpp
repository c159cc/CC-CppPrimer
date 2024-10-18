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
            // set����������?
            wp[word].insert(lines.size() - 1);
        }
    }

    string s;
    cout << "��������Ҫ��ѯ�ĵ���, q�˳�" << endl;
    while (getline(cin, s))
    {
        if (s == "q")
        {
            break;
        }

        if (wp.find(s) == wp.end())
        {
            cout << "û���ҵ��õ���" << endl;
        }
        else
        {
            auto loc = wp.find(s);
            cout << "����" << s << "������" << loc->second.size() << "��" << endl;
            for (auto num : loc->second)
            {
                cout << "�ڵ�" << num + 1 << "�� " << lines[num] << endl;
            }
        }
    }

    return 0;
}