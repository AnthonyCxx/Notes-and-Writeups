# Arrays in C#
An array is a data structure that stores multiple values of the same type. <br />
These values can be accessed individually, but the [index](https://www.pcmag.com/encyclopedia/term/index) must be known. <br />

## Declaring an Array
```C#
//Declare an integer array that holds 10 elements
int[] exampleArray = new int[10];

//Declare an array with the given elements
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

## Accessing Array Elements
```C#
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

Console.WriteLine( exampleArray[0] );  //Position 0 is item 1
Console.WriteLine( exampleArray[4] );  //Position 4 is item 5
Console.WriteLine( exampleArray[9] );  //Position 9 is item 10
```
> Prints: <br />
> 1  <br />
> 5  <br />
> 10 <br />

## Multi-dimensional Arrays
Arrays can have more than one [dimension](https://softwareengineering.stackexchange.com/questions/246803/what-defines-the-dimensionality-of-an-array). To add another dimension
to an array, add a comma in the declaration and specify the amount of elements. <br />

For reference, a 1D array is called a vector (caution, this is also the name of another data structure), a 2D array is called a matrix, and a 3D array is called a tensor.
```C#
//Declare a two-dimensional array (3 x 3)
int[,] ticTacToeBoard = new int[3, 3];
//  ^ Add another comma for each dimension of the array

//Declare and initialize a two-dimensional array
string[,] nameAndGrade = new string[3, 2] { { "Lucian", "100" }, { "Ella", "97" }, { "Garret", "62" } };

//Get the name and score of the first student
Console.WriteLine($"Student {nameAndGrade[0, 0]} recieved a {nameAndGrade[0, 1]}");
```
> Prints: "Student Lucian recieved a 100" <br />
> Note: the above could be better written as an array of tuples: <br />
>  _Tuple<string, int>[] nameAndGrade = new Tuple<string, int>[3];_

## Accessing by Range and Negative Index
### Accessing by Range
The range operator _.._ allows for referencing sections of the array by index.
```C#
//An array of 7 integers, 1-7
int[] array = { 1, 2, 3, 4, 5, 6, 7 }

//Start at index 0 and stops before index 7 (grabs 7 items)
Console.WriteLine( String.Join(", ", array[0..7]) );   //prints '1, 2, 3, 4, 5, 6, 7'

//Start at index 2 and stop before index 5
Console.WriteLine(String.Join(", ", array[2..5]));  //prints '3, 4, 5'

//Start at index 0 (implied) and stop at the final index (implied)
Console.WriteLine(String.Join(", ", array[..]));    //prints '1, 2, 3, 4, 5, 6, 7'

//Start at index 0 (implied) and stop at index 4
Console.WriteLine(String.Join(", ", array[..4]));  //prints '1, 2, 3, 4'

//Start at index 3 and stop at the final index (implied)
Console.WriteLine(String.Join(", ", array[3..]));    //prints '4, 5, 6, 7'
```
> The last index is exclusive, which allows for statements such as _array[0..array.Length]_, which grabs all values

### Accessing by Range and Negative Indexing
```C#
//This example code has been taken from the C# documentation linked below
var array = new int[] { 1, 2, 3, 4, 5, 6, 7 };
var slice1 = array[2..^3];    //Index 2 to 3rd to last: (3, 4)
var slice2 = array[..^3];     //Index 0 to 3rd to last: (1, 2, 3, 4)
var slice3 = array[2..];      //Index 2 to last element:  (3, 4, 5, 6, 7)
var slice4 = array[..];       //Index 0 to last index: (1, 2, 3, 4, 5, 6, 7)
```
> Reference: [C# Documentation: Ranges and Indices](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/proposals/csharp-8.0/ranges)

## Arrays with Values of Different Types
Since C# has a [_unified type system_](https://stackoverflow.com/questions/4233112/what-is-a-unified-type-system), all datatypes, including primitive datetypes, have an underlying _object_ datatype that they inherit from. Using the _object_ type as the datatype for the array allows an array to have varying datatypes.
```C#
object[] exampleArray = {"name", 10.5, 100};
            
Console.WriteLine( string.Join(", ", exampleArray) );
```
> Prints "name, 10.5, 100"

## Printing Out All the Elements of an Array
There are two main ways to print out all the values of an array: 
1. Using a _for_ or _foreach_ loop
2. Using the _string.Join()_ method

### Using a _for_/_foreach_ Loop
```C#
//With a for loop
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            
for(int i = 0; i < exampleArray.Length; i++)
{
    Console.Write(i + " ");
}

//With a foreach loop
foreach (int element in exampleArray)
{
    Console.Write(element + " ");
}
```

### Using the _string.Join()_ Method\
```
//Using the string.Join method
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//Here, string is an anoymous variable (not an anonymous type)
Console.WriteLine( string.Join(" ", exampleArray) );
```
> Prints: "1 2 3 4 5 6 7 8 9 10"
