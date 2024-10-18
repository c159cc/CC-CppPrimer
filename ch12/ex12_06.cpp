#include "../common/cc.h"
using ptr = vector<int>*;
ptr factory()
{ 
    return new vector<int>;
}

void read_vector(ptr p)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p->push_back(x);
    }
}

void print_vector(ptr p)
{
    for(int i = 0; i < p->size(); i++){
        cout << (*p)[i] << " ";
    }
    cout << endl;
}

int main()
{
    ptr p = factory();
    read_vector(p);
    print_vector(p);
    delete p;
    return 0;
}