# Preprocessor Directives in C
A preprocessor directive is a [directive](https://en.wikipedia.org/wiki/Directive_(programming)) that specifies how the compiler should process its input (the source code).

## #include \<file\>
The _#include_ directive [imports](https://en.wikipedia.org/wiki/Include_directive) another file into the current file. When importing a file, the filename should be
surrounded with either angular brackets (\< \>) or quotation marks (" "), depending on whether the file belongs to the C Standard Library or is a file made by the 
developer respectively.
```C
#include <stdio.h>           // For standard library files
#include "customFile.h"     //  For custom (user-made) files

int main(void)
{
    // %s is the string format specifier, replaced by 'Hello, World!\n'
    printf("%s", "Hello, world!\n");

    return 0;
}
```
