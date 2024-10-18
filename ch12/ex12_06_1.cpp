#include "../common/cc.h"

using ptr = shared_ptr<vector<int>>;
ptr factory()
{ 
    return make_shared<vector<int>>();
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
    return 0;
}