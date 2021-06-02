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
Booleans are converted to 1 (true) or 0 (false). <br />

### Conversion Requirements
- Numeric Types: throws an overflow error if the number is out of the range of a byte (-128 to 127)
- Strings: throws a runtime error if the string contains non-numbers or the number is out of the range of a byte (-128 to 127)

## .ToChar()
_.ToChar()_ converts an integer value into a valid UTF-16 character. <br />
_.ToChar()_ throws an exception when converting a _Single_ (float), _Double_, _Decimal_, _DateTime_, or _Boolean_ variable.

### Conversion Requirements
- Integral Types: the integer must be between U+0000 and U+FFFF (0 to 65535)
