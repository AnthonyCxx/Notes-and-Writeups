# Keywords in C#

## Var
The _var_ keyword is a variable 'type' that makes the compiler infer the datatype of the variable. <br />
The variable will still be strongly typed, but using the _var_ keyword allows you to avoid having to write out long types.

### Format
```C#
var [identifer];
```

### Example
```C#
//Declare a <string, int> tuple
var NameAndDigit = new Tuple<string, int, string, int, string, int>("one", 1, "two", 2, "three", 3);
```
> For a tuple like this, you really should use a [dictionary](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2?view=net-5.0). I am just using this as an example of when to not write the whole type <br />
> Reference: [What is a Tuple?](https://www.tutorialsteacher.com/csharp/csharp-tuple) <br />
> Reference: [C# Documentation: Var Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)
