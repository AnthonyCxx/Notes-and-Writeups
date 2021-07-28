# Preprocessor Directives in C++
A preprocessor directive is a [directive](https://en.wikipedia.org/wiki/Directive_(programming)) that specifies how the compiler should process its input (the source code).

## _#include_ \<file\>
The _#include_ directive [imports](https://en.wikipedia.org/wiki/Include_directive) another file into the current file. When importing a file, the filename should be
surrounded with either angular brackets (\< \>) or quotation marks (" "), depending on whether the file belongs to the C++ Standard Library or is a file made by the 
developer respectively.
```C++
#include <iostream>           // For standard library files
#include "customFile.h"      //  For custom (user-made) files

int main()
{
    // Code

    return 0;
}
```

## _#define_ \<input pattern\> \<output pattern\>
The _#define_ directive defines a pattern for the compiler such that whenever it encounters the pattern of input (the first item), it will be replaced by the output 
(the second item). These patterns of input which are transformed into patterns of output are called [macros](https://en.wikipedia.org/wiki/Macro_(computer_science)). 
In its simplest form, the _#define_ macro is used to define constants that will be substituted throughout the program. For example, a directive
_#define PI 3.14159_ would replace all instances of 'PI' (but not pi, pI, or Pi) with '3.14159'. Per convention, macro identifiers (names) should always be fully 
capitalized. See more about macros [here](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/The%20Compiler/Macros.md).

```C++
#include <iostream>
#define PI 3.14159
using namespace std;

int main(void)
{
    //Preprocessor replaces 'PI' with '3.14159'
    cout << "Pi is equal to " << PI << '\n';

    return 0;
}
```
> Prints: Pi is equal to 3.14159

## _#ifndef_, _#define_, and _#endif_
The _#ifndef_, _#define_,  and _#endif_ trio are typically used to prevent the compiler from including the same code multiple times (via the _#include_ directive). 
Code that is inbetween an _#ifndef_ and _#endif_ will not be executed if the macro (definition/pattern) is not defined (is false). The _#define_ (definition/pattern)
is included as a trigger, so that same code won't be included  more than once.
```C++
// In customFile.h
#ifndef CUSTOM_FILE      // If 'CUSTOM_FILE' is not defined, define everything until '#endif'
#define CUSTOM_FILE      // Prevents this body from being included multiple times (by defining 'CUSTOM_FILE')

void sayHello()
{
    cout << "Hello!\n";
}

#endif                 // End the conditional (creates a boundary for '#ifndef')
```
