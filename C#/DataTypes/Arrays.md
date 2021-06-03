# Arrays in C#
An array is a data structure that stores multiple values of the same type. <br />
These values can be accessed individually, but the [index](https://www.pcmag.com/encyclopedia/term/index) must be known. <br />

## Declaring an Array
```C#
//Declare an integer array that holds 10 integers
int[] exampleArray = new int[10];

//Declare an array with the given elements
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


//Declare a two-dimensional array (3 x 3)
int[,] ticTacToeBoard = new int[3, 3];

//Declare and initialize a two-dimensional array
string[,] numberNames = new string[3, 2] { { "one", "1" }, { "two", "2" }, { "three", "3" } };
```
> Note: To make an array of different datetypes, set the datatype to _object[]_ <br />
> Note: Arrays are dynamic in C# unless a size limit is set. <br />
> Note: Add a comma inbetween the \[ \] to add another dimension to the array

## Arrays with Values of Different Types
Since C# has a [_unified type system_](https://stackoverflow.com/questions/4233112/what-is-a-unified-type-system) all datatypes, including primitive datetypes, have an underlying
_object_ datatype that they inherit from. Using the _object_ type as the datatype for the array allows an array to have varying datatypes.
```C#
object[] exampleArray = {"name", 10.5, 100};
            
Console.WriteLine( string.Join(", ", exampleArray) );
```
> Prints "name, 10.5, 100"
