#include "../common/cc.h"

int main(){

    string file = "receipt freind theif receive";
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase); // 忽略大小写
    for(sregex_iterator it(file.begin(), file.end(), r), end_it; it!=end_it; ++it)
      {
        // 第二次长度不够会报错
          cout << it->prefix().str().substr(it->prefix().str().size() - 3, it->prefix().str().size()) << it->str() << it->suffix().str().substr(0,3) << endl;
        //   cout << it->prefix().str() << endl;
        //   cout << it->suffix().str() << endl;
          cout << it->length() << endl;
      }

    return 0;
}