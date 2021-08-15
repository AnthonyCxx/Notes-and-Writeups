# Functions in C
A function is a block of code that can be called upon by name, executing it. A function declaration requires a return type, the name of the function, and a list of the
parameters that it takes. For now, only worry about the name, since we'll be using void functions.

```C
#include <stdio.h>

//Definition of a function 'printHello' with no return type (void) or parameters
void printHello()
{
    puts("Hello, world!");
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

```C
#include <stdio.h>

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

    printf("The number returned by function 'return5' is: %d\n", number);

    return 0;
}
```

## Parameters
Functions can take [parameters](https://www.thoughtco.com/definition-of-parameters-958124) (sometimes called arguments). The function can then use these 
values as variables. When declaring parameters, be sure to declare their type as well. A simple method '_add_' could take two numbers as parameters and return their sum.
Parameters should be declared as a part of the parameters list (inside the parentheses following the function name) and should be prefaced by their datatype. If you have
multiple parameters, they should be comma-separated.

```C
#include <stdio.h>

//Function 'add' adds two numbers ('a' and 'b') and returns their sum
int add(int a, int b)
{
    return a + b;
}

int main()
{
    printf("5 + 5 = %d\n", add(5, 5));
}
```

## Implicit Parameter Type Conversion
Compatible types such as _int_, _float_, and _double_ can be [implcitly converted](https://www.ibm.com/docs/en/zos/2.1.0?topic=resolution-implicit-conversion-sequences)
when provided as a parameter for a function. If you have a function that takes an integer as a parameter, but you pass it a float (let's say 13.75), it will automatically
convert the float 13.75 into the integer 13 by [truncating](https://techterms.com/definition/truncate) it. The same goes for return types. If you return a double 56.88
and catch it in an integer, then the integer will contain 56 because it will type-cast 56.88 into 58 before storing it.

Because of this, I recommend all math-related functions you write to both use and return doubles, as you can always type-cast to a less specific type (double to float, 
double to int), but you cannot type-cast to a more specific type (float to double) without losing some or all of the characteristics of the more specific datatype
(in this case, some or all of the decimal places).

```C
#include <stdio.h>

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
    printf("10 + 20 stored as an integer is: %d\n", intResult);  //Result = 30

    //double + double
    double doubleResult = add(doubleA, doubleB);   //Stores the result as a double
    printf("15.5 + 16.5 stored as a double is: %.2f\n", doubleResult);  //Result = 32.2

    //int + double
    int mixedResult = add(intA, doubleA);         //Stores the result as an integer (type-casted down from a double)
    printf("10 + 15.5 stored as an integer is: %d\n", mixedResult);  //Result = 25

    return 0;
}
```
> References: [_LearnToProgram: Type Compatibility_](http://learntoprogramming.com/type-compatibility) and [_cplusplus.com: Type Conversions_](https://www.cplusplus.com/doc/tutorial/typecasting/) 

## Passing by Pointer
C doesn't have references like C++ does, so instead it [passes by pointer](https://www.tutorialspoint.com/cprogramming/c_passing_pointers_to_functions.htm).

```C
#include <stdio.h>

int swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    
    printf("Before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);

    return 0;
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
#include <stdio.h>

// If not static, this won't compile
static inline int absurdMath(int a, int b)
{
    return a * b + 2 / 15;
}

int main()
{
    //'absurdMath()' is inlined, so 'absurdMath(157, 31135)' is directly replaced by '157 * 31135 + 2 / 15'
    printf("The result of this absurd math is: %d\n", absurdMath(157, 31135));

    return 0;
}
```
> Sources: <br />
> cplusplus.com: [_What is C++ inline functions_](https://www.cplusplus.com/articles/2LywvCM9/) <br />
> Microsoft C++ Documentation: [_Inline Functions (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-160) <br />
> GeeksforGeeks: [_Inline Functions in C++_](https://www.geeksforgeeks.org/inline-functions-cpp/) <br />
> StackOverflow: [_Do compilers always ignore inline hints?_](https://stackoverflow.com/questions/32047466/do-c11-compatible-compilers-always-ignore-inline-hints) <br />
