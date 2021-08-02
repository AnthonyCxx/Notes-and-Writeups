//How to time to stuff like functions in C++, taken from Howard Hinnant's 'A <chrono> Tutorial'
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    using fpseconds = chrono::duration<double, ratio<1,1>>;   //Floating-point seconds
    chrono::steady_clock::time_point start = chrono::steady_clock::now();  //Start time

    /*
        Work goes here...
    */

    chrono::steady_clock::time_point end = chrono::steady_clock::now();  //End time

    cout << fixed;   //Prevents number being represented in scientific notation
    cout << "Time elapsed: " << chrono::duration_cast<fpseconds>(end - start).count() << '\n';  //Find elapsed time
}
