//How to time to stuff like functions in C++, taken from Howard Hinnant's 'A ＜chrono> Tutorial'
#include <chrono>
using namespace std::chrono;

//Get start time
auto start = steady_clock::now();

/*
  WORK GOES HERE
*/

//Get end time
auto end = steady_clock::now();

//Output total time between time_point objects
cout << duration_cast<seconds>(end - start).count() << "seconds\n";
