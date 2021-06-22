# Keywords in C#

## Var
The _var_ keyword is a variable 'type' that makes the compiler infer the datatype of the variable. <br />
The variable will still be strongly typed, but using the _var_ keyword allows you to avoid having to write out long type names. <br />
You may recognize _var_ as the C# equivalent of C++'s [_auto_](https://www.learncpp.com/cpp-tutorial/the-auto-keyword/) keyword.

```C#
//Declare a <string, int, string, int, string, int> tuple
var NameAndDigit = new Tuple<string, int, string, int, string, int>("one", 1, "two", 2, "three", 3);
```
> For a tuple like this, you really should use a [dictionary](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2?view=net-5.0). I am just using this as an example of when to not write the whole type. <br />
> Reference: [What is a Tuple?](https://www.tutorialsteacher.com/csharp/csharp-tuple) <br />
> Reference: [C# Documentation: Var Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)

## Default
The _default_ keyword initializes a variable to [the default value of its datatype](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/README.md), which 
could be false, \0 ([the null character](https://www.rapidtables.com/code/text/ascii-table.html)), 0, or null depending on the type.
```C#
int defaultInt = default;
bool defaultBool = default;
char defaultChar = default;
string defaultStr = default;

Console.WriteLine($"The default value of an integer (and any numeric type) is: {defaultInt}");
Console.WriteLine($"The default value of a bool is: {defaultBool}");
Console.WriteLine($"The default value of a char is: {(defaultChar == '\u0000' ? "\\0" : "not \\0")}"); 
Console.WriteLine($"The default value of a string is: {(defaultStr is null ? "null" : "not null")}");
```
> Prints: <br />
> The default value of an integer (and any numeric type) is: 0 <br />
> The default value of a bool is: False <br />
> The default value of a char is: \0 <br /> 
> The default value of a string is: null <br />
> 
> Note: the ternary operators are necessary because printing null (the default value of chars and strings) prints blank space

## Const
The _const_ keyword allows you to declare a value that cannot be changed. To differntiate constants from variables, many programmers name constants using
all capital letters (which I highly recommend). Constants _must_ be known at compile time and cannot be the result of an expression _unless_ the expression is the 
result of some constants
```C#
const decimal PI = 3.14M;  //'M' literal suffix needed for decimals

Console.WriteLine($"The value of Pi is: {PI}");

PI = 4913784713M;  //Illegal! PI is constant!
```

## Readonly
Like the _const_ keyword, _readonly_ prevents a value from being changed; however, there are some notable differentces. The _readonly_ keyword can only be applied
to [fields](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/fields) (specific data members of a class) and do not need to be known
at compile time (unlike constants). Because of this, _readonly_ fields can be initialized by the constructor of the class or struct it is a part of. However, after 
the constructor has exited, the _readonly_ field is not longer modifiable.
```C#
public static void Main(string[] args)
{
  var villager = new NPC("Skeltos");  
  
  villager.Name = "some cool fantasy name";  //Illegal! '_name' is readonly and 'Name' only has an 'init' modifier
} 

//'NPC' Class
class NPC
{
  private readonly string _name;

  public string Name { get { return _name; } init { _name = value; } }

  public NPC(string name = "error, no name given")
  {
    _name = name;
  }
}
```
