#include "../common/cc.h"

int main(){

    default_random_engine e;

    for(int i = 0; i < 10; i++){
        cout << e()<< endl;
    }

 

    return 0;
}