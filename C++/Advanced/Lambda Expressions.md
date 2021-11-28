# Lambda Expressions in C++
A lambda expression is a [functor](https://www.geeksforgeeks.org/functors-in-cpp/), a class with an overloaded _()_ operator such that it can be called like a function.
Lambda expressions are good for writing one-time functions that you don't want to dedicate an entire function to or for defining a function within another function. Lambda
expressions can be bound to a variable (usually of type [_auto_](https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/)) or can be defined in a parameter being
passed to a function (hence why they're so good as one-time functions). Like functions, lambda expressions are composed of a parameter list, a return type, and a function
body; however, return types are optional for lambdas and they also have a [capture clause](https://www.learncpp.com/cpp-tutorial/lambda-captures/) that can give them access 
to variables within the same scope.

If you _really_ want to declare the datatype of a lambda variable, it's technically a [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) object.

## Lambda Expression Format
```C++
//Format
[]() -> return_type {}

/*
//Explanation
[] : the capture clause
() : the parameter list
-> return_type : the return type of the function (optional)
{} : the body of the function
*/

//Example (notice the ';' at the end of the lambda, only needed for declarations)
auto isLowercase = [](char letter) -> bool { return letter >= 97 && letter <= 122; };

if (isLowercase('a'))  //Use the lambda like a function
    cout << "The letter 'a' is lowercase\n";
```

## Capture Clauses
Capture clauses, `[ ]`, allow you to use nearby variables (including functors) in a lambda expressions. Captured variables are passed by value unless
explicitly denoted by a `&`. You can capture any amount of variables, capturing some by reference and others by value – all you have to do is separate them
with a comma. If you want to capture all local variables by assignment or reference, write a single `[&]` or `[=]` respectively.

```C++
int i = 2;
auto lessThanI = [i](const int x) -> bool {return x < i;}; 

if (lessThanI(-2))  //True
    std::cout << "the number -2 is less than the local variable \'i\'...\n";
```
> The lambda _lessThanI_ captures the local variable 'i' by value.

## Using Lambdas as Function Parameter
A function can take another function as a paramter. This is common for many functions in the [_\<algorithm\>_](https://www.cplusplus.com/reference/algorithm/) library.
Lambda expressions allow you to write a one-time function so you can use it just for the one function call. Here, I used a lambda with the [_for\_each()_](cplusplus.com/reference/algorithm/for_each/) function to reverse the case of every letter in a string.

```C++
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string book = "Pride and Prejudice";

    //Before
    cout << "BEFORE Transformation: " << book << '\n';

    //Reverse the case of the string (upper -> lower, lower -> upper)
    for_each(book.begin(), book.end(), [](char& c) { if (isupper(c)) c = tolower(c); else if (islower(c)) c = toupper(c); });

    //After
    cout << "AFTER Transformation: " << book << '\n';

    return 0;
}
```

## Sources
Microsoft C++ Documentation: [_Lambda expressions in C++_](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160) <br />
cppreference.com: [_Lambda expressions_](https://en.cppreference.com/w/cpp/language/lambda) <br />
CProgramming.com: [_Lambda Functions in C++11 - the Definitive Guide_](https://www.cprogramming.com/c++11/c++11-lambda-closures.html) <br />
LearnCPP.com: [_11.14 — Lambda captures_](https://www.learncpp.com/cpp-tutorial/lambda-captures/) <br />
GeeksforGeeks: [_Functors in C++_](https://www.geeksforgeeks.org/functors-in-cpp/) <br />
GeeksforGeeks: [_Lambda expression in C++_](https://www.geeksforgeeks.org/lambda-expression-in-c/) <br />
DZone: [_All About Lambda Functions in C++ (From C++11 to C++17)_](https://dzone.com/articles/all-about-lambda-functions-in-cfrom-c11-to-c17) <br />
Embarcadero: [_C++ Lambda Expressions for Beginners_](https://blogs.embarcadero.com/lambda-expressions-for-beginners/) <br />
