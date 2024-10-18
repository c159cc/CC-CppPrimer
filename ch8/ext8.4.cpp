#include "../common/cc.h"

// 读取文件存放在vector容器中
int main()
{
  const char *filename = "G:\\temp\\test.js";

  ifstream infile(filename);
  if (!infile)
  {
    cout << "打开文件失败" << endl;
    return 1;
  }
  infile.imbue(locale("zh_CN.UTF-8"));
  vector<string> lines;
  string line;
  while (getline(infile, line))
  {
    lines.push_back(line);
  }

  infile.close();

  for(auto &s:lines){
    cout << s << endl;
  }
  cout << lines.size() << endl;
  return 0;
}