# Exception Handling in C#

## Checked Keyword
The _checked_ keyword defines a statement block in which variables cannot exceed their _MaxValue_ without resulting a [_System.OverflowException_](https://docs.microsoft.com/en-us/dotnet/api/system.overflowexception?view=net-5.0) runtime error. Typically, exceeding the maximum value just begins at the minimum value again and continues.
