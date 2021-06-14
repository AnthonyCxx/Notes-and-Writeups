# Iteration Statements (Loops) in C#
Loops (iteration statements) allow you to repeat a statement or block of statements multiple times, usually until some condition is no longer true.
C# has 4 types of iteration statements: for statements, foreach statements, do statements, and while statements. Loops consist of a condition and a body. <br />

## For Statement
The _for_ statement allows you to execute a block of statements a specific number of times. A _for_ statement consists of a declaration statement, a condition,
and an update statemnt in that order; each of these sections are separated by semi-colons. It is best to use a for loop when the exact amount of executions is known. <br />

### Format
```C#
for(delcaration; condition; update)
{
    //Body
}
```

### Example
```C#
//Prints "Hello, World!" five times
for (int iterator = 0; iterator < 5; iterator++)  //Declaration, condition, and update statements
{
  Console.WriteLine("Hello, World!");     //Body
}
```
> Note: It is commonplace to use just _i_ as a shorthand 'iterator'
>> | Loop Section | Function |
>> | ------------ | -------- |
>> | int interator = 0 | declare an integer _iterator_ and set it to 0 |
>> | iterator < 5 | as long as the iterator is less tha 5, execute the body |
>> | iterator++ | increment the iterator by 1 ([postfix operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/arithmetic-operators#increment-operator-)) |

### Advanced For Loops
Both the declaration and update statements of a _for_ loop can contain more than one value, as long as they are separated by commas. If you need multiple conditions,
just use the logical _&&_ and _| |_ operators. The following code snippet declares two counters, _i_ and _j_, which count from 0-5 and 0-10 respectively. 
Counter _j_ counts by twos.
```C#
//Prints two counters simultaneously
for(int i=0, j=0; i < 6; i += 1, j += 2 )
{
  Console.WriteLine(i + " " + j);
}
```
> Note: this works in other languages such as C++ as well
 
## While Statement
The _while_ statment continues to execute the body of the loop until the given condition is false. <br />
If the given condition is false from the start, then the loop will not execute at all.

### Format
```C#
while (condition)
{
    //Body
}
```

### Example
```C#
while (1 == 1)
{
    Console.WriteLine("this is an infinite loop");
}
```
> Note: this is actually an infinte loop (1 _always_ equals 1), please do not run this. <br />
> Side Note: If you are actually dumb enough to run this, you can stop the program with _ctrl_ + _c_. Don't say I didn't warn you.

## Do...While Statement
The _do...while_ loop acts similarly to a while loop, repeating until the given condition is false; however, unlike a normal _while_ loop, a _do...while_ loop will
always execute at least once.

### Format
```C#
do
{
    //Body
} while (condition);
```
> Note: pay close attention to the _;_ at the end of the while statement. A _do...while_ loop is the only loop with a semi-colon.

### Example
```C#
int input;

//Input loop: prompts for input until an integer greater than 5 is given
do
{
    Console.Write("Enter a number more than 5: ");       //Prompt the user
    input = Int32.Parse( System.Console.ReadLine() );    //Store the input as an integer (converted from a string)
} while (input <= 5);
```
> Reference: [Converting Strings to Integers in C#](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/how-to-convert-a-string-to-a-number)

## Foreach Statement
A _foreach_ loop executes the body of the loop for every item in a [container](https://docs.microsoft.com/en-us/dotnet/api/system.componentmodel.container?view=net-5.0) (iterable object). The variable declared in the loop is updated to be the item at the current index in the loop for each item in the loop. In other words, the 
variable takes on the value of the container at said index until all the items have been run through.

### Format
```C#
foreach(datatype variableName in container)
{
   //Body
}
```

### Example
```C#
string[] backpack = { "Pencil", "Spellbook", "Lobster" };

foreach(string item in backpack)
{
    Console.Write(item + " ");   //Print out each item
}
Console.WriteLine("");     //End the line
```
> Note: if the items are of different types, use [the _var_ keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)


# Related Keywords

## Break
The _break_ keyword breaks out of a loop, ending the current interation as well as preventing all future iterations.
```C#
string[] obscureReference = { "speed", "of", "lobsters", "origin" };

foreach (string word in obscureReference)
{
    if (word == "of")
        break;

    Console.WriteLine(word);

```
> Prints "speed", breaking the loop when it hits "of"

## Continue
The _continue_ keyword skips the remaining content of the iteration of the loop (if placed at the beginning, that's all of the loop) and then begins the next iteration.
```C#
//Prints all even numbers between 0 and 20 (inclusive)
for (int i = 0; i <= 20; i++)
{
    if (i % 2 == 1)   //If the number is odd, skip printing the number
        continue;

    Console.WriteLine(i);
}
```
> Note: This could be done better without a _continue_ statement, but I am using it here to illustrate the concept. As a general rule of thumb, try to limit
> anything that breaks that standard flow of the program. Simple is always better.

## Goto
The _goto_ keyword moves the [instruction pointer](https://en.wikipedia.org/wiki/Program_counter) to another section of code on the stack. _Goto_ statements can jump
_anywhere_ in the code, provided that it has been labeled (implicitly or explicitly). Because they can jump anywhere, _goto_ statements can quickly make code convoluted 
and very difficult to read. It is generally advised not to use _goto_ statements only when necessary, if at all. Now, there is still some debate about how they should
be used, but I argue that _goto_ statements should be used circumstantially, as there are times when they can improve code clarity or improve the efficiency of an 
algorithm (source: [Donald Knuth: Structured Programming with _goto_ Statements](https://www.scribd.com/document/38873257/Knuth-1974-Structured-Programming-With-Go-to-Statements)

### Fall-through Behavior with _goto_
```C#
int integer = 0;

switch(integer)
{
    case 0:
        Console.WriteLine(0);
        goto case 1;           
        break;
    case 1:
        Console.WriteLine(1);
        goto case 2;
        break;
    case 2:
        Console.WriteLine(2);
        break;
    default:
        System.Environment.Exit(1);
        break;
}
```

### Restarting Loops with _goto_
An infinite loop in C# using _goto_.
```C#
begin_loop:  
    for (int i = 0; i < 10; i++)   //print the numbers 0-9
    {
        Console.WriteLine(i);

        if (i == 5)
            goto begin_loop;  //restart the loop
    }
```
> Note: Spacing doesn't matter, so indenting the 'block' is irrelevant; however, you should still do it for sake of clarity as _goto_ statements can be difficult to read/find.
