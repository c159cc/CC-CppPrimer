#include "ex12_27_1.h"

void runQueries(ifstream &is)
{
    TextQuery tq(is);

    while (true)
    {
        cout << "enter word to look for, or q to quit:" << endl; // 这里需要endl
        string word;
        if (!(cin >> word) || word == "q")
            break;
        print(cout, tq.query(word)) << endl;
    }
}

void customTerminate()
{
    try
    {
        std::exception_ptr eptr{std::current_exception()};
        if (eptr)
        {
            std::rethrow_exception(eptr);
        }
        else
        {
            std::cerr << "Exiting without exception\n"; // 直接调用terminate会进入这个分支
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught\n";
    }
    std::exit(EXIT_FAILURE);
}

int main()
{

    std::set_terminate(customTerminate);
    ifstream infile("..\\data\\letter2.txt");
    runQueries(infile);
    return 0;
}
