# Variadic Functions in C++
A variadic function is a function varying [arity](https://en.wikipedia.org/wiki/Arity) (the amount of arguments it can take). Variadic functions allow you to write a single 
function like _add()_ that can take any number of variables, literals, or combination of the two. I could call _add(1, 2)_ or _add(7, 14, 900)_ and it would work all the same.

Though the implementation differs, all methods of creating variadic functions use an elipsis ('...', called the parameter pack) to represent the arguments passed
to the function as a list. Other languages also work the way way; C# uses the [_params_](https://www.c-sharpcorner.com/UploadFile/c63ec5/use-params-keyword-in-C-Sharp/) keyword
to pass the list of arguments as an array and Python uses [_\*args_ and \*kwargs](https://www.geeksforgeeks.org/args-kwargs-python/) to pass the arguments as a list.

## Variadic Templates (C++11)
Variadic templates are templates that can instantiate functions of both varying types _and_ varying parameters. The only catch is that these functions are recursive because
they start with however many elements the give function has and perform the body of the function on each element one by one until they reach no elements, at which point 
the base case is called. A function _add(1, 2, 3)_ would run _add(1, 2, 3)_, then _add(2, 3)_, and then _add(3)_ (the base case, which just returns '_3_').

```C++
#include <iostream>
using namespace std;

//Base case
template <typename T>
T sum(T num)
{
    return num;
}

//Variadic Template
template <typename T, typename... Args>
T sum(T num, Args... args)
{
    //Takes the first number and calls 'sum()' again, calling with 1 less item
    return num + sum(args...);
}

int main()
{
    cout << "1 + 2 = " << sum(1, 2) << '\n';

    cout << "7 + 14 + 900 = " << sum(7, 14, 900) << '\n';

    return 0;
}
```

## Fold Expressions (C++17)
C++17 added a cleaner, non-recursive way to write variadic functions: fold expressions.
[https://www.youtube.com/watch?v=nhk8pF_SlTk](https://www.youtube.com/watch?v=nhk8pF_SlTk) <br />

## C-Style Variadic Functions
Don't use this in C++, it's not type-safe and if you aren't careful, you'll get a segmentation fault.

## Sources
Microsoft C++ Documentation: [_Ellipsis and Variadic Templates_](https://docs.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-160) <br />
Modernes C++: [_C++ Insights - Variadic Templates_](https://www.modernescpp.com/index.php/c-insights-variadic-templates) <br />
Eli Bendersky's Blog: [_Variadic templates in C++_](https://eli.thegreenplace.net/2014/variadic-templates-in-c/) <br />
Kevin Ushey's Blog: [_Intro to C++ Variadic Templates_](https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/) <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
