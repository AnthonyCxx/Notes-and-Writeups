# Macros in C
Macros define patterns that input that are replaced by patterns of output. Macros are similar to functions, but are directly substituted into the text during the 
preprocessing stage and thus avoid function overhead (just like inline functions). However, macros are much more dangerous as they cannot be debugged (do not have
typechecking) and may expand in unexpected ways. [Here](https://programmersought.com/article/98051903921/) is a good summary of macros. Below I have some articles 
that provide a good summary of when and when not to use macros. As a rule of thumb, if you don't know: don't. <br />

Articles:
[_How to Properly Use Macros in C_](https://pmihaylov.com/macros-in-c/) <br />
[_What are Macros Useful For?_](https://stackoverflow.com/questions/653839/what-are-c-macros-useful-for) <br />

## _#define_ \<input pattern\> \<output pattern\>
The _#define_ directive defines a pattern for the compiler such that whenever it encounters the pattern of input (the first item), it will be replaced by the output 
(the second item). These patterns of input which are transformed into patterns of output are called [macros](https://en.wikipedia.org/wiki/Macro_(computer_science)). 
In its simplest form, the _#define_ macro is used to define constants that will be substituted throughout the program. For example, a directive
_#define PI 3.14159_ would replace all instances of 'PI' (but not pi, pI, or Pi) with '3.14159'. Per convention, macro identifiers (names) should always be fully 
capitalized.
```C
#include <stdio.h>
#define PI 3.14159

int main(void)
{
    printf("Pi is equal to %.5f\n", PI);     //Show Pi with 5 decimal places (%.5f)

    return 0;
}
```
> Prints: Pi is equal to 3.14159

## Parameterized Macros
Macros can be taken a step further with [parameterized macros](https://en.wikipedia.org/wiki/Macro_(computer_science)#Parameterized_macro), patterns that can take parameters.
Often, parameterized macros are used to write simple functions and eliminate [function overhead](https://stackoverflow.com/questions/31779335/why-is-there-overhead-when-calling-functions) (the time taken to call a function). Read [this StackOverflow response](https://stackoverflow.com/questions/14041453/why-are-preprocessor-macros-evil-and-what-are-the-alternatives) before using parameterized macros as they can have many unintended side effects and can be outright harmful in some cases. <br />

Here, we can write a simple macro to calculate the square of a number, preventing us from having to include the entire [_\<math.h\>_](https://www.tutorialspoint.com/c_standard_library/math_h.htm) to use the [_pow()_](https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm) function a single
time. See [this article](https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm) for more information on macros.
```C
#include <stdio.h>
#define SQUARE(x) (x*x)    // Parameterized 

int main(void)
{
    printf("The square of 5 is: %d\n", SQUARE(5));

    return 0;
}
```
> Prints: The square of 5 is: 25

## Macro Pitfalls
Macros are not typechecked; Additionally, they may not expand in the same way that you might expect.

### Lack of Type-checking
Macros cannot be debugged, and thus their type cannot be checked. This means that the computer cannot implicitly convert the datatypes to the same type and ends up adding 
two values of different types (which a computer **_cannot_** do properly). Here, the _INCREMENT()_ macro adds an integer literal (1) to the passed parameter and then assigns
it to the paramter. Because _int\_num_ is an integer, this does not cause any problems; however, since _float\_num_ is a float, the computer ends up adding an integer literal
to a float and the result is the value of _float\_num_ becoming 0.000000 (a clear error).
```C
#include <stdio.h>
#define INCREMENT(x) (x = x + 1)

int main(void)
{
    int int_num = 1;
    int float_num = 1.0;

    printf("The integer 1 incremented is: %d\n", INCREMENT(int_num));
    printf("The float 1 incremented is: %f\n", INCREMENT(float_num));  

    return 0;
}
```
> Prints: <br />
> The integer 1 incremented is: 2 <br />
> The float 1 incremented is: 0.000000 <br />

### Unexpected Expansion
Macros take their parameters quite literally. The _SQUARE(x)_ function used earlier to show parameterized macros breaks when you give it an expression (2+3) instead of a 
literal (5). This is because the parameter _x_  is 2+3 and the macro does not know to include parthenses; so, the macro really expands to 2 + 3 * 2 + 3, which
equals 11, not 25 as we would expect. This can be easily fixed by putting parentheses around the parameters in the definition of _SQUARE()_ like so:
_#define SQUARE(x) ( (x)\*(x) )_; now, it should work fine. Alternatively, you could use parentheses when passing the parameter, but that's impractical.
```C
#include <stdio.h>
#define SQUARE(x) ( (x)*(x) )    // <== Correct
// #define SQUARE(x) (x*x)  // <== Error, expands improperly

int main(void)
{
    printf("2+3 squared is: %d\n", SQUARE(2+3));  //Prints 25

    return 0;
}
```
> Prints: 2+3 squared is: 25 <br />
> 
> Citation notice: the example above is inspired by the GeeksforGeeks article '[Macros vs Functions](https://www.geeksforgeeks.org/macros-vs-functions/)'. <br />

## Pre-defined Macros 
There are a number of macros that are predefined by the compiler such as _\_\_DATE\_\__ (the date the program was compiled on), _\_\_TIME\_\__ (the time the program was compiled), and _\_\_FILE\_\__ (the name of the file being compiled). [Here](https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html) is a more comprehensive list (note:
some of these macros are specific to the GCC compiler).
```C
#include <stdio.h>

int main(void)
{
    /* PRE-DEFINED MACROS */

    // __DATE__ and __TIME__
    printf("This program was compiled on %s at %s\n", __DATE__, __TIME__);

    // __FILE__ (filename)
    printf("The name of this file is %s\n", __FILE__);

    return 0;
}
```
> Prints: <br />
> This program was compiled on Jun 30 2021 at 21:08:55 <br />
> The name of this file is Macros.c <br />
