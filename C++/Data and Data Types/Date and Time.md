# Working with Date and Time in C++
Although C++ inherits [_\<ctime\>_](https://www.cplusplus.com/reference/ctime/) from C, C++ provides its own library, [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/), with classes for date and time utilities. <br />
All classes from _\<chrono\>_ are a part of the namespace _std::chrono_; for sake of examples, I will only assume you are using namespace _std_. <br />
Feel free to remove the _chrono::_ from everything you see if you are using the namespace _std::chrono_.

The majority of this document has been constructed from the talk [_A \<chrono\> Tutorial_](https://www.youtube.com/watch?v=P32hvk8b13M) by [Howard Hinnant](https://github.com/HowardHinnant), who is recognized as a master C++ programmer and invented move semantics.  All credit to him.

# Basics of Keeping Time with the _duration_ and _time\_point_ Classes

# The _duration_ Class
The _duration_ class is used to store a duration of time (the amount of time between two points in time); these points in time may or may not 
be _time\_point_ objects.

| Method | Type | Description | 
| ------ | ---- | ----------- | 
| [_.count()_](https://www.cplusplus.com/reference/chrono/duration/count/) | Instance | returns the count (value/the time) of a _duration_ object | 
| [_::zero()_](https://www.cplusplus.com/reference/chrono/duration/zero/) | Static | returns a _duration_ object with the value 0 | 
| [_::min()_](https://www.cplusplus.com/reference/chrono/duration/min/) | Static | returns a _duration_ object with the minimum possbile value | 
| [_::max()_](https://www.cplusplus.com/reference/chrono/duration/max/) | Static | returns a _duration_ object with the maximum possbile value | 

## _duration_ typedefs
There are a set of instantiations of the _duration_ class to represent common units for time like seconds, minutes, and hours. <br />
These instantiations can be used like any other datatype, so you can make _milliseconds_ the datatype for a function parameter; this forces you to
pass '_10ms_' instead of just '_10_', which is much clearer.

| Unit | Literal Suffix | Ratio |
| ---- | -------------- | ----- |
| [_chrono::hours_](https://www.cplusplus.com/hours) | h | 3600/1 |
| [_chrono::minutes_](https://www.cplusplus.com/reference/chrono/minutes/) | min | 60/1 |
| [_chrono::seconds_](https://www.cplusplus.com/reference/chrono/seconds/) | s | 1/1 |
| [_chrono::milliseconds_](https://www.cplusplus.com/reference/chrono/milliseconds/) | ms | 1/1000 |
| [_chrono::microseconds_](https://www.cplusplus.com/reference/chrono/microseconds/) | us | 1/1,000,000 |
| [_chrono::nanoseconds_](https://www.cplusplus.com/reference/chrono/nanoseconds/) | ns | 1/1,000,000,000 |
> All the ratios use _seconds_ as the standard for comparison.

## Initializing a _duration_
You cannot assign an integer to a _duration_ like `chrono::minutes time_waited = 3;` because '_3_' is an ambiguous amount. <br />
You have to write `chrono::minutes time_waited{3}` or `chrono::minutes time_waited = 3min` to indicate that you mean 3 minutes. <br />

## Casting with _duration\_cast\<T\>_
You can store a larger unit in a variable of a smaller unit (e.g. _hours_ in a variable of type _seconds_) without typecasting, but you cannot
store a smaller unit in a variable of a larger type unless you typecast as the larger datatype may [truncate](https://techterms.com/definition/truncate)
a portion of that data since it cannot be wholly represented. To 'type-cast' the time, use the [_duration\_cast\<T\>_](https://en.cppreference.com/w/cpp/chrono/duration/duration_cast) function.

For example, the line `chrono::hours h = 72min;` will not compile because 72 minutes cannot be represented in a whole hour (as 72 minutes is 1 hours and 12 minutes).
By typecasting, we force program to truncate the extra twelve minutes and store the 72 minutes as 1 hour: `chrono::hours h = chrono::duration_cast<chrono::hours>(72min);`.

## Getting the Value of a _duration_
`cout << time_waited;` does not work. You have to access the amount of time by using the _.count()_ method. <br />
For example `cout << time_waited.count()` would work. However, adding two variables of type _seconds_ and assigning
it to a new _seconds_ variable is fine without using _.count()_.

## Mixed-mode Arithmetic
Doing math with variables of different units (e.g. _hours_ and _nanoseconds_) works just fine. <br />
The result will be returned in the smallest unit of the expression (in this case, nanoseconds).

## Creating Custom Durations
The _duration_ class is a template that can be used to create custom units of time. In the talk, Dr. Hinnant uses the example of a game developer trying to measure
60 frames a second, using the custom type '_frames_' as `using frames = duration<int32_t, ratio<1,60>>` such that a _frame_ is ~16.667 milliseconds.

| Custom Duration | Declaration |
| --------------- | ----------- |
| Day | `using days = duration<int, ratio_multiply<ratio<24>, hours::period>>;` |
| Week | `using weeks = duration<int, ratio_multiply<ratio<7>, days::period>>` |
> '_using days = duration<int, ratio<86400>>;_' also works since there are 86400 seconds in a day

# The _time\_point_ Class
| Method | Type | Description | 
| ------ | ---- | ----------- | 
| [_.time_since_epoch()_](https://www.cplusplus.com/reference/chrono/time_point/time_since_epoch/) | Instance | returns a _duration_ object containing the time between the _time\_point_ object and the [epoch](https://en.wikipedia.org/wiki/Unix_time) |
| [_::min()_](https://www.cplusplus.com/reference/chrono/time_point/min/) | Static | returns a _time\_point_ object with the minimum possible value |
| [_::max()_](https://www.cplusplus.com/reference/chrono/time_point/max/) | Static | returns a _time\_point_ object with the maximum possible value |

## Time Point Arithmetic 
You can subtract two _time\_point_ objects, but not add them.

## Casting with _time\_point\_cast_
You can type-cast a _time\_point_ to a different type (e.g. from _seconds_ to _minutes_)

# Basics of Getting Time with _clock_ Classes
Clocks are not interoperable; you cannot assign a timepoint of type _chrono::system\_clock::time\_point_ to a variable of _chrono::steady\_clock::time\_point_.

# The _system\_clock_ Class
Use _system\_clock_ when you need times that relate to a calendar.

| Method | Type | Description | 
| ------ | ---- | ----------- | 
| [_::now()_](https://www.cplusplus.com/reference/chrono/system_clock/now/) | Static | returns the current value of the _time\_point_ of _system\_clock_ |
| [_::to\_time\_t()_](https://www.cplusplus.com/reference/chrono/system_clock/to_time_t/) | Static |  |
| [_::from\_time\_t()_](https://www.cplusplus.com/reference/chrono/system_clock/from_time_t/) | Static |  |

# The _stready\_clock_ Class
Use _steady\_clock_ when you need to measure _time\_point_ — think of it like a stopwatch. <br />
_steady\_clock_ has no relationship to any calendar, so you cannot use it for dates.

| Method | Type | Description | 
| ------ | ---- | ----------- | 
|  |  |  |
|  |  |  |

# The _high\_resolution\_clock_ Class
| Method | Type | Description | 
| ------ | ---- | ----------- | 
|  |  |  |
|  |  |  |

## Sources
CppCon 2016: [_CppCon 2016: Howard Hinnant “A \<chrono\> Tutorial"_](https://www.youtube.com/watch?v=P32hvk8b13M) <br />
cplusplus.com: [_\<chrono\>_](https://www.cplusplus.com/reference/chrono/) <br />
cppreference.com: [_Date and time utilities: std::chono_](https://en.cppreference.com/w/cpp/chrono) <br />
TheCherno: [_Timing in C++_](https://www.youtube.com/watch?v=oEx5vGNFrLk) <br />
