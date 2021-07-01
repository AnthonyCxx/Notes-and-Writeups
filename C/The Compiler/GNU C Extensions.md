# GNU C Extensions
GNU C Extensions are extensions to the C programming language made by the [GNU Organization](https://www.gnu.org/philosophy/philosophy.html).
These extensions can be found [here](https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html). **Do _not_ use these in your college/university projects**, as they are 
specific to [the GNU C Compiler](https://gcc.gnu.org/) (GCC) and your code will not compile if your professor decides to use another compiler (which is not unlikely). 


## Statements Within Expressions
GNU C allows you to declare statements within expressions using the `({ })` structure.
```C
#include <stdio.h>

int main(void)
{

    // times = 5
    int times = ({int i = 0; for (i; i < 5; i++) { puts("Hello, World!"); } i; });

    // Prints: "Hello, World!" was printed a total of %d times.
    printf("\"Hello, World!\" was printed a total of %d times.\n", times);

    return 0;
}
```
