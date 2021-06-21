# Preprocessor Directives in C#
This is not a full list of preprocessor directives. I only intend to highlight the major ones. <br />
For a full list, look [here](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives).

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
#pragma warning disable CS0219    //Disables warnings for unused variables

public static void Main(string[] args)
{
    var unusedVariable = "this would normally generate a warning";   //typically error no. CS0219
}
```
> Reference: [C# Documentation: Master List of Compiler Warnings/Errors](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-messages/)

### Generate Checksum
