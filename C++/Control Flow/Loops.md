# Iteration Statements (Loops) in C++
Loops (iteration statements) allow you to repeat a statement or block of statements multiple times, usually until some condition is no longer true.
C++ has 4 types of iteration statements: for loops, while loops, and do...while loops and range-based for loops. Loops consist of a condition and a body. <br />

## For Statement
The _for_ statement allows you to execute a block of statements a specific number of times. A _for_ statement consists of a declaration statement, a condition,
and an update statemnt in that order; each of these sections are separated by semi-colons. It is best to use a for loop when the exact amount of executions is 
known (or deducible by some property or expression). <br />

### Format
```C++
for(delcaration; condition; update)
{
    //Body
}
```

### Example
```C++
//Prints "Hello, World!" 5 times
for (int iterator = 0; iterator < 5; iterator++)  //Declaration, condition, and update statements
{
  cout << "Hello, World!\n";     //Body
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
```C++
// Advanced for loop with two declaration and update statements
for (int i=0, j=0; i < 6; i += 1, j += 2)
{
  cout << i << " " << j << '\n';
}

```
> Note: this works in other languages such as C and C# as well
 
## While Statement
The _while_ statment continues to execute the body of the loop until the given condition is false. <br />
If the given condition is false from the start, then the loop will not execute at all.

### Format
```C++
while (condition)
{
    //Body
}
```

### Example
```C++
while (1 == 1)
{
    cout << "This is an infinite loop\n";
}
```
> Note: this is actually an infinte loop (1 _always_ equals 1), please do not run this. <br />
> Side Note: If you are actually dumb enough to run this, you can stop the program with _ctrl_ + _c_. Don't say I didn't warn you.

## Do...While Statement
The _do...while_ loop acts similarly to a while loop, repeating until the given condition is false; however, unlike a normal _while_ loop, a _do...while_ loop will
always execute at least once. _Do...while_ loops are exceptionally useful for validating user input.

### Format
```C++
do
{
    //Body
} while (condition);
```
> Note: pay close attention to the '_;_' at the end of the while statement. A _do...while_ loop is the only loop with a semi-colon.

### Example
```C++
#include <iostream>
using namespace std;

int main()
{
    int input;

    do
    {
        // Get input from user
        cout << "Enter an integer greater than 10: ";    // User prompt
        cin >> input;                            // Scan a single integer from the keyboard

        // If bad input, put a warning
        if (input <= 10)
            cout << "\nError: input not greater than 10\n";  // Extra '\n' for spacing

    } while (input <= 10);   // Loop while the number is 10 or less


    // Ending
    cout << "You entered the number: " <<  input << '\n';

    return 0;
}
```

## Range-based For Loop
A range-based for loop is the equivalent of a [_foreach loop_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/statements/iteration-statements#the-foreach-statement) in Java or C#. A range-based for loop iterates over a container (a data structure that contains a collection of elements). In the example, the variable
_num_ takes on a value of the Nth element in the array until it has iterated over all the elements. If you want to write a flexible for loop that works with various types,
don't know the datatype of the container, or don't want to write out the type, then use the [_auto_](https://www.youtube.com/watch?v=2vOPEuiGXVo) keyword.

## Format
```C++
for(variable declaration : container)
{

}
```

## Example
```C++
// An array of 5 numbers
int nums[5] = {1, 2, 3, 4, 5};

for(int num : nums)
{
    cout << num << '\n';
}
```
> Prints: <br />
> 1, 2, 3, 4, 5 (on separate lines)
