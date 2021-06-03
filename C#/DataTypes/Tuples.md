# Tuples in C#
A tuple is a mutable data structure that contains two or literals or variables, which may be of different types. <br />
The most common use of a tuple is to [return multiple values from a function](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/value-tuples#use-cases-of-tuples).
> [Mutable](https://www.merriam-webster.com/dictionary/mutable), opposite of _immutable_: abled to be changed (think _mut_- as in _mutate_)

## Declaring a Tuple
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

## Examples of Use Cases of Tuples

### Swapping Variables
```C#
int x = 10, y = 20;
Console.WriteLine($"Values before swapping: x = {x}, y = {y} ");

(x, y) = (y, x);   //Now, x = 20, y = 10
            
Console.WriteLine($"Values after swapping: x = {x}, y = {y} ");
```
