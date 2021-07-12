# Storage Classes in C
A storage class is a modifier for a variable that determines how the variable is stored in memory.

## auto
I'll be honest, _auto_ is a useless keyword; in fact, it was so useless that [C++ repurposed it](https://docs.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-160#remarks).
_auto_ just specifies that the variable being declared is local (not global). Because of this, it can only be used within functions, whose variables are automatically and
already local. You see the problem.

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
Static variables do not go out of scope, unlike local variables. Static variables can be used to maintain values even between function calls.
The default value of a static variable is 0.

```C
#include <stdio.h>

// Loop X number of times, keeping track of how many total times
void loop(int times)
{
    static int total;   // Default value is 0, not garbage.

    for(int i = 0; i < times; i++)
    {
        total++;
    }

    printf("The loop has been run a total of %d times\n", total);
}

int main()
{
    loop(3);        // Loop 3 times
    loop(5);       // Loop 5 times
    loop(12);     // Loop 12 times

    return 0;
}
```
> Prints: <br />
> The loop has been run a total of 3 times <br />
> The loop has been run a total of 8 times <br />
> The loop has been run a total of 20 times <br />

## register
The _register_ keyword stores a variable in a [CPU register](https://whatis.techtarget.com/definition/register) rather than [RAM](https://www.studytonight.com/computer-architecture/random-access-memory) (like it normally would). Using the _register_ keyword provides far faster access to the variable than if it were stored in RAM.
These days, the compiler is generally better at deciding which variables should be stored in the register than people, so they tend to take the _regsiter_ keyword
as more of a suggestion than a command (See [_"register" Keyword in C_](https://stackoverflow.com/questions/578202/register-keyword-in-c) and [_Death of the register keyword may be greatly exaggerated_](https://blog.bytellect.com/software-development/c-cplusplus/death-of-the-register-keyword-may-be-exaggerated/)).

## Sources
