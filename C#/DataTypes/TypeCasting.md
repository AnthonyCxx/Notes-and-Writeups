# Type Casting in C#
C# provides a class, [_System.Convert_](https://docs.microsoft.com/en-us/dotnet/api/system.convert?view=net-5.0), that allows you to convert base datatypes (ints, doubles, chars) into each other via the class methods. I will not cover every datatype here, only the common ones. Reference [this Microsoft guide](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/) and go under _'Methods'_ on the left-hand side for all the methods. <br />

Alternatively, you can just put the datatype in from of the variable in parentheses.
```C#
double pi = 3.14;

Console.WriteLine($"The first value of pi is { (int) pi }");
```

## .ToBoolean()
_.ToBoolean()_ throws an exception when converting _Char_ or _DateTime_ variables.

### Conversion Requirements
- Numeric Types: _.ToBoolean()_ will return false if the number is 0, otherwise true
- Strings: _.ToBoolean()_ returns true if the string is "true" (case insensitive)

## .ToByte()
_.ToByte()_ throws an exception when converting _DateTime_ variables. <br />
Additionally, _.ToByte()_ throws a runtime error if the string contains non-numbers or the number is out of the range of a byte (-128 -	127)
