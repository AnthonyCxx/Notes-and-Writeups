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
//Class
class HelloWorld
{
    //Main Function
    static void Main(string[] args)
    {
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

## Non-Primitive Data Types
### Arrays
```C#
//Declare an array of students
string[] students = {"Henry", "Charlie", "Seth"};

//Declare a two-dimensional array (3 x 3)
int[,] ticTacToeBoard = new int[3, 3];

//Declare and initialize a two-dimensional array
string[,] numberNames = new string[3, 2] { { "one", "1" }, { "two", "2" }, { "three", "3" } };
```
> Note: To make an array of different datetypes, set the datatype to _object[]_ <br />
> Note: Arrays are dynamic in C# unless a size limit is set. <br />
> Note: Add a comma inbetween the \[ \] to add another dimension to the array

# I/O Operations
## Printing
```C#
//Print (without implicit \n)
Console.Write("");

//Print (with implicit \n)
Console.WriteLine("");

//Using variables with Print Statements
Console.Write("Enter your name: ");
string name = Console.ReadLine();
Console.WriteLine("Hello, " + name); 
```

## Reading
```C#
Console.ReadLine();
```
> Note: Data may be read as a string? Similarly to Python...
