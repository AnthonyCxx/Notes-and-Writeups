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

## Jagged Arrays
In a standard array, each row _must_ have the same amount of columns; however, this can be worked around if you make a 1-dimensional array where each index
is another array. That way, each row has its own amount of columns. <br />

The following example has been taken directly from Microsoft's C# Documentation, which is linked below.
```C#
//Declare an array of 3 arrays
int[][] jaggedArray = new int[3][];

//Declare and initialize the individual arrays
jaggedArray[0] = new int[] { 1, 3, 5, 7, 9 };
jaggedArray[1] = new int[] { 0, 2, 4, 6 };
jaggedArray[2] = new int[] { 11, 22 };

//Access the second element of the third array
Console.WriteLine($"The second element in the third array is: {jaggedArray[2][1]}");
```
> Note: Instead of using standard multi-dimensional array syntax _\[2, 1\]_, here the sets of brackets are separate since they are different arrays. <br />
> Reference: [C# Documentation: Jagged Arrays](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/arrays/jagged-arrays)

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
> Note: the last index is exclusive, not inclusive.

### Accessing by Negative Index
The negative index refers to the element **n**th element from the end of the array and is denoted by the [_^_ unary operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/proposals/csharp-8.0/ranges#systemindex). Unlike normal indicies, negative indices are not zero-indexed. _^1_ refers to the
final index of an array.
```C#
var array = new int[] { 1, 2, 3, 4, 5, 6, 7 };

//prints '7', the last element
Console.WriteLine( array[^1] );

//prints '1', the first element
Console.WriteLine( ^array.Length );
```
> To refer to the final index, use _^array.Length_

### Accessing by Range and Negative Indexing
```C#
//This example code has been taken from the C# documentation linked below
var array = new int[] { 1, 2, 3, 4, 5, 6, 7 };

//Start at index 2 and stop at the third to last 
Console.WriteLine(String.Join(", ", array[2..^3]))   //prints '3, 4'

//Start at index 0 (implied) and end at the 5th to last
Console.WriteLine(String.Join(", ", array[..^5]))   //prints '1, 2'
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
