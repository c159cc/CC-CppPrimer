#include "./Sales_data h"
double Sales_data::avg_price() const
{
  if (units_sold)
  {
    return revenue / units_sold;
  }
  else
    return 0;
}

istream &operator>>(istream &is, Sales_data &item)
{
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  if (is)
    item.revenue = item.units_sold * price;
  else
    item = Sales_data();
  return is;
}

ostream &operator<<(ostream &os, Sales_data &item)
{
  os << "ISBN: " << item.bookNo << " # sold: " << item.units_sold << " revenue: " << item.revenue << endl;
  return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.units_sold += rhs.units_sold;
  sum.revenue += rhs.revenue;
  return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
 Sales_data temp = *this;
 *this = temp + rhs;
 return *this;
}

// Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
// {
//   Sales_data sum = lhs;
//   sum += rhs;
//   return sum;
// }

// Sales_data &Sales_data::operator+=(const Sales_data &rhs)
// {
//   if (bookNo == rhs.bookNo)
//   {
//     units_sold += rhs.units_sold;
//     revenue += rhs.revenue;
//   }
//   return *this;
// }

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
  return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
  return !(lhs == rhs);
}

int main()
{

  // Sales_data data1, data2;
  // double price = 0.0;
  // std::cin>>data1.bookNo>>data1.units_sold>>price;
  // data1.revenue = data1.units_sold * price;

  // cin>>data2.bookNo>>data2.units_sold>>price;
  // data2.revenue = data2.units_sold * price;

  // if(data1.bookNo == data2.bookNo){
  //   unsigned totalCnt = data1.units_sold + data2.units_sold;
  //   double totalRevenue = data1.revenue + data2.revenue;
  //   cout<<data1.bookNo<<" "<<totalCnt<<" "<<totalRevenue<<endl;

  //   if(totalCnt!= 0)
  //     cout<<"Average price: "<<totalRevenue/totalCnt<<endl;
  //     else
  //       cout << "(no sales)" << endl;
  // }else{
  //   cerr<<"Data must refer to the same book"<<endl;
  //   return -1;
  // }

  // Sales_data total;
  // if(read(cin,total)){
  //   Sales_data trans;
  //   while(read(cin,trans)){
  //     if(total.isbn()==trans.isbn()){
  //       total.combine(trans);
  //     }else{
  //       print(cout, total) << endl;
  //       total = trans;
  //     }
  //   }
  //   print(cout, total) << endl;
  // }else{
  //   cerr << "No data?!" << endl;
  // }

  Sales_data total;
  if (cin >> total)
  {
    Sales_data trans;
    while (cin >> trans)
    {
      if (total.isbn() == trans.isbn())
      {
        total += trans;
      }
      else
      {
        cout << total << endl;
        total = trans;
      }
    }
    cout << total << endl;
  }
  else
  {
    cerr << "No data?!" << endl;
  }

  return 0;
}