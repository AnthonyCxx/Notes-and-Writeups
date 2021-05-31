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

# C# Program Structure
```C#
//Classes to include (think of these as header files)
using System;    //Includes I/O Operations and more

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
        Console.WriteLine("Hello, " + name);
    }
}
```
> Note: Use [PascalCase](https://techterms.com/definition/pascalcase) for method names

# C# Data Types

## Primitive Data Types
| Data Type | Bytes | Minimum Value | Maximum Value | Default Value |
| --------- | ----- | ------------- | ------------- | ------------- |
| bool | 1 | true | false | false |
| char | 2 | 0 | 65,535 | \0 |
| sbyte | 1 | -128 | 127 | 0 | 
| byte | 1 | 0 | 255 | 0 |
| short | 2 | -32,768 | 32,767 | 0 |
| ushort | 2 | 	0 | 65,535 | 0 |
| int | 4 | -2,147,483,648 | 2,147,483,647 | 0 |
| uint | 4 | 0 | 4,294,967,295 | 0 |
| long | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 0 |
| ulong | 8 | 0 | 18,446,744,073,709,551,615 |0  |
| float | 4 | -3.402823 x 10^38 | 3.402823 x 10^38 | 0 |
| double | 8 | -1.79769313486232 x 10^308 | 1.79769313486232 x 10^308 | 0 |
| decimal | 16 | ±1.0 × 10^−28 | ±7.9 × 10^28 | 0 |
> Note: private variables should have a `_` prepended (per industry standard, not my opinion)

## Non-Primitive Data Types
### Arrays
```C#
//Declare an array of students
string[] students = {"Henry", "Charlie", "Seth"};

//Print the array is a comma-separated string
Console.WriteLine(string.Join(", ", students));

//Declare a two-dimensional array (3 x 3)
int[,] ticTacToeBoard = new int[3, 3];

//Declare and initialize a two-dimensional array
string[,] numberNames = new string[3, 2] { { "one", "1" }, { "two", "2" }, { "three", "3" } };
```
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

