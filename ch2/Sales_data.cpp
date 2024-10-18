#include "Sales_data.h"
 
int main()
{
    Sales_data data1, data2;

    double price = 0; // 每本书价格
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue  ;

        if (totalCnt != 0)
        {
            cout<<" " << totalRevenue / totalCnt << endl;
        }
        else
            cout << "(no sales)" << endl;

        return 0;
    }
    else
    {
        cerr << " data must refer to the same isbn" << endl;
        return -1;
    }
 
}