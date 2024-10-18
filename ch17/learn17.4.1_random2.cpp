#include "../common/cc.h"

int main(){

    long long *p = NULL;
    cout << time(p) << endl;
    // 异常
    // cout << *p << endl;
    // default_random_engine e(*p);

    default_random_engine e(time(0));

    for(int i = 0; i < 10; i++){
        cout << e()<< endl;
    }

 

    uniform_real_distribution<> d(0.0, 1.0);
    cout<<d(e)<<endl;
    return 0;
}