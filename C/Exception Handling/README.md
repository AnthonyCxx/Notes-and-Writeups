# Exception Handling in C
C does not support exception handling, so you can go ahead and cry now. Instead, we have [conditionals](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Control%20Flow/Conditionals.md), a set of functions ([_perror()_](https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm) and [_strerror()_](https://www.tutorialspoint.com/c_standard_library/c_function_strerror.htm)), and a set of macros 
([_extern int errno_](https://www.tutorialspoint.com/c_standard_library/c_macro_errno.htm), [_EDOM_](https://www.tutorialspoint.com/c_standard_library/c_macro_edom.htm),
and [_ERANGE_](https://www.tutorialspoint.com/c_standard_library/c_macro_erange.htm))
to deal with errors.

## Simple Error Handling with Conditionals
Ideally, you can predict potentially pitfalls in your program; if you can, using an _if_ statement is always a solid option.

Note: dividing by zero is actually undefined behavior, not 0, but for the sake of example I'm ignoring that.
```C
#include <stdio.h>

int main(void)
{
    int result, dividend = 30, divisor = 0;

    // Avoid floating-point exception from dividing by zero
    if (divisor != 0)
        result = dividend / divisor;
    else
        result = 0;

    printf("The result of %d / %d is %d\n", dividend, divisor, result);

    return 0;
}
```
> Prints: <br />
> The result of 30 / 0 is 0

## errno
_errno_ is a integer that corrosponds to an error message in a  hard-coded lookup table. This table varies by system, but for our purposes you should use [this Linux table](https://www.thegeekstuff.com/2010/10/linux-error-codes/). To use _errno_ in your program, declare it globally via `extern int errno;`.

## strerror()
_strerror()_ is a function under [_\<string.h\>_](https://www.tutorialspoint.com/c_standard_library/string_h.htm) that searches the system's error lookup table for
the given error code (as an integer) and returns the appropriate error message as a string literal. <br />

Here, I forced a printing error by closing [stdout](https://stackoverflow.com/questions/16430108/what-does-it-mean-to-write-to-stdout-in-c).
```C
#include <stdio.h>      // I/O operations
#include <string.h>    // contains 'strerror()'
#include <errno.h>    // contains 'errno'

// Macro from 'errno.h', receives error codes from operations
extern int errno;

int main(void)
{
    // 'stdout' is a file, so you can close it
    fclose(stdout);

    // Won't work because 'stdout' is closed
    puts("This won\'t print");

    // Error message
    if (errno)         // If an error occured (error will be non-zero)
    {
        // Printing to 'stderr' will still work, because 'stdout' is a separate FILE* stream
        fprintf(stderr, "An error occured: %s (Error code: %d)\n", strerror(errno), errno);
    }

    return 0;
}
```
> Prints: <br />
> An error occured: Bad file descriptor (Error code: 9)

## perror()

## Sources
TutorialsPoint: [_C - Error Handling_](https://www.tutorialspoint.com/cprogramming/c_error_handling.htm) <br />
TutorialsPoint: [_C Library Macro: Errno_](https://www.tutorialspoint.com/c_standard_library/c_macro_errno.htm) <br />
CPPReference: [_strerrr()_](https://en.cppreference.com/w/cpp/string/byte/strerror) <br />
Study Tonight: [_Error Handling in C_](https://www.studytonight.com/c/error-handling-in-c.php) <br />
GeeksforGeeks: [_Error Handling in C Programs_](https://www.geeksforgeeks.org/error-handling-c-programs/) <br />
StackOverflow: [_Error Handling in C Code_](https://stackoverflow.com/questions/385975/error-handling-in-c-code) <br />
Wikibooks: [_C Programming/Error handling_](https://en.wikibooks.org/wiki/C_Programming/Error_handling) <br />
TheGeekStuff: [_131 Linux Error Codes for C Programming Language using errno_](https://www.thegeekstuff.com/2010/10/linux-error-codes/) <br />
