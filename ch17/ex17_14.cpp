#include "../common/cc.h"

int main(){

    
  
try{
    regex r("[[:alpha:]+"); 

    bool b = regex_match("hello", r);
}catch(regex_error e){
    cout << e.what() << endl;
    cout<<e.code()<<endl;
}
    

    return 0;
}