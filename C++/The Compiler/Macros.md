# Macros in C++
Macros define patterns that input that are replaced by patterns of output. Macros are similar to functions, but are directly substituted into the text during the 
preprocessing stage and thus avoid function overhead (just like inline functions). However, macros are much more dangerous as they cannot be debugged (do not have
typechecking), have no sense of scope, and may expand in unexpected ways. [Here](https://programmersought.com/article/98051903921/) is a short summary of macros. 
Below I have some articles that provide a good summary of macros as well as when and when not to use them. As a rule of thumb, if you don't know: _don't_. 
Use functions instead. <br />

Articles: <br />
[_C++ TUTORIAL - MACRO - 2020_](https://www.bogotobogo.com/cplusplus/preprocessor_macro.php) <br />
[_3 Types of Macros That Improve C++ Code_](https://www.fluentcpp.com/2019/05/14/3-types-of-macros-that-improve-c-code/) <br />
[_How and Why to Avoid Preprocessor Macros_](https://luckyresistor.me/knowledge/avoid-preprocessor-macros/) <br />

## _#define_ \<input pattern\> \<output pattern\>
The _#define_ directive defines a pattern for the compiler such that whenever it encounters the pattern of input (the first item), it will be replaced by the output 
(the second item). These patterns of input which are transformed into patterns of output are called [macros](https://en.wikipedia.org/wiki/Macro_(computer_science)). 
In its simplest form, the _#define_ macro is used to define constants that will be substituted throughout the program. For example, a directive
_#define PI 3.14159_ would replace all instances of 'PI' (but not pi, pI, or Pi) with '3.14159'. Per convention, macro identifiers (names) should always be fully 
capitalized. These days, you should always use [_const_](https://www.geeksforgeeks.org/const-keyword-in-cpp/) instead of _#define_ for constants like 'PI'.
```C++
#include <iostream>
#define PI 3.14159
using namespace std;

int main()
{
    //Preprocessor replaces 'PI' with '3.14159'
    cout << "Pi is equal to " << PI << '\n';

    return 0;
}
```
> Prints: Pi is equal to 3.14159

## Parameterized Macros
Macros can be taken a step further with [parameterized macros](https://en.wikipedia.org/wiki/Macro_(computer_science)#Parameterized_macro), patterns that can take parameters.
Often, parameterized macros are used to write simple functions and eliminate [function overhead](https://stackoverflow.com/questions/31779335/why-is-there-overhead-when-calling-functions) (the time taken to call a function). Read [this StackOverflow response](https://stackoverflow.com/questions/14041453/why-are-preprocessor-macros-evil-and-what-are-the-alternatives) before using parameterized macros as they can have many unintended side effects and can be outright harmful in some cases. In modern C++, you really
should use [_inline_](https://www.geeksforgeeks.org/inline-functions-cpp/) or [_constexpr_](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/) to avoid function overhead. Using macros as functions is not something you should be doing in modern C++. <br />

Here, we can write a simple macro to calculate the square of a number, preventing us from having to include the entire [_\<cmath\>_](https://www.tutorialspoint.com/c_standard_library/math_h.htm) to use the [_pow()_](https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm) function a single
time.
```C++
#include <iostream>
#define SQUARE(x) (x*x)    // Parameterized
using namespace std;

int main()
{
        //'SQUARE(5)' is replaced by '5 * 5'
    cout << "The square of 5 is: " << SQUARE(5) << '\n';

    return 0;
}
```
> Prints: The square of 5 is: 25

## Macro Pitfalls: Unexpected Expansion
Macros take their parameters quite literally. The _SQUARE(x)_ function used earlier to show parameterized macros breaks when you give it an expression (2+3) instead of a 
literal (5). This is because the parameter _x_  is 2+3 and the macro does not know to include parthenses; so, the macro really expands to 2 + 3 * 2 + 3, which
equals 11, not 25 as we would expect. This can be easily fixed by putting parentheses around the parameters in the definition of _SQUARE()_ like so:
_#define SQUARE(x) ( (x)\*(x) )_; now, it should work fine. Alternatively, you could use parentheses when passing the parameter, but that's impractical.
```C++
#include <iostream>
#define SQUARE(x) ( (x)*(x) )    // <== Correct
// #define SQUARE(x) (x*x)  // <== Wrong (logic error), expands improperly
using namespace std;

int main()
{
        //A proper 'SQUARE()' macro
    cout << "2+3 squared is: " << SQUARE(2+3) << '\n';  //Prints 25

    return 0;
}
```
> Prints: 2+3 squared is: 25 <br />
> 
> Citation notice: the example above is inspired by the GeeksforGeeks article '[Macros vs Functions](https://www.geeksforgeeks.org/macros-vs-functions/)'. <br />

## Pre-defined Macros 
There are a number of macros that are predefined by the compiler such as _\_\_DATE\_\__ (the date the program was compiled on), _\_\_TIME\_\__ (the time the program was compiled), and _\_\_FILE\_\__ (the name of the file being compiled). [Here](https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html) is a more comprehensive list (note:
some of these macros are specific to the GCC compiler).
```C++
#include <iostream>
using namespace std;

void someFunction()
{
    cout << "Inside the function \'" << __FUNCTION__ << "\'!\n";
}

int main()
{
    /* PRE-DEFINED MACROS */

    // __DATE__ and __TIME__
    cout << "This program was compiled on " << __DATE__ << " at " <<  __TIME__ << '\n';

    // __FILE__ (filename)
    cout << "The name of this file is " << __FILE__ << '\n';

    //__FUNCTION__ (the name of the current function)
    someFunction();

    return 0;
}
```
> Prints: <br />
> This program was compiled on Jul 28 2021 at 13:31:24 <br />
> The name of this file is PredefinedMacros.cpp <br />
> Inside the function 'someFunction'! <br />
