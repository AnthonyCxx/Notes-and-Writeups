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

## If Statement
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

## Else Statement
An _else_ statement always directly follows either an _if_ or _else if_ statement. An _else_ statement executes when the preceeding condition is false. <br />
An _else_ statement must always come at the end of a conditional structure.

### Example
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

## Else If Statement
Like the _else_ statement, an _else if_ statement must follow an _if_ statement. An _else if_ statement executes if both the preceeding statement _and_ the given
condition are true. You can use an _else if_ statement without using an _else_ statement.

### Example
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

## Switch Statment
The _switch_ statment allows for evaluating a variable or expression in a clear and structured manner. By default, _switch_ statements support 
[fall-through behavior](https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/), meaning that when the expression matches a case, it 
executes that statement block _and_ all the statement blocks that follow - this is avoided by ending statement blocks with the _break_ statement.

### Format
```C#
switch (expression)
{
    case someValue1:
            //Statements
            break;
            
    //Values someValue2, someValue2, and someValue3 all execute the same block
    case someValue2:      
    case someValue3:
    case someValeu4:
            //Statements
            break;
    default:
            //Statements
            break;                           
}
```

### Example
```C#
string request;

switch (request)
{
    case "--decode":
        Console.WriteLine($"Decoded Text: {decoder.Decode(text)}");
        break;
    case "--encode":
        Console.WriteLine($"Encoded Text: {encoder.Encode(text)}");
        break;
    default:
        Console.WriteLine("Error: unknown request. Exiting...");
        System.Environment.Exit(1);
        break;                             
}
```

### Example
