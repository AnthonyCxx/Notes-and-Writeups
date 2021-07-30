# Working with Date and Time in C++
Although C++ inherits [_\<ctime\>_](https://www.cplusplus.com/reference/ctime/) from C, C++ provides its own library, [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/), with classes for date and time utilities. <br />
All classes from _\<chrono\>_ are a part of the namespace _std::chrono_; for sake of examples, I will only assume you are using namespace _std_.

# Measurements

## _duration_
The _duration_ class is used to store a duration of time (the amount of time between two points in time); these points in time may or may not 
be _time\_point_ objects.

### _duration_ typedefs
There are a set of instantiations of the _duration_ class to represent common units for time like seconds, minutes, and hours. <br />
These instantiations can be used like literals, so you can pass '_10ms_' instead of '_10_' to a function to make it clearer.

You cannot assign an integer to a _duration_ like `chrono::minutes time_waited = 3;` because '_3_' is an ambiguous amount. <br />
You have to write `chrono::minutes time_waited{3}` to indicate that you mean 3 minutes.

| Unit | Ratio |
| ---- | ----- |
| [_chrono::hours_](https://www.cplusplus.com/hours) | 3600/1 |
| [_chrono::minutes_](https://www.cplusplus.com/reference/chrono/minutes/) | 60/1 |
| [_chrono::seconds_](https://www.cplusplus.com/reference/chrono/seconds/) | 1/1 |
| [_chrono::milliseconds_](https://www.cplusplus.com/reference/chrono/milliseconds/) | 1/1000 |
| [_chrono::microseconds_](https://www.cplusplus.com/reference/chrono/microseconds/) | 1/1,000,000 |
| [_chrono::nanoseconds_](https://www.cplusplus.com/reference/chrono/nanoseconds/) | 1/1,000,000,000 |
> All the ratios use _seconds_ as the standard for comparison.

## time_point

# Clocks

## system_clock

## stready_clock

## high_resolution_clock

## Sources
CppCon 2016: [_CppCon 2016: Howard Hinnant “A \<chrono\> Tutorial"_](https://www.youtube.com/watch?v=P32hvk8b13M) <br />
cplusplus.com: [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/) <br />
cppreference.com: [_Date and time utilities: std::chono_](https://en.cppreference.com/w/cpp/chrono) <br />
TheCherno: [_Timing in C++_](https://www.youtube.com/watch?v=oEx5vGNFrLk) <br />
