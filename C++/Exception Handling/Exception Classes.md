# Creating Custom Exceptions with Exception Classes in C++
If you choose to throw the numerator or denominator when throwing a division by zero error, there is the problem that you cannot throw separate errors for dividing 0 by 0 (indeterminate) and generally dividing by 0 (undefined)
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
> Don't forget to initialize _result_ in the _catch_ blocks, otherwise it's value will be [garbage](https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/).

## Catch Block Order and Derived Exception Classes
Substitutability is a fundamental principle of design inhherited classes; anywhere where you use the base class, you should be able to use the derived class. Though
incredibly convenient for functions, it can cause some problems for derived exceptions classes, as the derived exception class gets caught by a _catch_ block meant
for the base class. To solve this problem, always put the _catch_ block for the derived exception class ***before*** the _catch_ block for the base exception class.

### Bad Example
If you try to compile this code, GCC will give you the following warning: "_warning: exception of type ‘IndeterminateResultException’ will be caught
by earlier handler for ‘DivideByZeroException’_".

```C++
#include <iostream>
#include <string>
using namespace std;

//For dividing by zero
class DivideByZeroException
{
    private:
        string message;

    public:
        DivideByZeroException(string Message = "you cannot divide by zero!")
        {
            message = Message;
        }

        string what() const
        {
            return message;
        }

};

//For dividing zero by zero
class IndeterminateResultException: public DivideByZeroException
{
    public:
        //A single constructor that calls the constructor from 'DivideByZeroException'
        IndeterminateResultException(string Message = "dividing zero by zero is indeterminate!"): DivideByZeroException(Message)
        {
            //'IndeterminateResultException' implements no new members
        }
};


int main()
{
    try
    {
        //Gets caught by 'DivideByZeroException' since it's derived from it...
        throw IndeterminateResultException();
    }
    catch(const DivideByZeroException& e)
    {
        clog << "Caught a divide by zero exception!\n";
    }
    catch(const IndeterminateResultException& e)
    {
        clog << "Caught an indeterminate result exception!\n";
    }

    return 0;
}
```

### Good Example
Now that the most specific (most derived) _catch_ block comes first, substitutability won't cause any problems.

```C++
#include <iostream>
#include <string>
using namespace std;

//For dividing by zero
class DivideByZeroException
{
    private:
        string message;

    public:
        DivideByZeroException(string Message = "you cannot divide by zero!")
        {
            message = Message;
        }

        string what() const
        {
            return message;
        }

};


//For dividing zero by zero
class IndeterminateResultException: public DivideByZeroException
{
    public:
        //A single constructor that calls the constructor from 'DivideByZeroException'
        IndeterminateResultException(string Message = "dividing zero by zero is indeterminate!"): DivideByZeroException(Message)
        {
            //'IndeterminateResultException' implements no new members
        }
};


int main()
{
    try
    {
        //Gets caught by 'IndeterminateResultException' since its catch block comes first
        throw IndeterminateResultException();
    }
    catch(const IndeterminateResultException& e)
    {
        clog << "Caught an indeterminate result exception!\n";
    }
    catch(const DivideByZeroException& e)
    {
        clog << "Caught a divide by zero exception!\n";
    }

    return 0;
}
```

## Modeling Built-in Exceptions
[_std::bad\_cast_](https://en.cppreference.com/w/cpp/header/typeinfo)
