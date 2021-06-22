# Preprocessor Directives in C#
This is not a full list of preprocessor directives. I did exclude the [_#pragma checksum_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives#pragma-checksum) directive because of my ignorance.

## Defining Symbols
The following conditional directives take parameters in the form of symbols. Symbols are defined in the format `#define <symbol>`. After a symbol has been defined, 
any conditional evaluation will evaluate to true. Symbols can be undefined with `#undef <symbol>`.
```C#
#if !MAIN_FUNCTION          //If 'MAIN_FUNCTION' is not defined, continue until '#endif'
#define MAIN_FUNCTION      //Define 'MAIN_FUNCTION' so that it will be not be compiled twice
using System;

namespace Main_Function
{
    class Program
    {
        static void Main()
        {
           //Code
        }
    }
}
#endif      //End the 'if' block
```

## Conditionals
The _#if_, _#elif_, _#else_, and _#endif_ preprocesor directives regulate whether sections of code should be complied or not. 
Often, an _#if !\<expression\>_, _#define \<expression\>_, _#endif_ structure is used to prevent code from being compiled more than once if it is included in multiple files.
This technique has been replaced with _#prgama once_ nowadays.

```C#
#if !MAIN_FUNCTION          //If 'MAIN_FUNCTION' is not defined, continue until '#endif'
#define MAIN_FUNCTION      //Define 'MAIN_FUNCTION' so that it will be not be compiled twice
using System;

namespace Main_Function
{
    class Program
    {
        static void Main()
        {
           //Code
        }
    }
}
#endif      //End the 'if' block
```
> In this case, it doesn't make much sense to include the guards since this snippet contains the main function; normally, it would be used in other files.

## Regions
_Regions_ define sections of collapsable code within the [Visual Studio IDE](https://visualstudio.microsoft.com/). Regions are often used in larger projects
with large files so the developer can focus on the relevant sections. Regions start with a _#region \<Name\>_ directive and end with an _#endregion_ directive.
You can nest regions by putting one inside the other. The _#endregion_ directives will figure themselves out.
```C#
#region BoxClass
public class Box
{
    public double Length { get; init; }
    public double Width { get; init; }
    public double Height { get; init; }

    public double Area { get { return Length * Width * Height; } }

    public double SurfaceArea { get { return 2 * ( Length * Width + Length * Height + Height * Width); } }

    #region BoxConstructor
    public Box(double length, double width, double height)
    {
        Length = length;
        Width = width;
        Height = height;
    }
    #endregion
}
#endregion
```
> Note: The _Box_ class is now collapsable as is its constructor, BoxConstructor.

## Enabling/Disabling Nullable Reference Types
There are three directive for allowing/disallowing [nullable reference types](https://docs.microsoft.com/en-us/dotnet/csharp/nullable-references): _#nullable enable_, _#nullable disable_, and _#nullable restore_.

| Command | Result |
| ------- | ------ |
| _#nullable enable_ | sets the nullable annotation context and nullable warning context to enabled |
| _#nullable disable_ | sets the nullable annotation context and nullable warning context to disabled |
| _#nullable restore_ | restores the nullable annotation context and nullable warning context to the project settings |
| _#nullable disable warnings_ | set the nullable warning context to disabled |
| _#nullable enable warnings_ | set the nullable warning context to enabled |
| _#nullable restore warnings_ | restores the nullable warning context to the project settings |
| _#nullable disable annotations_ | set the nullable annotation context to disabled |
| _#nullable enable annotations_ | set the nullable annotation context to enabled |
| _#nullable restore annotations_ | restores the annotation warning context to the project settings |
> This table has been directly taken from the [C# Documentation: Nullable Contexts] <br />
> Reference: [C# Documentation: _#nullable_ Preprocessor Directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives#nullable-context).

## Errors/Warnings
The _#error_ and _#warning_ directives allow the user to manually create errors and warnings.

### Errors
```C#
#error This program is not finished. This warning prevents compilation.
using System;

namespace Main
{
    class Program
    {
        static void Main()
        {
           //Code
        }
    }
}
```

### Warnings
```C#
#warning I have not finished the exception handling for this section. Careful.
using System;

namespace Main
{
    class Program
    {
        static void Main()
        {
           //Code
        }
    }
}
```

## Editing Line Numbers

### Manually Setting Lines
The _#line \<integer\>_ directives manually sets the line number. All lines after that count from that number.
```C#
namespace Main
{
    class Program
    {
        static void Main()
        {
            #line 200
            int integer = ;
        }
    }
}
```
> Fails to compile. Error on line 200.

### Hiding Lines
Sections of code can be discounted by using the _#line hidden_ directive. <br /> <br />
Note that "a #line hidden directive doesn't affect file names or line numbers in error reporting. That is, if the compiler finds an error in a hidden block, the compiler will report the current file name and line number of the error." (Reference: [C# Documentation](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives))
```C#
namespace Main
{
    class Program
    {
        static void Main()
        {
            #line 200
            int integer = 10;
            #line hidden
            double val = 20;
            double val2 = 20;
            double val3 = 20;
            #line default
            const decimal PI = 3.14M;
        }
    }
}
```
> Here, the lines for the doubles are not counted.

### Restoring Default Numbering
Normal numbering can be resumed using the _#line default_ directive.
```C#
namespace Main
{
    class Program
    {
        static void Main()
        {
            #line 200
            int integer = 10;
            #line default
            double val = ;
        }
    }
}
```
> Fails to compile. Error on line 10 (double val = ;).

## Pragmas

### Enable/Disable Warnings
```C#
#pragma warning disable CS0219     //Disables warnings for unused variables
#pragma warning disable C4464     //Disable warning against C++ '#include' directive including a '..'

public static void Main(string[] args)
{
    var unusedVariable = "this would normally generate a warning";   //typically error no. CS0219
}
```
> Note: notice how errors related to C# begin with '_CS_' and errors related to C++ start with '_C_' <br />
> Reference: [C# Documentation: Master List of Compiler Warnings/Errors](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-messages/)
