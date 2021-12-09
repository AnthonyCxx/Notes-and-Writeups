# Arrays in C#
> [Arrays vs Lists](https://csharp-station.com/c-arrays-vs-lists/) <br />
> 
An array is a data structure that stores multiple values of the same type. <br />
These values can be accessed individually, but the [index](https://www.pcmag.com/encyclopedia/term/index) must be known. <br />
If you do not know the index, use the [_.IndexOf_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/Arrays.md#indexof) or [_.LastIndexOf()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/Arrays.md#lastindexof) methods. <br />

## Declaring an Array
```C#
//Declare an integer array that holds 10 elements
int[] exampleArray = new int[10];

//Declare an array using the .CreateInstance() method
Array exampleArray = Array.CreateInstance(typeof(int), 10);

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
In a standard multi-dimensional array, each row _must_ have the same amount of columns; however, this can be worked around if you make an array where each index
is another array. That way, each row has its own amount of columns. And yes, you can make both of the arrays multi-dimensional. Try wrapping your head around that.<br />

The following example has been taken directly from Microsoft's C# Documentation, which is linked below.
```C#
//Declare an array of 3 arrays
int[][] jaggedArray = new int[3][];

//Declare and initialize the individual arrays
jaggedArray[0] = new int[] { 1, 3, 5, 7, 9 };
jaggedArray[1] = new int[] { 0, 2, 4, 6 };
jaggedArray[2] = new int[] { 11, 22 };

//Access the second element of the third array (22)
Console.WriteLine($"The second element in the third array is: {jaggedArray[2][1]}");
```
> Note: Instead of using standard multi-dimensional array syntax _\[2, 1\]_, here the sets of brackets are separate since they are different arrays. <br />
> Note: For jagged arrays, the _.Length_ member returns the amount of arrays. <br />
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
Since C# has a [_unified type system_](https://stackoverflow.com/questions/4233112/what-is-a-unified-type-system), all datatypes, including primitive datatypes, have an underlying _object_ class that they inherit from. Using the _object_ type as the datatype for the array allows an array to have varying datatypes.
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
```C#
//Using the string.Join method
int[] exampleArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//Here, string is an anoymous variable (not an anonymous type)
Console.WriteLine( string.Join(" ", exampleArray) );
```
> Prints: "1 2 3 4 5 6 7 8 9 10"

## Array Properties
| Property | Contains |
| -------- | -------- |
| .Length | the number of elements |
| .Rank | the number of dimensions |
> This is not comprehensive, but [this list](https://docs.microsoft.com/en-us/dotnet/api/system.array.isfixedsize?view=net-5.0) is.

## Array Methods
> Note: Many of these methods only work on one-dimensional arrays. If the method only works with one-dimensional arrays, you will get a [_RankException_](https://docs.microsoft.com/en-us/dotnet/api/system.rankexception?view=net-5.0) when passing in an array with more than one dimension. 

## .GetValue()
The _.GetValue(**_index_**)_ method returns the element at the given index.
```C#
int[] exampleArray = new int[] { 1, 2, 3, 4, 5, 1 };

for (int index = 0; i < exampleArray.Length; i++)
{
    Console.WriteLine($"Index = {index}, Element = {exampleArray.GetValue(index)}");
}
```
> Prints: <br />
> Index = 0, Element = 1 <br />
> Index = 1, Element = 2 <br />
> Index = 2, Element = 3 <br />
> Index = 3, Element = 4 <br />
> Index = 4, Element = 5 <br />
> Index = 5, Element = 1 <br />

## .SetValue()
The _.SetValue(**_value_**, **_index_**)_ method sets the value of an index. <br />
```C#
//Declare an uninitialized array of 3 integers
int[] intArray = new int[3];

//Set the values of the array to 1, 2, and 3
intArray.SetValue(1, 0);
intArray.SetValue(2, 1);
intArray.SetValue(3, 2);

//Print the array
Console.WriteLine(string.Join(", ", intArray));
```
> Prints: '1, 2, 3'

## .IndexOf()
The _Array.IndexOf(**_array_**, **_value_**)_ returns the index of the first instance of the given value. If the value is not in the array, a _-1_ will be returned.
```C#
int[] exampleArray = new int[] { 1, 2, 3, 4, 5, 1 };

int searchValue = 1;
int index = Array.IndexOf(exampleArray, searchValue);

Console.WriteLine($"The first occurance of {searchValue} is at index {index}");
```
> Prints: "The first occurance of 1 is at index 0"

## .LastIndexOf()
The _Array.LastIndexOf(**_array_**, **_value_**)_ method returns the last index of the given value. If the value is not in the array, a _-1_ will be returned.
```C#
int[] exampleArray = new int[] { 1, 2, 3, 4, 5, 1 };

int lastIndexOf1 = Array.LastIndexOf(exampleArray , 1);    //returns 5
int lastIndexOf6 = Array.LastIndexOf(exampleArray , 6);   //returns -1

Console.WriteLine($"The last index of element 1 is: {lastIndexOf1}");
```
> Prints: "The last index of element 1 is: 5"

## .Sort()
The _Array.Sort(**_array_**)_ method sorts an array in [ascending order](https://www.youtube.com/watch?v=jWBglsSb63w). <br />
Portions of the array and the comparer can be manually specified. Refer to the [C# Documentation for _Array.Sort()_](https://docs.microsoft.com/en-us/dotnet/api/system.array?view=net-5.0)
```C#
int[] exampleArray = { 7, 4, 2, 9, 1, 3, 10, 6, 8, 5 };

//Prints: '7, 4, 2, 9, 1, 3, 10, 6, 8, 5'
Console.WriteLine($"Array contents BEFORE sorting: {string.Join(", ", exampleArray)}");

//Sort the array
Array.Sort(exampleArray);

//Prints: '1, 2, 3, 4, 5, 6, 7, 8, 9, 10'
Console.WriteLine($"Array contents AFTER sorting: {string.Join(", ", exampleArray)}");
```

### .BinarySearch()
The _Array.BinarySearch(**_array_**, **_search_element_**)_ performs a [binary search](https://www.geeksforgeeks.org/binary-search/), looking for the provided item. 
If found, the index of the search item is returned; otherwise, a negative number is returned.
```C#
int[] exampleArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int indexOf7 = Array.BinarySearch(exampleArray, 7);

if (indexOf7 < 0)
{
    Console.WriteLine("The element \'7\' was not found in the array");
}
else
{
    Console.WriteLine($"The index of the number \'7\' is: {indexOf7}");
}
```
> Prints: "The index of the number '7' is: 6" <br />
> **IMPORTANT**: a binary search can only be performed on sorted arrays. <br />

## .ForEach()
The _Array.ForEach(**_array_**, **_action_**)_ method performs the given actions on each member of the array individually.
```C#
//An array of 4 palindromes, and one non (nonchalant)
string[] palindromes = new string[5] { "kayak", "rotator", "sagas", "aibohphobia", "nonchalant" };

//Check each word in the array for palindromes. If it is, print it
Array.ForEach(palindromes, printPalindrome);

//Print the word if it's a palindrome
static void printPalindrome(string word)
{
    if (isPalindrome(word))
        Console.WriteLine($"Palindrome found: {word}");
}

//Check if the word is a palindrome
static bool isPalindrome(string word)
{
    //Iterate over the string, comparing the nth and nth-from-last characters 
    for (int i = 0; i < word.Length / 2; i++)
    {
         //If the two characters do not match, return false
         if (word[i] != word[^(i + 1)])
             return false;
    }

   //If all match, return true
   return true;
}
```
> Prints: <br />
> Palindrome found: kayak       <br />
> Palindrome found: rotator     <br />
> Palindrome found: sagas       <br />
> Palindrome found: aibohphobia <br />

## .TrueForAll()
The _Array.TrueForAll(**_array_**, **_predicate_**)_ method returns true if the [predicate](https://docs.microsoft.com/en-us/dotnet/api/system.predicate-1?view=net-5.0) is true for _every_ element in the given array. <br />

```C#
//An array of 4 palindromes, and one non (nonchalant)
string[] palindromes = new string[5] { "kayak", "rotator", "sagas", "aibohphobia", "nonchalant" };

//Return false, since 'nonchalant' is not a palindrome
if (Array.TrueForAll(palindromes, isPalindrome))
     Console.WriteLine("The array \'palindromes\' exclusively conatins palindromes");
else
     Console.WriteLine("The array \'palindromes\' does not exclusively contain palindromes");


static bool isPalindrome(string word)
{
    //Iterate over the string, comparing the nth and nth-from-last characters
    for (int i = 0; i < word.Length / 2; i++)
     {
         //If the two characters do not match, return false
         if (word[i] != word[^(i+1)])
             return false;            
     }

     //If all match, return true
     return true;
}
```
> Note: It is common use to [_lambda expressions_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-expressions) as one-time functions. <br />
> Aibohphobia, noun: the fear of palindromes (yes, it's a palindrome). <br />

## .Fill()
The _Array.Fill(**_array_**, **_value_**)_ method sets every element in the array to the given values. This is especially helpful when initializing an array.
```C#
int[] intArray = new int[30];

Console.WriteLine($"Array values: {string.Join(", ", intArray)}");

Array.Fill(intArray, 5);

Console.WriteLine($"Array values: {string.Join(", ", intArray)}");
```
> Prints: <br />
> Array values: 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 <br />
> Array values: 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 <br />

## .Resize()
The _Array.Resize(ref **_array_**, **_size_**)_ methods resizes an array to the given size.
```C#
int[] exampleArray = new int[3] { 1, 2, 3 };

Console.WriteLine($"The array is {exampleArray.GetUpperBound(0) + 1} elements long");

//Increase the size of the array by 2 (total: 5)
Array.Resize(ref exampleArray, exampleArray.Length + 2);

Console.WriteLine($"The array is {exampleArray.GetUpperBound(0) + 1} elements long");
```
> Prints: <br />
> The array is 3 elements long <br />
> The array is 5 elements long <br />

## .Reverse()
The _Array.Reverse(**_array_**)_ method reverse an array. This takes [O(n) time](https://docs.microsoft.com/en-us/dotnet/api/system.array.reverse?view=net-5.0) where _n_ is the length of the array.
```C#
string[] sentence = new string[] { "this", "is", "a", "sentence" };

Console.WriteLine($"Array BEFORE being reversed: {string.Join(" ", sentence)}");

Array.Reverse(sentence);

Console.WriteLine($"Array AFTER being reversed: {string.Join(" ", sentence)}");
```
> Prints: <br />
> Array BEFORE being reversed: this is a sentence <br />
> Array AFTER being reversed: sentence a is this  <br />
> Reference: [What is O(n)?](https://en.wikipedia.org/wiki/Time_complexity)

## .Clear()
The _.Array.Clear(**_array_**, **_starting\_index_**, **_length_**)_ (where _length_ is the amount of elements to clear) method resets the specified elements of
an array to their initial value (0, for example, with numeric types).
```C#
int[] exampleArray = new int[] { 1, 2, 3, 4, 5 };

Console.WriteLine($"Array BEFORE being cleared: {string.Join(" ", exampleArray)}");

//Clear only the first three elements
Array.Clear(exampleArray, 0, exampleArray.Length);

//Clear all the elements
Array.Clear(exampleArray, 0, exampleArray.Length);

Console.WriteLine($"Array AFTER being cleared: {string.Join(" ", exampleArray)}");
```
> Prints: <br />
> "Array BEFORE being cleared: 1, 2, 3, 4, 5" <br />
> "Array AFTER being cleared: 0, 0, 0, 0, 0"  <br />

## .GetLowerBound()
The _.GetLowerBound(**_dimension_**)_ returns the lowest index of the dimension specified. The lowest index is almost _always_ 0, but [there are some rare cases](https://stackoverflow.com/questions/17358139/getupperbound-and-getlowerbound-function-for-array)
where the lowest index of an array is not 0.
```C#
//A jagged array that stores two, 2-dimensional arrays.
int[][,] jaggedArray = new int[2][,];

//A 2-dimensional array with two rows and 4 columns each
jaggedArray[0] = new int[2, 4] { { 1, 2, 3, 4}, 
                                 { 5, 6, 7, 8 } };

//A 2-dimensional array with two rows and 6 columns each
jaggedArray[1] = new int[2, 6] { { 1, 2, 3, 4, 5, 6 }, 
                                 { 7, 8, 9, 10, 11, 12 } };

//Get the lower bound of the first array in the first 2-dimensional array
Console.WriteLine($"The lowest bound of the first array is:  {jaggedArray[0].GetLowerBound(0)}");

//Get the lower bound of the second array in the second 2-dimensional array
onsole.WriteLine($"The lowest bound of the second array is: {jaggedArray[1].GetUpperBound(1)}");
```
> Prints: <br />
> "The lowest bound of the first array is:  0" <br />
> "The lowest bound of the second array is: 5" <br /> <br />
> Note: Remember, spacing does not matter in C#, so try to line up the rows and columns when initializing a matrix <br />
> (this is practically impossible for tensors).

## .GetUpperBound
The _.GetUpperBound(**_dimension_**)_ returns the highest index of the dimension specified (which is always 1 less than the amount of elements).
```C#
//A jagged array that stores two, 1-dimensional arrays.
int[][] jaggedArray = new int[2][];

//Declare and initialize the individual arrays
jaggedArray[0] = new int[] { 1, 2, 3};
jaggedArray[1] = new int[] { 1, 2, 3, 4, 5, 6, 7 };

Console.WriteLine($"The upper bound of the first array is:  {jaggedArray[0].GetUpperBound(0)}");
Console.WriteLine($"The upper bound of the second array is: {jaggedArray[1].GetUpperBound(0)}");
```
> Prints: <br />
> The upper bound of the first array is:  2 <br />
> The upper bound of the second array is: 6 <br />
