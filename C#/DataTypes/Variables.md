# Variables in C#

## Identifiers
An identifier is the name you assign to a type (a variable, constant, class, etc.)

## Value, Reference and Pointer Types
Variables all belong to one of the categories, based on how the data is stored in memory and whether the CLR automatically manages it via [garbage collection](https://docs.microsoft.com/en-us/dotnet/standard/garbage-collection/fundamentals). All primitive types (except for strings) are value types, which means that the 
value of the variable is directly stored in the variable. Reference and pointer types, on the other hand, store the memory address of the object in the variable.
The difference between reference and pointer types is that reference types are automatically managed by the garbage collector, while pointer types are not. <br />

When passing value types as a parameter, the variable itself is not passed, only the value stored in it. Any changes to the copied value will not affect
the original variable. This is not true for reference nor pointer types as they pass the address in memory.

## Global Variables
There are no global variables in C#. However, a public static field in a class is essentially the same thing.
```C#
public static void Main(string[] args)
{
    Console.WriteLine($"OS: {SystemInfo.OSName}");
    Console.WriteLine($"Model: {SystemInfo.Model}");
    Console.WriteLine($"Architecture: {SystemInfo.Architecture}");
    Console.WriteLine($"RAM: {SystemInfo.RAM}");
}

//Class 'SystemInfo' is composed entirely of 'global' variables
class SystemInfo   //Callable with the 'systeminfo' command in Powershell
{
    public static string OSName { get; } = "Microsoft Windows 10 Home";
    public static string  Model { get; } = "GP63 Leopard 8RE";
    public static string Architecture { get; } = "x86_64";    //x86_64 Assembly
    public static int RAM { get; } = 32_614;   //in MB
}
```
> Prints: <br />
> OS: Microsoft Windows 10 Home <br />
> Model: GP63 Leopard 8RE <br />
> Architecture: x86_64 <br />
> RAM: 32614 <br />

## Nullable Value Types
Standard types can be assigned null if a _?_ is appended to the datatype at declaration. The value null should be reserved to indicate an invalid or unknown value.
```C#
//Assigning a value to null
bool  isTall = null;    //Illegal
bool? isTall = null;   //Legal

//Checking for null
if (isTall is null)
{
    isTall = false;
}
```
> Reference: [C# Documentation: Nullable Value Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/nullable-value-types) <br />
> Reference: [C# Documentation: Null Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/null) <br />

## Naming Identifiers after Keywords
Keywords are reserved, and an identifier cannot have the same name as a keyword by default; <br />
however, it is possible to name an identifier after a keyword if you prepend a _@_ during declaration.
```C#
string @event = "Displaying Main Menu";
```
> Note: _event_ is keyword used to "declare an event in a publisher class"
