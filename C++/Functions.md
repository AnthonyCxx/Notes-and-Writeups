# Functions in C++
A function is a block of code that can be called upon by name, executing it. A function declaration requires a return type, the name of the function, and a list of the
parameters that it takes. For now, only worry about the name, since we'll be using void functions.

```C++
#include <iostream>
using namespace std;

//Definition of a function 'printHello' with no return type (void) or parameters
void printHello()
{
    cout << "Hello, world!" << '\n';
}

int main()
{
    //Calling function 'printHello'
    printHello();

    return 0;
}
```

## The _return_ Keyword and Return Types
Functions can return a value to wherever it was called. The return keyword returns that value, which could be a literal, a variable, an expression, or even a 
data structure (an array, tuple, map, etc.). Once the return statement is executed, the function ends, regardless of whether there was code after the return statement. 
Any good compiler should warn you that the code after the return statement is 'dead code' (code that cannot and will not be executed). The datatype of the value that 
will be returned must be declared as a part of the function declaration (just before the name). Here, the return5() method returns an integer, 5. 
If a method does not return any value, then its return type is void.

```C++
#include <iostream>
using namespace std;

/*
    A function 'return5' that returns the integer 5
    to where it was called
*/
int return5()
{
    return 5;
}

int main()
{
    int number = return5();

    cout << "The number returned by function 'return5' is: " << number << '\n';

    return 0;
}
```

## Parameters
Functions can take [parameters](https://www.thoughtco.com/definition-of-parameters-958124) (sometimes called arguments). The function can then use these 
values as variables. When declaring parameters, be sure to declare their type as well. A simple method '_add_' could take two numbers as parameters and return their sum.
Parameters should be declared as a part of the parameters list (inside the parentheses following the function name) and should be prefaced by their datatype. If you have
multiple parameters, they should be comma-separated.

```C++
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "5 + 5 = " << add(5, 5) << '\n';
}
```
## Default Parameters
In the event that a method is called without some or all parameters, measures can be put into place to ensure that each parameter still has some default value.
To add default parameters, simple put an equals sign followed by a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) 
(some value). That way, the parameter will take on that value if and only if no other value is provided.

```C++
#include <iostream>
using namespace std;

/*
    Function 'add' adds two integers.
    If a value is not supplied, it is
    assumed to be 0.
*/
int add(int a = 0, int b = 0)
{
    return a + b;
}

int main()
{
    cout << "Calling 'add(5, 5)': " << add(5, 5) << '\n';               // a = 5, b = 5
    cout << "Calling 'add(7)' (one parameter): " << add(7) << '\n';    //  a = 7, b = 0
    cout << "Calling 'add()' (no parameters): " << add() << '\n';     //   a = 0, b = 0
}
```

## Implicit Parameter Type Conversion
Compatible types such as _int_, _float_, and _double_ or _char*_ and _string_ can be [implcitly converted](https://www.ibm.com/docs/en/zos/2.1.0?topic=resolution-implicit-conversion-sequences)
when provided as a parameter for a function. If you have a function that takes an integer as a parameter, but you pass it a float (let's say 13.75), it will automatically
convert the float 13.75 into the integer 13 by [truncating](https://techterms.com/definition/truncate) it. The same goes for return types. If you return a double 56.88
and catch it in an integer, then the integer will contain 56 because it will type-cast 56.88 into 58 before storing it.

Because of this, I recommend all math-related functions you write to both use and return doubles, as you can always type-cast to a less specific type (double to float, 
double to int), but you cannot type-cast to a more specific type (float to double) without losing some or all of the characteristics of the more specific datatype
(in this case, some or all of the decimal places).

```C++
#include <iostream>
using namespace std;

/*
    A simple add function.
    If the arguments passed ('a' and 'b') are not doubles,
    then they will be type-casted to doubles before being added.
    If the result is not caught by a double, then the result will
    be type-casted to the appropriate datatype.

    Essentially, by using the most-specific datatype (i.e. doubles), we can
    guarantee that we have an accurate and valid result for any datatype since we
    can always type-cast downwards to less specific type if needed (e.g. int).
*/
double add(double a, double b)
{
    return a + b;
}

int main()
{
    int intA = 10, intB = 20;                 //Sum = 30
    double doubleA = 15.5, doubleB = 16.7;   //Sum = 32.2

    //int + int
    int intResult = add(intA, intB);                //Stores the result as an integer
    cout << "10 + 20 stored as an integer is: " << intResult << '\n';  //Result = 30

    //double + double
    double doubleResult = add(doubleA, doubleB);   //Stores the result as a double
    cout << "15.5 + 16.5 stored as a double is: " << doubleResult << '\n';  //Result = 32.2

    //int + double
    int mixedResult = add(intA, doubleA);         //Stores the result as an integer (type-casted down from a double)
    cout << "10 + 15.5 stored as an integer is: " << mixedResult << '\n';  //Result = 25

    return 0;
}
```
> References: [_LearnToProgram: Type Compatibility_](http://learntoprogramming.com/type-compatibility) and [_cplusplus.com: Type Conversions_](https://www.cplusplus.com/doc/tutorial/typecasting/) 

## Function Overloading
C++ is an object-oriented language, so it supports [polymorphism](https://www.geeksforgeeks.org/polymorphism-in-c/). One of the major ways C++ support the object-oriented
programming paradigm is through function overloading (the others being operator overloading and virtual functions). Function overloading allows two functions to share
the same name and yet remain entirely distinct; the way the compiler can differentiate between functions is by the amount of parameters and/or their type, so you cannot
having two different functions that only differ in return type will not work ([reference](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm#:~:text=Function%20Overloading%20in%20C%2B%2B,differ%20only%20by%20return%20type.)).

In this example, you have two different add functions, one of integers, and one for doubles. In actual practice, this would be best achieved by [templates](https://www.tutorialspoint.com/cplusplus/cpp_templates.htm), but you haven't learned those yet.

```C++
#include <iostream>
using namespace std;

//'add' function for integers
int add(int a = 0, int b = 0)
{
    return a + b;
}

//'add' funtion for doubles
double add(double a = 0, double b = 0)
{
    return a + b;
}

int main()
{
    //Calls two separate functions
    cout << "Calling the 'add' function for integers: " << add(1, 12) << '\n';
    cout << "Calling the 'add' function for double: " << add(3.5, 7.9) << '\n';
}
```

## Improving Performance with _inline_
The _inline_ keyword can be used to insert the actual body of the code into the program wherever the function is called — this can help increase efficiency by
preventing [function overhead](https://stackoverflow.com/questions/144993/how-much-overhead-is-there-in-calling-a-function-in-c). Furthermore "Functions expanded 
inline are subject to code optimizations not available to normal functions." 
([quote](https://docs.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-160#inline-__inline-and-__forceinline); note this is the Microsoft C++ compiler).
Keep in mind that just because you mark a function as _inline_ does not mean that it will be inlined — your compiler treats it more as a suggestion, really.
If you _must_ inline a function for whatever reason, you can use compiler-specific techniques like GCC's `__attribute__((always_inline))` ([source](https://www.keil.com/support/man/docs/armcc/armcc_chr1359124974010.htm)).

```C++
#include <iostream>
using namespace std;

inline int absurdMath(int a, int b)
{
    return a * b + 2 / 15;
}

int main()
{
    //'absurdMath()' is inlined, so 'absurdMath(157, 31135)' is directly replaced by '157 * 31135 + 2 / 15'
    cout << "The result of this absurd math is: " << absurdMath(157, 31135) << '\n';

    return 0;
}
```
> Sources: <br />
> cplusplus.com: [_What is C++ inline functions_](https://www.cplusplus.com/articles/2LywvCM9/) <br />
> Microsoft C++ Documentation: [_Inline Functions (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-160) <br />
> GeeksforGeeks: [_Inline Functions in C++_](https://www.geeksforgeeks.org/inline-functions-cpp/) <br />
> StackOverflow: [_Do compilers always ignore inline hints?_](https://stackoverflow.com/questions/32047466/do-c11-compatible-compilers-always-ignore-inline-hints) <br />

## Improving Performance with _constexpr_
A constant expression (marked by the _constexpr_ keyword) indicates that the function can be evaluated at compile time and can be substituted with the result of the function
to increase performance at runtime. For a function to be a valid constant expression, it must be exceedingly simple, like a function with no more than one return statement
or a constructor with just an [initializer list](https://www.educative.io/edpresso/what-are-initializer-lists-in-cpp). Constant expressions cannot be virtual or a coroutine,
must return a literal type (i.e. not a user-defined type like a class), and cannot contain a whole slew of things, including but not limited to: a _try_/_catch_ block, 
any uninitialized variables, or variables that aren't literal types. If a constant expression contains any of these things, the _constexpr_ keyword will be ignored.

```C++
#include <iostream>
using namespace std;

constexpr int absurdMath(int a, int b)
{
    return a * b + 2 / 15;
}

int main()
{
    /*
       'absurdMath()' is a constant expression, so 'absurdMath(157, 31135)' is replaced
       by the result of '157 * 31135 + 2 / 15', which is 4,888,195
    */
    cout << "The result of this absurd math is: " << absurdMath(157, 31135) << '\n';

    return 0;
}
```
> Sources: <br />
> Youtuber CPP Nuts: [_constexpr C++ | C++11_](https://www.youtube.com/watch?v=frifFlPO_uI) <br />
> CPPReference.com: [_constexpr specifier (since C++11)_](https://en.cppreference.com/w/cpp/language/constexpr) <br />
> Microsoft C++ Documentation: [_constexpr (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-160) <br />
> GeeksforGeeks: [_Understanding constexpr specifier in C++_](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/) <br />
> StackOverflow: [_Difference between _constexpr_ and _const__](https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const) <br />
