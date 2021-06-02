# Type Casting in C#
C# provides a class, [_System.Convert_](https://docs.microsoft.com/en-us/dotnet/api/system.convert?view=net-5.0), that allows you to convert base datatypes (ints, doubles, chars) into each other via the class methods. I will not cover every datatype here, only the common ones. Reference [this Microsoft guide](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/) and go under _'Methods'_ on the left-hand side for all the methods.

## .ToBoolean()
_.ToBoolean()_ throws an exception when converting _char_ or _datatime_ variables.

### Conversion Requirements
- Numeric Types: _.ToBoolean()_ will return false if the number is 0, otherwise true
- Strings: _.ToBoolean()_ returns true if the string is "true" (case insensitive)

