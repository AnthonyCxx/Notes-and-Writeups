# Operators in C#

## Is Operator
The _is_ operator does two things:
1. "checks if the result of an expression is compatible with a given type"
2. "matchs an expression against a [pattern](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/patterns#property-pattern)"
> Reference: [C# Documentation: is Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/is)

### Format
```C#
//Format
[expression] is [type]

//Example
someVar is bool;
```

### Example
```C#
//Data Validation
if (result is not null)
{
    Console.WriteLine(result.ToString());
}
```
> _result_ cannot be null, because invoking a method on a null value results in a [NullReferenceException](https://docs.microsoft.com/en-us/dotnet/api/system.nullreferenceexception?view=net-5.0)
