# GNU C Extensions
GNU C extensions are extensions to the C programming language made by the [GNU Organization](https://www.gnu.org/philosophy/philosophy.html). These extensions can be found [here](https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html). GNU C extensions are not accepted as a part of the [ISO C Standard](https://www.iso-9899.info/wiki/The_Standard) 
nor the [ANSI C Standard](https://en.wikipedia.org/wiki/ANSI_C) (which was adopted bythe ISO C Standard years ago). **Do _not_ use these in your college/university projects**, 
as they are specific to [the GNU C Compiler](https://gcc.gnu.org/) (GCC) and your code will not compile if your professor decides to use another compiler (which is not unlikely). 
That being said, if you are building with GCC (and especially if you are building for Linux) these extensions are incredibly handy, almost [to the point of magic](https://radek.io/2012/11/10/magical-container_of-macro/).

## Statements Within Expressions
GNU C allows you to declare statements within expressions using the `({ })` structure. The result of the last expression is implicitly returned.
Here, we can print 'Hello, world!' and return the amount of times all in a single
variable declaration. In this context, it is poor practice, but there are many circumstances where it is convenient to evaluate a complex expression and store the result.
```C
#include <stdio.h>

int main(void)
{

    // times = 5 (returned by i, the last statement).
    int times = ({int i = 0; for (i; i < 5; i++) { puts("Hello, World!"); } i; });

    // Prints: "Hello, World!" was printed a total of %d times.
    printf("\"Hello, World!\" was printed a total of %d times.\n", times);

    return 0;
}
```

### Case Range
The GCC Compiler allows you to use '...' to indicate a [case range expression](https://gcc.gnu.org/onlinedocs/gcc/Case-Ranges.html). <br />
The range expression will accept everything between the given low and high.
```C
#include <stdio.h>

int main(void)
{
    int coins = 255;

    switch (coins)
    {
        case 300 ... 999:
            puts("You can buy a large health potion.");

        case 200 ... 299:
            puts("You can buy a medium health potion.");

        case 100 ... 199:
            puts("You can buy a small health potion.");
            break;

        default:
            puts("You have insufficient funds.");
    }

    return 0;
}
```
> Prints: <br />
> You can buy a medium health potion. <br />
> You can buy a small health potion.  <br />
