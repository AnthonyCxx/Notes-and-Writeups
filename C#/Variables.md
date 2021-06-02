# Identifiers in C#
An identifier is the name you assign to a type (a variable, constant, class, etc.)

## Nullable Value Types
Standard types can be assigned null if a _?_ is appended to the datatype at declaration.
```C#
bool  isTall = null;    //Illegal
bool? isTall = null;   //Legal
```
> Reference: [C# Documentation: Nullable Value Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/nullable-value-types)
> Reference: [C# Documentation: Null Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/null)

## Naming Identifiers after Keywords
Keywords are reserved, and an identifier cannot have the same name as a keyword by default; <br />
however, it is possible to name an identifier after a keyword if you prepend a _@_ during declaration.
```#C
string @event = "Displaying Main Menu";
```
> Note: _event_ is keyword used to "declare an event in a publisher class"
