# Preprocessor Directives in C++
A preprocessor directive is a [directive](https://en.wikipedia.org/wiki/Directive_(programming)) that specifies how the compiler should process its input (the source code).

## _#include_ \<file\>
The _#include_ directive [imports](https://en.wikipedia.org/wiki/Include_directive) another file into the current file. When importing a file, the filename should be
surrounded with either angular brackets (`<filename>`) or quotation marks (`"filename"`), depending on whether the file belongs to the C++ Standard Library or is a file made by the 
developer respectively. Including a file is the equivalent of copying and pasting the file where the _#include_ is written. I'm being serious, that's literally what the 
compiler does. Because of this, all _#include_ directives should come before any code, especially the _main()_ function.

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

int main()
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
is included as a trigger, so that same code won't be included  more than once. This practice, however, is outdated now. Use _#pragma once_ instead.
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

# _#pragma_
The _#pragma_ macro enables/disables various compiler features such as warnings or errors. The _#pragma_ directive can even 'poison' certain functions/features, preventing
the code from using them (for security reasons, etc.). Some of these features are specific to the GCC compiler; if they are, then they will have '_GNU_' in the directive.

## _#pragma once_
The _#pragma once_ directive tells the compiler to only include the current file once, regardless of how many _#include_
directives are used. <br /> This is not only a more concise, but safer alternative to the _#ifndef_, _#define_,  and _#endif_ trio as there is no chance of a name conflict.

```C++
#pragma once  //See how much cleaner this is?

void sayHello()
{
    cout << "Hello!\n";
}
```

## _#pragma GCC Error/Warning_
_#pragma GCC Error_ and _#pragma GCC Warning_ can be used to manually define errors. Though it sounds strange, manual warnings can be used to note things like bugs that you
haven't gotten arround to fixing and manual errors can prevent people from using dangerous, unfinished code.

```C++
#include <iostream>
using namespace std;

#pragma GCC error "This error will prevent you from compiling the code"
#pragma GCC warning "This is a warning. It won't stop you, but it should"

int main()
{
    //Stuff

    return 0;
}
```

## _#pragma GCC poison_
GCC allows you to 'poison' certain identifiers, which could be functions, objects, or even variable names. <br />
If the code contains a poisoned identifier, it will not compile.

Attempting to compile the following code yields an error, '_error: attempt to use poisoned "cout"_'.
```C++
#include <iostream>
using namespace std;

#pragma GCC poison cout

int main()
{
    cout << "Hello, World!\n";

    return 0;
}
```
