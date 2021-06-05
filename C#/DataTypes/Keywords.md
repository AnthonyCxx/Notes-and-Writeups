# Keywords in C#

## Var
The _var_ keyword is a variable 'type' that makes the compiler infer the datatype of the variable. <br />
The variable will still be strongly typed, but using the _var_ keyword allows you to avoid having to write out long type names. <br />
You may recognize _var_ as the C# equivalent of C++'s [_auto_](https://www.learncpp.com/cpp-tutorial/the-auto-keyword/) keyword.

### Format
```C#
var [identifer];
```

### Example
```C#
//Declare a <string, int, string, int, string, int> tuple
var NameAndDigit = new Tuple<string, int, string, int, string, int>("one", 1, "two", 2, "three", 3);
```
> For a tuple like this, you really should use a [dictionary](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2?view=net-5.0). I am just using this as an example of when to not write the whole type. <br />
> Reference: [What is a Tuple?](https://www.tutorialsteacher.com/csharp/csharp-tuple) <br />
> Reference: [C# Documentation: Var Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)

## Ref
When passing [value types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/built-in-types) as a parameter to a function, the actual variable
itself is not passed, but only a copy of its contents. This means that anything that happens to the value passed will not affect the actual variable in main. To pass by 
reference, you have to use the [_ref keyword_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref) in both the function declaration and when calling
the function.

```C#
//Declare a integer, 10
int number = 10;

//Calling by value (does nothing)
Console.WriteLine($"Integer value BEFORE calling by value: {number}");

IncrementIntegerByValue(number);

Console.WriteLine($"Integer value AFTER calling by value: {number}");

//Separator: newline
Console.WriteLine("");

//Calling by reference (affects the value in main)
Console.WriteLine($"Integer value BEFORE calling by reference: {number}");

IncrementIntegerByReference(ref number);

Console.WriteLine($"Integer value AFTER calling by reference: {number}");


//Increment integers - same implementation, but parameters are different
static void IncrementIntegerByValue(int integer)
{
   integer++;
}

static void IncrementIntegerByReference(ref int integer)
{
   integer++;
}
```
> Prints: <br />
> Integer value BEFORE calling by value: 10 <br /> 
> Integer value AFTER calling by value:  10 <br />
>
> Integer value BEFORE calling by reference: 10 <br />
> Integer value AFTER calling by reference:  11 <br />
> Reference: [C# Documentation: Passing by Reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref)
