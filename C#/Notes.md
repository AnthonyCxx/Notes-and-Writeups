# Reference Notes for C#
This is not meant to be a tutorial for C#, only reference notes for people who already know a C-family language. <br />
If it's not explicitly listed here, assume it's the same as C/C++.

# Compiling and Running on the Commandline with [Mono](https://kozmicluis.com/compile-c-sharp-command-line/)
## Compiling 
```bash
mcs -out:hello.exe hello.cs
```
## Running
```bash
mono hello.exe
```
> Note: you can apparently also do `./<executable>`; however, this has resulted in some runtime errors for me. Always use _mono_.

# Building Self-Contained Executables with dotnet (.NET)
Self-contained executables can be run on other computers without needing typical external dependencies.

## Creating a Project
```
//Format 
dotnet new <Application Type> -n <Project Name>

//Example
dotnet new Console -n HelloWorld
```

## Building a Project
```
//Format
dotnet build <Program Name>.csproj

//Example
dotnet build HelloWorld.csproj
```
> Note: the result will be under _/bin/Debug_

## Running a Project
```
//Format
dotnet run <Application Name>

//Example
dotnet run HelloWorld
```

## Publishing the Project
```
//Format
dotnet public -r <RID> -p:PublishSingleFile=true --self-contained true

//Example
dotnet publish -r win-x64 -p:PublishSingleFile=true --self-contained true
```
> Replace _\<RID\>_ with the appropriate [runtime identifier](https://docs.microsoft.com/en-us/dotnet/core/rid-catalog) (RID)

# C# Program Structure
```C#
using System;    //This part is optional -- it's 'using namespace std;' in C++

//Class
class HelloWorld
{
    //Main Function
    static void Main(string[] args)   //'Main' method is static, so you do not have to have an
    {                                //instanceoof the 'HelloWorld' class to be able to call it
        //Program
        GreetUser("Jason");
    }
    
    //Declaring a method 
    static void GreetUser(string name)
    {
        //Method contents
        System.Console.WriteLine("Hello, " + name);
    }
}
```
> Note: args\[0\] in C# is not the program name, but the first commandline argument <br />
> Note: Use [PascalCase](https://techterms.com/definition/pascalcase) for method names

## Comments
Comment Styles in C#
| Comment Type | Syntax |
| ------------ | ------ | 
| C# Single-line Comment | // |
| C# Multi-line Comment | /* \*/ |
| XML Single-line Comment | /\*\* \*\*/ |
| XML Multi-line Comment | /// |

## Declaring a Namespace

C# allows you to declare a namespace using the _using_ keyword.
```C#
using System;

//Shortcut instead of having to write "System.Console.WriteLine()"
Console.WriteLine("some text");
```
If you want to use individual members of a namespace, add _static_ after the _using_ keyword
```C#
using System;
using static System.Math; 
//Allows for writing "Sqrt()" instead of "System.Math.Sqrt()"

Console.WriteLine( Sqrt(9) );
```
Furthermore, you can alias namespace declarations with the _=_ operator.
```C#
using System;
using static mth = System.Math;  //'mth' is an alias for 'System.Math'

Console.WriteLine( mth.Sqrt(9) );
```
