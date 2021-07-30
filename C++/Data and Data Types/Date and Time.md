# Working with Date and Time in C++
Although C++ inherits [_\<ctime\>_](https://www.cplusplus.com/reference/ctime/) from C, C++ provides its own library, [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/), with classes for date and time utilities. <br />
All classes from _\<chrono\>_ are a part of the namespace _std::chrono_.

# Measurements

## _duration_
The _duration_ class is used to store a duration of time (the amount of time between two points in time).

### _duration_ typedefs
There are a set of instantiations of the _duration_ class to represent common units for time like seconds, minutes, and hours.
| Unit | Ratio |
| ---- | ----- |
| hours | 3600/1 |
| minutes | 60/1 |
| seconds | 1/1 |
| milliseconds | 1/1000 |
| microseconds | 1/1,000,000 |
| nanoseconds | 1/1,000,000,000 |
> All the ratios use _seconds_ as the standard for comparison.

## time_point

# Clocks

## system_clock

## stready_clock

## high_resolution_clock

## Sources
CppCon 2016: [_CppCon 2016: Howard Hinnant “A \<chrono\> Tutorial"_](https://www.youtube.com/watch?v=P32hvk8b13M) <br />
cplusplus.com: [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/) <br />
cppreference.com: [_Date and time utilities: std::chono_](https://en.cppreference.com/w/cpp/chrono/weekday) <br />
TheCherno: [_Timing in C++_](https://www.youtube.com/watch?v=oEx5vGNFrLk) <br />
