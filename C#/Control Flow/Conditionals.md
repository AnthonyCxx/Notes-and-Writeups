# Conditional Statements in C#
Conditionals are control structures that allow you to control the flow of a program based on certain (boolean) criteria. <br />
If the condition is true, then the statments within the _{ }_ will be executed; otherwise, no code will be executed and the program will continue on. <br /> 

If you forget to include the _{ }_, then the _if_ statement will only affect the statement that directly follows it. <br />
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
    //Not executed even though the first if statement is false, because 1 does not equal 2
    System.Console.WriteLine("Hmm, the item may be a book...");
}
else
{
    //IS executed, because 'isBook' is false and the else if statement above failed
    Sysmtem.Console.WriteLine("The item is NOT a book!");
}
```

## Switch Statment
The _switch_ statment allows for evaluating a variable or expression in a clear and structured manner. Switch statements can execute multiple cases, but only [using _goto_
statements](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ControlFlow/Keywords.md#fall-through-behavior-with-goto). An example of a use for a switch statement 
would be [NPC dialogue](https://learn.unity.com/tutorial/switch-statements#5c8a6f91edbc2a067d4753d4) that is based on an in-game value, such as the intelliegence of the 
player character.


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
    case someValue4:
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

### Type-based Switch Statement

```C#
static void Main(string[] args)
{   
            //Prints the integer '123'
            Console.WriteLine( ToInt("123") );   
}

static int ToInt(object number)
{
    switch (number)
    {
        case double d:
            return Convert.ToInt32(d);

        case string s:
            return Int32.TryParse(s, out int x) ? x : 0;
                    
        default:
            return 0;
    }
}
```
> [C# Switch on Type](https://systemoutofmemory.com/blogs/the-programmer-blog/c-sharp-switch-on-type) <br />
> StackOverflow: [Switch on Type](https://stackoverflow.com/questions/298976/is-there-a-better-alternative-than-this-to-switch-on-type) <br />

## The Ternary Operator (? :)
The ternary operator (as opposed to binary or unary operators) takes a condition and evaluates it; if the condition is true, it returns the first expression; if not,
it returns the second expression. Think of the ternary operator as a simplified version of a standard _if_-_else_ conditional structure.

### Format
```C#
expression ? value1 : value2
```

### Example
```C#
decimal pi = 3.14;
decimal sqrt5 = Math.Sqrt(5);
string result = (pi > sqrt5) ? "Pi is greater than the square root of 5" : "Pi is less than the square root of 5";

Console.WriteLine(result);
```
> Prints "Pi is greater than the square root of 5", as 3.14 is greater than 2.24
