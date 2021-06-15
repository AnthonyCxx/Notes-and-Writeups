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
