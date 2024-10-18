#include "../common/cc.h"
#include <cctype>

int main()
{
    using sz = vector<string>::size_type;
    map<string, set<sz>> word_map;
    vector<string> lines;
    set<sz> word_set;
    string text, word;
    sz lineNo = 0;

    ifstream infile("../data/letter2.txt");
    string line;
    while (getline(infile, line)){
        istringstream iss(line);
        while (iss >> text)
        {
            // std::remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
            // std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), std::ispunct);
            word_map[text].insert(lineNo);
        }

        ++lineNo;
        lines.push_back(line);
    }

    do{
        cout<<"Enter a word to search for (or q to quit): "<<endl;
        if(!(cin>>text) || text == "q"){
            break;
        }

        auto mit = word_map.find(text);
        if(mit == word_map.end()){
            cout<<"The word \""<<text<<"\" was not found in the text."<<endl;
        }else{
            cout << "The word \"" << text << "\" occurs "<< mit->second.size() << " times in the text:" << endl;
            for(sz i : mit->second){
                cout << "line"<<i+1<<": " << lines[i] << endl;
            }
        }
    } while (true);

    return 0;
}