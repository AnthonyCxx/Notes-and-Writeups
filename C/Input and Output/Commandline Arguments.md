# Using Commandline Arguments in C
Commandline arguments are [function arguments](http://www.trytoprogram.com/c-programming/c-programming-function-arguments/#:~:text=C%20programming%20function%20arguments%20also,carry%20out%20the%20specified%20task.) that are passed to the main function at the commandline when the 
program is run. To use commandline arguments,

```C
#include <stdio.h>

int main(int argc, char* argv[])
{
    // Print all commandline arguments
    for(int i=0; i < argc; i++)
    {
        puts(argv[i]);
    }

    return 0;
}
```
