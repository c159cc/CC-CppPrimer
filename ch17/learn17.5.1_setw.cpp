#include "../common/cc.h"

int main(){
    int i = -16;
    double d = 3.14159;
    cout<<"i: "<<setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<setw(12)<<d<<"next col"<<'\n';

    //pad the first column and left-justify all columns
    cout<<left
    <<"i: "<<setw(12)<<i<<"next col"<<'\n'
    <<"d: "<<setw(12)<<d<<"next col"<<'\n'
    << right;

    // pad the first column and right-justify all columns
    cout << right
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: "  << d << "next col" << '\n';

    // pad the first column but put the padding internal to the field
    cout<<internal
    << "i: "<<setw(12)<<i<<"next col"<<'\n'
    <<"d: " <<d<<"next col"<<'\n';

    // pad the first column, using # as the pad character
    cout << endl;
    cout << setfill('#')
         << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n'
         << setfill(' ');

    return 0;
}