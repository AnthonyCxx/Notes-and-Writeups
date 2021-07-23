# Exception Handling in C++
Exceptions are errors that occur during runtime, like a failure to allocate heap memory because there wasn't enough memory left ([_bad\_alloc_](https://www.cplusplus.com/reference/new/bad_alloc/)); exceptions can be managed through a process called _exception handling_. Exception handling allows you to deal
with errors in a way that allows the program to continue running seamlessly (hopefully). Sometimes, an exception cannot be truly 'recovered' from, but can only be dealt with,
in which case exception handing allows a graceful solution to be achieved.

Exception handling is preferable to only error checking (C-style error handling) as exception handling is distinct from the rest of the code and cannot be confused with
standard control flow; moreover, exception handling does not require the programmer to implcitly know that some generic _if_ statment is meant to handle an error because
the exception handling makes it abundently apparent.

After you finish reading all of this, read through [_Modern C++ best practices for exceptions and error handling (2020)_](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160).

## Basic Error Handling with _try_ and _catch_
Exception handling is fundamentally built upon two keywords: _try_ and _catch_. _try_ defines a block of code within which the programmer expects
an error may occur and _catch_ catches the error, defining a block that runs after the error occurs. When an exception is raised, the program immediately
exits the _try_ block and jumps to the relevant _catch_ block; the remaining statement in the _try_ block are ignored.

In the following example, the _catch_ statement catches a built-in error [_bad\_alloc_](https://www.cplusplus.com/reference/new/bad_alloc/),
which is implicitly thrown when `new int[9223372036854775]` fails. If there were no catch _try_/_catch_ block, then the program would have crashed
with the following message: <br />

_"terminate called after throwing an instance of 'std::bad_alloc'. <br />
what():  std::bad\_alloc.  <br />
Aborted (core dumped)"_ <br />

```C++
// Protip: If you don't know the error type, catching '...' will catch any and all errors. //
// ^^ If you're in CSC-1720, then this will be on your test ^^

try
{
  //Always fails, array size is too large (~9.223 quadrillion bytes or 8 petabytes)
  int* massiveArray = new int[9223372036854775];
}
catch(bad_alloc)  //Fatal error caught, now the program won't crash.
{
  clog << "Error: array could not be allocated...\n";
}
```

## Manually Throwing Errors with _throw_
If you want to catch anything other than an error thrown by the program itself, you'll have to do it manually with the _throw_ keyword. If you know Python,
think of _throw_ as the [_raise_](https://stackoverflow.com/questions/2052390/manually-raising-throwing-an-exception-in-python) keyword. You can throw any datatype 
in C++, integers, doubles, strings, classes, but you cannot have two catch blocks with the same datatype; if you do, then the second one will never be executed.
This problem is solved by exception classes, which we will touch on shortly.

This program catches a division by zero error (floating point exception), which would have crashed the program and caused a core dump.
```C++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double numerator, denominator, result;

    //Get the numerator and denominator from the user
    cout << "Enter the numerator and denominator: ";
    cin >> numerator >> denominator;

    /*
        User enters '10' for the numerator
        and '0' for the denominator.
    */

    try
    {
        //Throw error?
        if (denominator == 0)
            throw string("you cannot divide by zero.");  //'string' is a class and has a constructor

        //Never executed since denominator is thrown
        result = numerator / denominator;
    }
    catch(const string& errMsg)   //Catch ANY thrown string
    {
        //Error message, so use clog instead of cout
        clog << "Error: " << errMsg << '\n'; 
        result = 0;
    }

    //Print result of the division
    cout << "Result: " << result << '\n';

    return 0;
}
```

## Creating Custom Exceptions with Exception Classes
In the problem above, there is the problem that you cannot throw separate errors for dividing 0 by 0 (indeterminate) and generally dividing by 0 (undefined)
as there is only one datatype (double) to throw. You could of course throw a double and a string, or a double and a char*, or even a char* and a string; 
however, all of these options are not only needlessly confusing, but limiting, as you may need to throw three or more unique errors in more complex blocks.
Limiting yourself to the basic datatypes is highly restrictive. So, often programmers will create unique classes for each potential error, allowing you to 
separate your errors (and _catch_ blocks) neatly.

Here are two classes for dealing with both inderminate (0 / 0) and undefined (anything / 0) division. This way, you can avoid any and all floating-point exceptions
that would kill your program. Furthermore, you can see how exception handling neatly divides the intended flow of the program from the error-handling as they are in 
separate blocks.

```C++
#include <iostream>
#include <string>
using namespace std;

//For indeterminate calculations (0 / 0)
class IndeterminateResult
{
    private:
        //The error message
        string message;

    public:
        //Default and parameterized constructor (via default parameter)
        IndeterminateResult(string errorMessage = "Dividing 0 by 0 is indeterminate.")
        {
            message = errorMessage;
        }

        /* 
           The 'what()' function is standard practice in C++. 
           Always use a 'what()' function. to return the message.
       */

        //Return the error message
        string what() const 
        {
            return message;
        }
};

//For undefined calculations (anything / 0)
class UndefinedResult
{
    private:
        //The error message
        string message;

    public:
        //Default and parameterized constructor (via default parameter)
        UndefinedResult(string errorMessage = "Dividing by 0 is undefined")
        {
            message = errorMessage;
        }
        
        /* 
           The 'what()' function is standard practice in C++. 
           Always use a 'what()' function. to return the message.
       */

        //Return the error message
        string what() const
        {
            return message;
        }
};

// DRIVER CODE //
int main()
{
    double numerator, denominator, result;

    //Get the numerator and denominator from the user
    cout << "Enter the numerator and denominator: ";
    cin >> numerator >> denominator;

    //Error-free division
    try
    {
        //Throw error?
        if (numerator == 0 and denominator == 0)
            throw IndeterminateResult("0 / 0 is indeterminate.");
        
        //Throw error?
        if (denominator == 0)
            throw UndefinedResult("anything / 0 is undefined.");

        //If no errors are thrown, perform the calculation.
        result = numerator / denominator;
    }
    catch(const IndeterminateResult& e)
    {
        //Error message, so use clog instead of cout
        clog << "Error: " << e.what() << '\n'; 
        result = 0;
    }
    catch(const UndefinedResult& e)
    {
        //Error message, so use clog instead of cout
        clog << "Error: " << e.what() << '\n';
        result = 0;
    }

    //Print result of the division
    cout << "Result: " << result << '\n';

    return 0;
}
```

## Catching Errors with _assert()_
C++ inherited the _assert()_ function from C and continues to use it as a viable way of catching errors. _assert()_ is a function under the [_\<cassert\>_](https://www.cplusplus.com/reference/cassert/)
library and is used for errors that ["should have never occured if all your code is correct"](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160#exceptions_versus_assertions). This is because unlike error handling, which is meant to deal with errors as they arise, _assert()_ terminates the program
if the expression inside it evaluates to false. If you want to test your program without the _assert()_ statements you've included, you can disable them by writing
`#define NDEBUG`.

Here, the _assert()_ catches the fact that I forgot to add a _break_ statement after the final case. I meant for the flow of execution to fall through to cases
1, 2, and 3, but not to the default case. The _assert()_ statement makes this clear.

```C++
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int choice = 2;

    switch (choice)
    {
        case 1:
            cout << "Case 1 activated...\n";

        case 2:
            cout << "Case 2 activated...\n";

        case 3:
            cout << "Case 3 activated...\n";

        //This should never happen.
        default:
            assert(0);  //Always false
    }

    return 0;
}
```

## Sources
cplusplus.com: [_Exceptions_](https://www.cplusplus.com/doc/tutorial/exceptions/) <br />
cplusplus.com: [_std::exception_](https://www.cplusplus.com/reference/exception/exception/) <br />
TutorialsPoint: [_C++ Exception Handling_](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm) <br />
GeeksforGeeks: [_Exception Handling in C++_](https://www.geeksforgeeks.org/exception-handling-c/) <br />
Microsoft C++ Documentation: [_Modern C++ best practices for exceptions and error handling (2020)_](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160) <br />
isocpp.org: [_Exceptions and Error Handling_](https://isocpp.org/wiki/faq/exceptions) <br />
cplusplus.com: [_assert_](https://www.cplusplus.com/reference/cassert/assert/) <br />
StackOverflow: [_Why should I use asserts?_](https://stackoverflow.com/questions/1081409/why-should-i-use-asserts) <br />
