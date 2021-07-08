# Iteration Statements (Loops) in C
Loops (iteration statements) allow you to repeat a statement or block of statements multiple times, usually until some condition is no longer true.
C has 3 types of iteration statements: for statements, while statements, and do...while statements. Loops consist of a condition and a body. <br />

## For Statement
The _for_ statement allows you to execute a block of statements a specific number of times. A _for_ statement consists of a declaration statement, a condition,
and an update statemnt in that order; each of these sections are separated by semi-colons. It is best to use a for loop when the exact amount of executions is 
known (or deducible by some property or expression). <br />

### Format
```C#
for(delcaration; condition; update)
{
    //Body
}
```

### Example
```C
#include <stdio.h>

int main(void)
{
    //Prints "Hello, World!" 5 times
    for (int iterator = 0; iterator < 5; iterator++)  //Declaration, condition, and update statements
    {
        puts("Hello, World!");     //Body
    }

    return 0;
}
```
> Note: It is commonplace to use just _i_ as a shorthand 'iterator'
>> | Loop Section | Function |
>> | ------------ | -------- |
>> | int interator = 0 | declare an integer _iterator_ and set it to 0 |
>> | iterator < 5 | as long as the iterator is less tha 5, execute the body |
>> | iterator++ | increment the iterator by 1 ([postfix operator](https://www.programiz.com/article/increment-decrement-operator-difference-prefix-postfix)) |

### Advanced For Loops
Both the declaration and update statements of a _for_ loop can contain more than one value, as long as they are separated by commas. If you need multiple conditions,
just use the logical [_&&_](https://www.tutorialspoint.com/cprogramming/c_logical_operators.htm) and [_| |_](https://www.tutorialspoint.com/cprogramming/c_logical_operators.htm) operators. The following code snippet declares two counters, _i_ and _j_, which count from 0-5 and 0-10 respectively. 
Counter _j_ counts by twos.
```C
#include <stdio.h>

int main(void)
{
    // Advanced for loop with two declaration and update statements
    for (int i=0, j=0; i < 6; i += 1, j += 2)
    {
        printf("%d %d\n", i, j);
    }

    return 0;
}
```
> Note: this works in other languages such as C++ as well
 
## While Statement
The _while_ statment continues to execute the body of the loop until the given condition is false. <br />
If the given condition is false from the start, then the loop will not execute at all.

### Format
```C
while (condition)
{
    //Body
}
```

### Example
```C
while (1 == 1)
{
    puts("This is an infinite loop");
}
```
> Note: this is actually an infinte loop (1 _always_ equals 1), please do not run this. <br />
> Side Note: If you are actually dumb enough to run this, you can stop the program with _ctrl_ + _c_. Don't say I didn't warn you.

## Do...While Statement
The _do...while_ loop acts similarly to a while loop, repeating until the given condition is false; however, unlike a normal _while_ loop, a _do...while_ loop will
always execute at least once. _Do...while_ loops are exceptionally useful for validating user input.

### Format
```C
do
{
    //Body
} while (condition);
```
> Note: pay close attention to the _;_ at the end of the while statement. A _do...while_ loop is the only loop with a semi-colon.

### Example
```C
#include <stdio.h>

int main(void)
{
    int input;

    do
    {
        // Get input from user
        printf("Enter an integer greater than 10: ");    // User prompt
        scanf("%d", &input);                            // Scan a single integer from the keyboard

        // If bad input, put a warning
        if (input <= 10)
            puts("Error: input not greater than 10\n");  // Extra '\n' for spacing

    } while (input <= 10);   // Loop while the number is 10 or less


    // Ending
    printf("You entered the number: %d\n", input);

    return 0;
}
```
> Reference: [_scanf()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Input.md#scanf)

## Emulating _foreach_ with Macros
Many languages (C++, C#, Java, Python) have a [_foreach_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/statements/iteration-statements#the-foreach-statement) 
that allows you to easily loop over a data structure such as an array or linked list. C does not have a _foreach_ statement; however, one can be emulated with macros.
The only downside is that you have to write a different _foreach_ macro for each data structure, since their implementation is different. This macro, which works for arrays,
would not come close to working for linked lists.

```C
#include <stdio.h>

// Finds the size of an array
#define SIZE(array) sizeof(array) / sizeof(array[0])

// Loops over an array
#define foreach(i, array) \                  
    for(int i=0; i < SIZE(array); i++)

int main(void)
{
    // An array of 5 integers (1 -5)
    int array[5] = {1, 2, 3, 4, 5};

    foreach(i, array)    // Expands to 'for (int i=0; i < sizeof(array) / sizeof(array[0]); i++'
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
```
> Note: '\' extends the macro definition of _foreach_ to the next line
> 
> Strange? Note: I expected the macro to break when I changed the parameter 'array' inside of the 'SIZE()' macro since it wouldn't share the same name as the 
> 'foreach' macro, but it didn't.

### A Look into the Preprocessor
After running this program through the preprocessor (and only the preprocessor!) with the GCC `-E` option, I went to the bottom of the file and found the substitutions
the preprocessor did with our macros and lo and behold it works perfectly.
```C
int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};

    // A look at our expanded macros
    for(int i=0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
```
