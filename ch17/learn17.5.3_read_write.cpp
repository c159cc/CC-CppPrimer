#include "../common/cc.h"

/**
 *
// 读取文件, 内容如下, 统计每行字符数量
abcd
efg
hi
j

abcd
efg
hi
j
5 9 12 14
*/
int main()
{
     // 2024年4月30日10:48:42
     const char *path = "f://cc//out1.txt";
     // 打开文件, 读+写+指针到末尾
     // 两个点: 1, 使用fstream
     /// 2, in,out,ate 在fstream中
     fstream inOut(path, fstream::ate| fstream::in | fstream::out );

     if (!inOut)
     {
          // 使用了cerr, 使用了EXIT_FAILURE
          cerr << "打开文件失败" << endl;
          return EXIT_FAILURE;
     }

     // // 记下末尾的位置, 回到头部开始读取, 读取完成后回到末尾记录count
     // auto end_mark = inOut.tellg(); //
     // inOut.seekg(0, fstream::beg); // 回到头部
     // string line;
     // size_t cnt = 0;
     // while(inOut && inOut.tellg() != end_mark && getline(inOut, line)){
     //      cnt += line.size() + 1;
     //      auto mark = inOut.tellg();
     //      inOut.seekp(0, fstream::end); // 回到末
     //      inOut << cnt ;
     //      if(mark!=end_mark){
     //           inOut << " ";
     //      }
     //      inOut.seekg(mark);
     //      cout << line << endl;
     // }

     // inOut.seekp(0, fstream::end);
     // inOut << "\n";


     // 书本参考方案
     // inOut is opened in ate mode, so it starts out positioned at the end
     auto end_mark = inOut.tellg(); // remember original end-of-file

     inOut.seekg(0, fstream::beg); // reposition to the start of the file
     size_t cnt = 0;               // accumulator for the byte count
     string line;                  // hold each line of input
     // while we haven't hit an error and are still reading the original data
     while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
     { // and can get another line of

          cnt += line.size() + 1;       // add 1 to account for the
          auto mark = inOut.tellg();    // remember the read position
          inOut.seekp(0, fstream::end); // set the write marker to the

          inOut << cnt; // write the accumulated length
          // print a separator if this is not the last line
          if (mark != end_mark)
               inOut << " ";
          inOut.seekg(mark); // restore the read position 
     }
     inOut.seekp(0, fstream::end); // seek to the end
     inOut << "\n";

     return 0;
}