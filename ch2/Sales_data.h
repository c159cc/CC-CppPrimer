#include "../common/cc.h"

#ifndef SALES_DATA_H
#define SALES_DATA_H
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0; // 数量
    double revenue = 0.0; // 收入
}; // 这里的封号是必须的, 因为可以在class body后面定义变量
#endif  
 