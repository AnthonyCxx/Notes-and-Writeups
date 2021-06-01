# Conditional Statements in C#
Conditionals are control structures that allow you to control the flow of a program based on certain (boolean) criteria. <br />
If the condition is true, then the statments within the _{ }_ will be executed; otherwise, no code will be executed and the program will continue on. <br /> 
Note that _If_, _else if_, and _else_ statements will only ever execute one statement of statement block. <br /> 

If you forget to include the _{ }_, then the _if_ statement will only affect the next statement that follows it. <br />
Although it is syntactically correct to omit the _{ }_, you should always include them for sake of clarity.

### Format
```C#
if (condition)   //If the condition is true, then
{
    //Execute statements
}
```

## If 
The _if_ keyword is the heart of conditional statements - you cannot have a conditional statement without first have an _if_ statement. <br />
An _if_ statement evaluates a condition and executes some code if the condition is true.

### Example
```C#
bool isBook = true;

if (isBook)   //'isBook' is replaced by its value (true)
{
    //Statements to be executed
    System.Console.WriteLine("The item is a book!");
}
```
> This snippet prints "The item is a book!"

## Else
An _else_ statement always directly follows either an _if_ or _else if_ statement. An _else_ statement executes when the preceeding condition is false. <br />
An _else_ statement must always come at the end of a conditional structure.
```C#
bool isBook = false;

if (isBook)   //'isBook' is replaced by its value (false)
{
    //Not executed, because 'isBook' is false
    System.Console.WriteLine("The item is a book!");
}
else
{
    //IS executed, because 'isBook' is false
    Sysmtem.Console.WriteLine("The item is NOT a book!");
}
```

## Else if
Like the _else_ statement, an _else if_ statement must follow an _if_ statement. An _else if_ statement executes if both the preceeding statement _and_ the given
condition are true. You can use an _else if_ statement without using an _else_ statement.
```C#
bool isBook = false;

if (isBook)   //'isBook' is replaced by its value (false)
{
    //Not executed, because 'isBook' is false
    System.Console.WriteLine("The item is a book!");
}
else if (1 == 2)
{
    //Not executed even though the if statement is false, because 1 does not equal 2
    System.Console.WriteLine("Hmm, the item may be a book...");
}
else
{
    //IS executed, because 'isBook' is false and the else if statement above failed
    Sysmtem.Console.WriteLine("The item is NOT a book!");
}
```
