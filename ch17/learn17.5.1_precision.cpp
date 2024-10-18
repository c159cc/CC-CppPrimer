#include "../common/cc.h"

int main(){
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
    cout.precision(12);
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;
    cout << setprecision(3);
    cout << "Precision: " << cout.precision() << ", Value: " << sqrt(2.0) << endl;

    return 0;
}