# Macros in C
Macros define patterns that input that are replaced by patterns of output. Macros are similar to functions, but are directly substituted into the text during the 
preprocessing stage and thus avoid function overhead (just like inline functions). However, macros are much more dangerous as they cannot be debugged (do not have
typechecking), have no sense of scope, and may expand in unexpected ways. [Here](https://programmersought.com/article/98051903921/) is a short summary of macros. 
Below I have some articles that provide a good summary of macros as well as when and when not to use them. As a rule of thumb, if you don't know: _don't_. 
Use functions instead. <br />

Articles: <br />
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

## Macro Pitfalls: Unexpected Expansion
Macros take their parameters quite literally. The _SQUARE(x)_ function used earlier to show parameterized macros breaks when you give it an expression (2+3) instead of a 
literal (5). This is because the parameter _x_  is 2+3 and the macro does not know to include parthenses; so, the macro really expands to 2 + 3 * 2 + 3, which
equals 11, not 25 as we would expect. This can be easily fixed by putting parentheses around the parameters in the definition of _SQUARE()_ like so:
_#define SQUARE(x) ( (x)\*(x) )_; now, it should work fine. Alternatively, you could use parentheses when passing the parameter, but that's impractical.
```C
#include <stdio.h>
#define SQUARE(x) ( (x)*(x) )    // <== Correct
// #define SQUARE(x) (x*x)  // <== Wrong (logic error), expands improperly

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

## Generics with _\_Generic_ 
[C11](https://en.wikipedia.org/wiki/C11_(C_standard_revision)) introduced the [_\_Generic_](https://en.cppreference.com/w/c/language/generic) keyword,
which allows you to write a single macro that works with varying datatypes. This is important because it allows for safer macros by preventing unintentional misusing
them with types it wasn't intended for; in addition to providing some type-safety, the _\_Generic_ keyword allows you to emulate typical object-oriented programming
principles like function overloading and templating.

### Simple Usage
Here is a simple generic macro that increments different datatypes differently.

```C
#include <stdio.h>

// Increment integers by 1, floats by 2, and doubles by 3
#define INCREMENT(X) _Generic((X), int: X += 1, float: X += 2.0f, double: X += 3.0)

int main(void)
{
    int int_num = 1;
    float float_num = 1.0;

    printf("The integer 1 incremented is: %d\n", INCREMENT(int_num));
    printf("The float 1 incremented is: %.2f\n", INCREMENT(float_num));
   
    return 0;
}
```
> Prints: <br />
> The integer 1 incremented is: 2 <br />
> The float 1 incremented is: 3.00 <br />

### Evaluating Datatypes
```C
#include <stdio.h>

#define TYPE(X) \
 _Generic((X), \
    char: "char", \
    unsigned char: "unsigned char",\
    char*: "char pointer",        \
                    \
    short: "short", \
    unsigned short: "unsigned short", \
    int: "int", \
    unsigned int: "unsigned int", \
    long: "long", \
    unsigned long: "unsigned long", \
    long long: "long long", \
    unsigned long long: "unsigned long long", \
                    \
    float: "float", \
    double: "double", \
    long double: "long double", \
                                \
    default: "unknown datatype")


int main(void)
{
    // Print the type of a string literal (a char*)
    printf("Type name: %s\n", TYPE("this is a string literal"));

    // Print the datatype of an unsigned long long
    printf("Type name: %s\n", TYPE(10ULL));    // 'ULL' suffix for unsigned long long literal

    return 0;
}
```
> Prints: <br />
> Type name: char pointer <br />
> Type name: unsigned long long <br />

### Complex Usage
Generic macros can be used to achieve pseudo-polymorphism, mapping varying functions to a single 'function' call.
```C
#include <stdio.h>

void print_char(char);
void print_str(char*);

void print_int(int);
void print_float(float);
void print_double(double);

// Pseudo-polymorphism
#define print(x) _Generic((x), char: print_char, char*: print_str, int: print_int, float: print_float, double: print_double)(x)

int main(void)
{
    print("This is a string :D");
    print(14.00);
    print(1300);
    print((char) 'A');   // For some reason disincluding the typecast '(char)' yields 'print_int'

    return 0;
}

void print_char(char chr)
{
    printf("Printing char: \'%c\'\n", chr);
}

void print_str(char* str)
{
    printf("Printing string: \'%s\'\n", str);
}

void print_int(int num)
{
    printf("Printing int: \'%d\'\n", num);
}

void print_float(float num)
{
    printf("Printing float: \'%.2f\'\n", num);
}

void print_double(double num)
{
    printf("Printing double: \'%.2lf\'\n", num);
}
```

### Sources:
IBM Documentation: [_Generic Selection (C11)_](https://www.ibm.com/docs/en/zos/2.4.0?topic=expressions-generic-selection-c11) <br />
Microsoft Documentation: [_Generic Selection (C11)_](https://docs.microsoft.com/en-us/cpp/c-language/generic-selection?view=msvc-160) <br />
WikiChip: [_Generic Selection - C_](https://en.wikichip.org/wiki/c/generic_selection) <br />
Rob's Programming Blog: [_C11 - Generic Selections_](http://www.robertgamble.net/2012/01/c11-generic-selections.html) <br />
StackOverflow: [_Syntax and Sample Usage of \_Generic in C11_](https://stackoverflow.com/questions/9804371/syntax-and-sample-usage-of-generic-in-c11) <br />
GitHub Gist: [_Fun with C11 \_Generic()_](https://gist.github.com/ThirteenFish/8253ab3a55101bd86455) <br />
Andrew Bissel: [_C11’s \_Generic Keyword: Macro Applications and Performance Impacts_](https://abissell.com/2014/01/16/c11s-_generic-keyword-macro-applications-and-performance-impacts/) <br />
