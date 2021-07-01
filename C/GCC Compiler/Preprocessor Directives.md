# Preprocessor Directives in C
A preprocessor directive is a [directive](https://en.wikipedia.org/wiki/Directive_(programming)) that specifies how the compiler should process its input (the source code).

## _#include_ \<file\>
The _#include_ directive [imports](https://en.wikipedia.org/wiki/Include_directive) another file into the current file. When importing a file, the filename should be
surrounded with either angular brackets (\< \>) or quotation marks (" "), depending on whether the file belongs to the C Standard Library or is a file made by the 
developer respectively.
```C
#include <stdio.h>           // For standard library files
#include "customFile.h"     //  For custom (user-made) files

int main(void)
{
    printf("Hello, world!\n");

    return 0;
}
```

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

## Parameterized Macros (_#define_)
Macros can be taken a step further with [parameterized macros](https://en.wikipedia.org/wiki/Macro_(computer_science)#Parameterized_macro), patterns that can take parameters.
Often, parameterized macros are used to write simple functions and eliminate [function overhead](https://stackoverflow.com/questions/31779335/why-is-there-overhead-when-calling-functions) (the time taken to call a function). Read [this StackOverflow response](https://stackoverflow.com/questions/14041453/why-are-preprocessor-macros-evil-and-what-are-the-alternatives) before using parameterized macros as they can have many unintended side effects and can be outright harmful in some cases. <br />

Here, we can write a simple macro to calculate a square root, preventing us from having to include the entire [_\<math.h\>_](https://www.tutorialspoint.com/c_standard_library/math_h.htm) to use a single function.
```C
#include <stdio.h>
#define SQUARE(x) (x * x)    // Parameterized 

int main(void)
{
    printf("The square root of 5 is: %d\n", SQUARE(5));

    return 0;
}
```
> Prints: The square root of 5 is: 25

## _#ifndef_, _#define_, and _#endif_
The _#ifndef_, _#define_,  and _#endif_ trio are typically used to prevent the compiler from including the same code multiple times (via the _#include_ directive). 
Code that is inbetween an _#ifndef_ and _#endif_ will not be executed if the macro (definition/pattern) is not defined (is false). The _#define_ (definition/pattern)
is included as a trigger, so that same code won't be included  more than once.
```C
// In customFile.h
#ifndef CUSTOM_FILE      // If 'CUSTOM_FILE' is not defined, define everything until '#endif'
#define CUSTOM_FILE      // Prvents this body from being included multiple times (by defined 'CUSTOM_FILE'

void sayHello(void)
{
    printf("Hello, world!");
}

#endif                 // End the conditional (creates a boundary for '#ifndef'
```
