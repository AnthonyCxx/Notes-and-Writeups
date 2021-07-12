# Storage Classes in C
A storage class is a modifier for a variable that determines how the variable is stored in memory.

## auto

## extern
The _extern_ keyword (short for 'external') allows you to use variables and functions declared in other files.

File 1
```C
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
