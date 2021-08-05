# Variadic Functions in C++
A variadic function is a function varying [arity](https://en.wikipedia.org/wiki/Arity) (the amount of arguments it can take). Variadic functions allow you to write a single 
function like _add()_ that can take any number of variables, literals, or combination of the two. I could call _add(1, 2)_ or _add(7, 14, 900)_ and it would work all the same.

Though the implementation differs, all methods of creating variadic functions use an elipsis ('...', called the parameter pack) to represent the arguments passed
to the function as a list. Other languages also work the way way; C# uses the [_params_](https://www.c-sharpcorner.com/UploadFile/c63ec5/use-params-keyword-in-C-Sharp/) keyword
to pass the list of arguments as an array and Python uses [_\*args_ and \*kwargs](https://www.geeksforgeeks.org/args-kwargs-python/) to pass the arguments as a list.
When the elipsis ('...') is placed on the left side of a type (`...Args`), it indicates that there is a parameter pack; when placed on the right side of a type (`args...`), 
it expands into the parameter pack. Use `...Args` to declare a parameter pack and `args...` to use one.

## Variadic Templates (C++11)
Variadic templates are templates that can instantiate functions of both varying types _and_ varying parameters. These functions are 'recursive' (but not really) because
they start with however many elements the give function has and perform the body of the function on each element one by one until they reach no elements, at which point 
the base case is called. A function _add(1, 2, 3)_ would run _add(1, 2, 3)_, then _add(2, 3)_, and then _add(3)_ (the base case, which just returns '_3_'). Interestingly
enough, variadic templates involve no actual recursion since the compiler creates the functions with the appropriate amount of arguments for each call, so it's only 
calling another function (even though it looks recursive). Because of this, variadic templates do not inherit the performance problems that recursive functions have.

Like the typename '_T_', there is nothing special about the typename '_Args_' (which is short for 'arguments'), you can change it to anything — it's just the typename
of the parameter pack.

Example 1: a variadic _sum()_ function
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
template <typename T, typename ...Args>
T sum(T num, Args ...args)
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

Example 2: a variadic _print()_ function
```C++
#include <iostream>
using namespace std;

//Base Case
template <typename T>
void print(const T& str)
{
    //Base case adds the final '\n'
    cout << str << '\n';
}

//Variadic Print Function
template <typename T, typename ...Args>
void print(const T& str, Args... args)
{
    //Print a string
    cout << str << ' ';  //Add a space (to separate strings)

    //Print the rest of the strings...
    print(args...);
}

int main()
{
    print("This function", "will", "print", "any number of", "strings.");  //or anything else you give it, like '10'

    return 0;
}
```

## Fold Expressions (C++17)
C++17 added a cleaner, more straight-forward way to write variadic functions: fold expressions. Fold expressions allow you to write a single function that contains an
expression that is applied to the parameter pack. Once expanded, the expression will be applied to every member of the paramter pack. This does make the exact
placement of the parameter pack a little more tricky and the code a little more difficult to write, so you'll have to look at a few examples before you really get it.

Example 1: a variadic _sum()_ function
```C++
// C++17: COMPILE WITH 'g++ -std=c++17 file.cpp  //
#include <iostream>
using namespace std;


template <typename ...T>  //'...' on the left for declarations
auto sum(T... num)       //Return type cannot be 'T' since it's a parameter pack...
{
    return (num + ...);     //Apply 'num +' to all elements: 'num1 + num2 + num3...'
}

int main()
{
    cout << "8 + 49 + 72 = " << sum(8, 49, 72) << '\n';
    cout << "7.2 + 3513 = " << sum(7.2, 3513) << '\n';

    return 0;
}
```
> Reference: [_auto_](https://www.geeksforgeeks.org/return-type-deduction-in-c14-with-examples/) return type

Example 2: a variadic _print()_ function
```C++

```
[https://sodocumentation.net/cplusplus/topic/2676/fold-expressions](https://sodocumentation.net/cplusplus/topic/2676/fold-expressions)

## C-Style Variadic Functions
C++ has access to C-style variadic functions through the [_\<cstdarg\>_](https://www.cplusplus.com/reference/cstdarg/) library. <br />
Honestly though, don't use it in C++; it's not type-safe and if you aren't careful, you'll get a segmentation fault.

## Sources
Microsoft C++ Documentation: [_Ellipsis and Variadic Templates_](https://docs.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-160) <br />
Modernes C++: [_C++ Insights - Variadic Templates_](https://www.modernescpp.com/index.php/c-insights-variadic-templates) <br />
Eli Bendersky's Blog: [_Variadic templates in C++_](https://eli.thegreenplace.net/2014/variadic-templates-in-c/) <br />
Kevin Ushey's Blog: [_Intro to C++ Variadic Templates_](https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/) <br />
C++ Weekly With Jason Turner: [_C++ Weekly - Ep 20 C++17's Fold Expressions - Introduction_](https://www.youtube.com/watch?v=nhk8pF_SlTk) <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
