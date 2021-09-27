# Reference Notes for C#
This is not meant to be a tutorial for C#, only reference notes for people who already know a C-family language. <br />
If it's not explicitly listed here, assume it's the same as C/C++.

# IDE/Code Environment
If you're building a C# program, you really should be using [Visual Studio](https://visualstudio.microsoft.com/) or [Visual Studio Code](https://code.visualstudio.com/).

# Building Self-Contained Executables via the Commandline with dotnet (.NET)
Self-contained executables can be run on other computers without needing typical external dependencies. <br />
Below is how to create a self-contained executable if you aren't using Visual Studio (see: [the easy way](https://stackoverflow.com/questions/1057878/how-to-compile-the-finished-c-sharp-project-and-then-run-outside-visual-studio)).

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
Publishing a project contains a [self-contained executable](https://gunnarpeipman.com/dotnet-core-self-contained-executable/) that can be run on a specific OS and CPU combo
without needing to install .NET Core (for example, x86-64 Windows).
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
    {                                //instance of the 'HelloWorld' class to be able to call it
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
> Note: Use [PascalCase](https://techterms.com/definition/pascalcase) for method names <br />
> Reference: [C# Documentation: Static Classes and Methods](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)

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

Console.WriteLine(Sqrt(9));
```
Furthermore, you can alias namespace declarations with the _=_ operator.
```C#
using System;
using static mth = System.Math;  //'mth' is an alias for 'System.Math'

Console.WriteLine(mth.Sqrt(9));
```
