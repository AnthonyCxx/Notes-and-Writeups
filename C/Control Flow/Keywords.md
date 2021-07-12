# Keywords Related to Control Flow in C

## Break
The _break_ keyword breaks out of a loop, ending the current interation as well as preventing all future iterations.
```C
#include <stdio.h>

int main(void)
{
    // An infinite loop...
    for (int i=1; i; i++)   // 'i' is always true as it's non-zero
    {
        printf("%d\n", i);

        if (i > 100000)
        {
            printf("Breaking loop at %d!\n", i);
            break;
        }
    }

    return 0;
}
```
Prints: <br />
> (1 - 100,000) <br />
> Breaking loop at 100,001! <br />

## Continue
The _continue_ keyword skips the remaining content of the iteration of the loop (if placed at the beginning, that's all of the loop) and then begins the next iteration.
```C
#include <stdio.h>

int main(void)
{
    // Prints all even numbers 0-20
    for (int i=0; i <= 20; i++)
    {
        if (i % 2 == 1)   // Skip odd numbers
            continue;

        printf("%d\n", i);
    }

    return 0;
}
```
> Note: This could be done better without a _continue_ statement, but I am using it here to illustrate the concept. <br />
> As a general rule of thumb, try to limit anything that breaks that standard flow of the program. Simple is always better.

## Goto
The _goto_ keyword moves the [instruction pointer](https://en.wikipedia.org/wiki/Program_counter) to another section of code on the stack. _Goto_ statements can jump
_anywhere_ in the code, provided that it has been labeled (implicitly or explicitly). Because they can jump anywhere, _goto_ statements can quickly make code convoluted 
and very difficult to read. It is generally advised to use _goto_ statements only when necessary, if at all. Now, there is still some debate about how and if they should
be used, but I argue that _goto_ statements can be used in very rare circumstance where they can improve code clarity or improve the efficiency of an 
algorithm. Regardless, for the most part, _goto_ statements are a clear indicator of poor code structure and make maintaining codebases exceptionally difficult. <br />

Here is an article worth reading, regardless of its age: [Donald Knuth: Structured Programming with _goto_ Statements](https://www.scribd.com/document/38873257/Knuth-1974-Structured-Programming-With-Go-to-Statements). <br /> Keep in mind that this was written in a time when programming languages lacked good structure, 
 and _goto_ statements were often the only option for unconditional jumps. Nowadays, this is not true, so take the arguments with a grain of salt. <br />

As you should always have both sides, here is a [A Case Against Goto Statements](https://www.cs.utexas.edu/users/EWD/ewd02xx/EWD215.PDF).

```C
#include <stdio.h>

int main(void)
{
    // An infinite loop
    begin_loop:
        for(int i=1; i < 10; i++)
        {
            printf("%d\n", i);

            if (i == 5)
                goto begin_loop;
        }

    return 0;
}
```
> Note: Spacing doesn't matter, so indenting the 'block' is irrelevant; however, you should still do it for sake of clarity as _goto_ statements can be difficult to read/find.

