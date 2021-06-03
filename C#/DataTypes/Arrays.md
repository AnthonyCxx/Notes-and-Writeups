# Arrays in C#
An array is a data structure that stores multiple values of the same type. <br />
These values can be accessed individually, but the [index](https://www.pcmag.com/encyclopedia/term/index) must be known. <br />

## Declaring an Array
```C#
//Declare an integer array that holds 10 integers
int[] exampleArray = new int[10];

//Declare an array with the given elements
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```
> Note: Arrays are dynamic in C# unless a size limit is set. <br />
> Note: Add a comma inbetween the \[ \] to add another dimension to the array

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

//Declare and initialize a two-dimensional array
string[,] nameAndGrade = new string[3, 2] { { "Lucian", "100" }, { "Ella", "97" }, { "Garret", "62 } };
```
> Note: the above could be better written as _Tuple<string, int>[] nameAndGrade = new Tuple<string, int>[3];_

## Arrays with Values of Different Types
Since C# has a [_unified type system_](https://stackoverflow.com/questions/4233112/what-is-a-unified-type-system), all datatypes, including primitive datetypes, have an underlying _object_ datatype that they inherit from. Using the _object_ type as the datatype for the array allows an array to have varying datatypes.
```C#
object[] exampleArray = {"name", 10.5, 100};
            
Console.WriteLine( string.Join(", ", exampleArray) );
```
> Prints "name, 10.5, 100"
