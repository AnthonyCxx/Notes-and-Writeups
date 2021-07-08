# Conditional Statements in C
Conditionals are control structures that allow you to control the flow of a program based on certain (boolean) criteria. <br />
If the condition is true, then the statments within the _{ }_ will be executed; otherwise, no code will be executed and the program will continue on. <br /> 

If you forget to include the _{ }_, then the _if_ statement will only affect the statement that directly follows it. <br />
Although it is syntactically correct to omit the _{ }_, you should always include them for sake of clarity.

### Format
```C
if (condition)   //If the condition is true, then
{
    //Execute statements
}
```

## If Statement
The _if_ keyword is the heart of conditional statements - you cannot have a conditional statement without first have an _if_ statement. <br />
An _if_ statement evaluates a condition and executes some code if the condition is true.

### Example
```C
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool isBook = true;

    if (isBook)   //'isBook' is replaced by its value (true)
    {
    //Statements to be executed
    puts("The item is a book!");
    }

    return 0;
}
```
> This snippet prints "The item is a book!"

## Else Statement
An _else_ statement always directly follows either an _if_ or _else if_ statement. An _else_ statement executes when the preceeding condition is false. <br />
An _else_ statement must always come at the end of a conditional structure.

### Example
```C
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool isBook = false;

    if (isBook)   //'isBook' is replaced by its value (false)
    {
        //Not executed, because 'isBook' is false
        puts("The item is a book!");
    }
    else
    {
        //IS executed, because 'isBook' is false
        puts("The item is NOT a book!");
    }

    return 0;
}
```

## Else If Statement
Like the _else_ statement, an _else if_ statement must follow an _if_ statement. An _else if_ statement executes if both the preceeding statement _and_ the given
condition are true. You can use an _else if_ statement without using an _else_ statement.

### Example
```C
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool isBook = false;

    if (isBook)   //'isBook' is replaced by its value (false)
    {
        //Not executed, because 'isBook' is false
        puts("The item is a book!");
    }
    else if (1 == 2)
    {
        //Not executed even though the first if statement is false, because 1 does not equal 2
        puts("Hmm, the item may be a book...");
    }
    else
    {
        //IS executed, because 'isBook' is false and the else if statement above failed
        puts("The item is NOT a book!");
    }

    return 0;
}
```

## Switch Statment
The _switch_ statment allows for evaluating a variable or expression that may equal a variety of values a clear and structured manner. An example of a use for a switch statement 
would be [NPC dialogue](https://learn.unity.com/tutorial/switch-statements#5c8a6f91edbc2a067d4753d4) that is based on an in-game value, such as the intelliegence of the 
player character.

### Standard Behavior
```C
#include <stdio.h>

int main(void)
{
    int coins = 300;

    switch (coins)
    {
        case 300:
            puts("You can buy a large health potion.");
            break;

        case 200:
            puts("You can buy a medium health potion.");
            break;

        case 100:
            puts("You can buy a small health potion.");
            break;

        default:
            puts("You have insufficient funds.");
            break;
    }

    return 0;
}
```
> Prints: You can buy a large health potion.  <br />

### Fall-through Behavior
By disclusing the _break_ statement, you can allow the flow of execution to continue to the next case (and the next case, etc.) after a case is triggered.

```C
#include <stdio.h>

int main(void)
{
    int coins = 300;

    switch (coins)
    {
        case 300:
            puts("You can buy a large health potion.");

        case 200:
            puts("You can buy a medium health potion.");
            
        case 100:
            puts("You can buy a small health potion.");
            break;

        default:
            puts("You have insufficient funds.");
    }

    return 0;
}
```
> Prints: <br />
> You can buy a large health potion.  <br />
> You can buy a medium health potion. <br />
> You can buy a small health potion. <br />

### Using GNU Range Expressions
The GCC Compiler allows you to use [range expressions](https://gcc.gnu.org/onlinedocs/gcc/Case-Ranges.html) as a replacement for booleans.
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

## The Ternary Operator (? :)
The ternary operator (as opposed to binary or unary operators) takes a condition and evaluates it; if the condition is true, it returns the first expression; if not,
it returns the second expression. Think of the ternary operator as a simplified version of a standard _if_-_else_ conditional structure.

### Format
```C
expression ? value1 : value2
```

### Example
```C
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    // Returns (and then prints) 'Pi is less than the square root of 5' because 'PI > sqrt(5)' is false
    puts( PI > sqrt(5) ? "Pi is greater than the square root of 5" : "Pi is less than the square root of 5" );

    return 0;
}
```
> Prints "Pi is greater than the square root of 5", as 3.14 is greater than 2.24

