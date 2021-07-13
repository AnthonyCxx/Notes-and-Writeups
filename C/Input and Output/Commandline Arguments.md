# Using Commandline Arguments in C
Commandline arguments are [function arguments](http://www.trytoprogram.com/c-programming/c-programming-function-arguments/#:~:text=C%20programming%20function%20arguments%20also,carry%20out%20the%20specified%20task.) that are passed to the main function at the commandline when the 
program is run. <br /> To use commandline arguments, change the parameters of the _main_ function from '_void_' to '_int argc, char* argv[]_'. _argc_ stands for 'argument
count' and is equal to the amount of arguments. _argv\[\]_ stands for 'argument vector' and is an array that contains all the commandline arguments. A for loop combined
with _argc_ allows you to easily loop over the entire array. Unlike languages like C#, the first argument inthe argument vector (argv) is always the name of the program.

```C
#include <stdio.h>

int main(int argc, char* argv[])
{
    // Print all commandline arguments
    for(int i=1; i < argc; i++)   // 'int i=0' to include program name
    {
        puts(argv[i]);
    }

    return 0;
}
```
