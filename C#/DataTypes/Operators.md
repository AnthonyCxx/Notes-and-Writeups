# Operators in C#

## Is Operator

### Format
```C#
//Format
[expression] is [type]

//Example
someVar is boolean;
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
