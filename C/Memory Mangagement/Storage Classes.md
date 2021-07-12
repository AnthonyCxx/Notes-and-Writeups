# Storage Classes in C
A storage class is a modifier for a variable that determines how the variable is stored in memory.

## auto
I'll be honest, _auto_ is a useless keyword; in fact, it was so useless that [C++ repurposed it](https://docs.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-160#remarks).
_auto_ just specifies that the variable being declared is local (not global). Because of this, it can only be used within functions, whose variables are automatically
local. You see the problem.

## extern
The _extern_ keyword (short for 'external') provides an alternative to _#include_, allowing you to use variables and functions declared in other files without including the
other file.

File 1
```C
// Compile with 'gcc *.c' ('*' wildcard matches with all C source code files)
#include <stdio.h>

extern void ascii(char);     // There is a void function that accepts a char in another file

int main()
{
    char input;

    printf("Enter a character to find its ASCII value: ");
    input = getchar();
    putchar('\n');

    ascii(input);   //prints the ASCII value of a character

    return 0;
}
```

File 2
```C
// The other file
#include <stdio.h>

void ascii(char character)
{
    printf("The ASCII value of %c is %d\n", character, character);
}
```

## static

## register


## Sources
