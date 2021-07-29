/*
    Credit for time functions: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
*/

#include <iostream>
#include <iomanip>        //I/O formatting
#include <functional>    //Contains the 'function' class
#include <chrono>       //Contains time funtions
using namespace std;

//Function wrapper 'time' times how long it takes a void function with no parameters to run
void time(function<void()> func)   //'function' is a class in the <functional> header file
{
    //Mark the beginning and end time of the function
    auto start = chrono::system_clock::now();
    func();
    auto end = chrono::system_clock::now();

    //Translate the start and end time into a
    chrono::duration<double> time_elapsed = end - start;

    cout << "Done! " << setprecision(2) << time_elapsed.count() << " seconds elapsed.\n";
}

//Print the numbers 1-100, but format them (zero-padded to 3 digits)
void print100()
{   
    //Set stream flag
    cout  << setfill('0');
    
    //Print 0-100, zero-padded to 3 chars
    for(int i=1; i < 101; i++)
    {
        cout << setw(3) << i << '\n';
    }
}

// DRIVER CODE //
int main()
{
    //Time how long it takes to print the numbers 1-100
    time(print100);

    return 0;
}
