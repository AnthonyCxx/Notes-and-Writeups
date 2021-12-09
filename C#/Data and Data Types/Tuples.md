# Tuples in C#
> [Tuple vs ValueTuple](http://taswar.zeytinsoft.com/c-what-is-the-difference-between-valuetuple-and-tuple/) <br />

A tuple is an immutable data structure that contains two or literals or variables, which may be of different types. <br />
Tuples are heap-allocated, so don't overuse them.
> [Immutable](https://www.merriam-webster.com/dictionary/immutable), opposite of _mutable_: unable to be changed (think _mut_- as in _mutate_)

The most common use of a tuple is to [return multiple values from a function](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/value-tuples#use-cases-of-tuples).

## Declaring a Tuple
### Format
```C#
Tuple<datatype, datatype> name = new Tuple<datatype, datatype>(value1, value2);
```

### Example
```C#
//Default method
Tuple<int, int, int> exampleTuple = Tuple<int, int, int>(1, 2, 3);

//Using the .Create() method
Tuple<int, int, int> exampleTuple = Tuple.Create(1, 2, 3);

//Using the var keyword
var HelloWorldTuple = Tuple.Create("Hello,", " world!");
```
> Tip: consider using the [_var keyword_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/Keywords.md#var) when declaring a tuple.

## Accessing Data Members of a Tuple
Data members of a tuple are public and can be accessed in the format _.Item[index]_.
```C#
Tuple<string, string> HelloWorldTuple = Tuple.Create("Hello,", " world!");
            
Console.Write(HelloWorldTuple.Item1);
Console.Write(HelloWorldTuple.Item2);
```
> Prints "Hello, World!"

## Declaring Variables as the Values of a Tuple
It's possible to declare variables of varying type, directly taking on the datatype of the element in the tuple. 

```C#
//Declare three variables of type var, which all become strings (they can be different types)
var(name, signInTime, signOutTime, _) = ("Eren", "10:40 AM", "8:00 PM", "0bba2e0a-0212-4a88-977d-10eddab87cae");
                
Console.WriteLine($"Name: {name}");  
Console.WriteLine($"Clock-in Time: {signInTime}");   
Console.WriteLine($"Clock-out Time: {signOutTime}")
```
> Note: The _\__ (underscore) was used to discard a part of the tuple - the record number. <br />
> 
> Prints: <br />
> Name: Eren <br />
> Clock-in Time: 10:40 AM <br />
> Clock-out Time: 8:00 PM <br />

## Nesting Tuples
Tuples can even hold other tuples.
```C#
Tuple<string, int> NameAndAge = new Tuple<string, int>("Jeremy", 32);
Tuple< Tuple<string, int>, string > PersonAndProfession = new Tuple< Tuple<string, int>, string >(NameAndAge, "Construction Worker");
            
Console.WriteLine($"Name: {PersonAndProfession.Item1.Item1}");
Console.WriteLine($"Age: {PersonAndProfession.Item1.Item2}");
Console.WriteLine($"Occupation: {PersonAndProfession.Item2}");
```
> Prints: <br />
> Name: Jeremy <br />
> Age: 32 <br />
> Occupation: Construction Worker <br />

## Examples of Use Cases of Tuples

### Swapping Variables
```C#
int x = 10, y = 20;
Console.WriteLine($"Values before swapping: x = {x}, y = {y} ");

//Swap variables
(x, y) = (y, x);   //Now, x = 20, y = 10
            
Console.WriteLine($"Values after swapping: x = {x}, y = {y} ");
```

### Returning Multiple Values from a Function
```C#
int minimum, maximum;
            
int[] array = {6, -10, 9, 15, 221};
            
(minimum, maximum) = findMinMax(array);
            
Console.WriteLine($"Minimum = {minimum}, Maximum = {maximum}");            

//Function: findMinMax - finds the minimum and maximum value of an array
public static Tuple<int, int> findMinMax(int[] array)
{
    int min = array[0], max = array[0];
            
    foreach(int value in array)
    {
        if (min > value)
        {
            min = value;
        }
                
        if (max < value)
         {
            max = value;
         }
     }
            
     return Tuple.Create(min, max);
}
```
> Prints "Minimum = -10, Maximum = 221" <br />
> Reference: [_foreach_ loop](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ControlFlow/Loops.md#foreach-statement)
