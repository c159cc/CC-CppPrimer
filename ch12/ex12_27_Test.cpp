#include "./ex12_27.h"

void runQueries(ifstream &infile){
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile);

   // iterator with the user: prompt for a word to find and print results
    while(true){
        cout<<"enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end of file or if a 'q' is entered
        if(!(cin>>s)||s=="q") break;
        // run the query and print the results
        print(cout, tq.query(s))<<endl;
    } 
}

int main() {

    cout << "helo" << endl;
    ifstream infile("..\\data\\letter.txt");
    runQueries(infile);
    return 0;
}