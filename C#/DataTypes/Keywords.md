# Keywords in C#

## Var
The _var_ keyword is a variable 'type' that makes the compiler infer the datatype of the variable. <br />
The variable will still be strongly typed, but using the _var_ keyword allows you to avoid having to write out long type names. <br />
You may recognize _var_ as the C# equivalent of C++'s [_auto_](https://www.learncpp.com/cpp-tutorial/the-auto-keyword/) keyword.

### Format
```C#
var [identifer];
```

### Example
```C#
//Declare a <string, int, string, int, string, int> tuple
var NameAndDigit = new Tuple<string, int, string, int, string, int>("one", 1, "two", 2, "three", 3);
```
> For a tuple like this, you really should use a [dictionary](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2?view=net-5.0). I am just using this as an example of when to not write the whole type. <br />
> Reference: [What is a Tuple?](https://www.tutorialsteacher.com/csharp/csharp-tuple) <br />
> Reference: [C# Documentation: Var Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/var)

## Parameter Modifiers

### Ref
When passing [value types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/built-in-types) as a parameter to a function, the actual variable
itself is not passed, but only a copy of its contents. This means that anything that happens to the value passed will not affect the actual variable in main. To pass by 
reference, you have to use the [_ref keyword_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref) in both the function declaration and when calling
the function.

```C#
//Declare a integer, 10
int number = 10;

//Calling by value (does nothing)
Console.WriteLine($"Integer value BEFORE calling by value: {number}");

IncrementIntegerByValue(number);

Console.WriteLine($"Integer value AFTER calling by value: {number}");

//Separator: newline
Console.WriteLine("");

//Calling by reference (affects the value in main)
Console.WriteLine($"Integer value BEFORE calling by reference: {number}");

IncrementIntegerByReference(ref number);

Console.WriteLine($"Integer value AFTER calling by reference: {number}");


//Increment integers - same implementation, but parameters are different
static void IncrementIntegerByValue(int integer)
{
   integer++;
}

static void IncrementIntegerByReference(ref int integer)
{
   integer++;
}
```
> Prints: <br />
> Integer value BEFORE calling by value: 10 <br /> 
> Integer value AFTER calling by value:  10 <br />
>
> Integer value BEFORE calling by reference: 10 <br />
> Integer value AFTER calling by reference:  11 <br />
> Reference: [C# Documentation: Passing by Reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref)


### In
_In_ is equivalent to _ref readonly_ (an immutable parameter which is passed by reference). Even though you cannot modifiy _in_ parameters, it is important that
the _in_ keyword exists because it allows you to pass large values to functions without creating unnecessary copies. Because _in_ parameters are immutable, they 
must be initialized before being passed.

**WARNING: DO NOT RUN THIS CODE** <br />
This code easily ate 16 GB of RAM. Do _not_ run this.
```C#
public static void Main(string[] args)
{
   // WARNING: DO NOT RUN THIS CODE //
   #error this manual error will prevent code compilation. Do not run this code.

   //Declare an array of 100,000,000 unsigned long integers
   ulong[] array = new ulong[100_000_000];

   //Fill the array with the max value of an unsigned long (18_446_744_073_709_551_615 -- ~18.5 quintillion)
   Array.Fill(array, ulong.MaxValue);

   //Print the array as a comma-separated (cs) string
   PrintArray(array);
}
        
public static void PrintArray(in ulong[] aMassiveArray)  //pass the array by reference and as read-only 
{
   Console.WriteLine( string.Join(", ", aMassiveArray) );
}
```

### Out
_Out_ performs the exact same function as the _ref_ keyword, but _out_ allows you to pass uninitialized variables.

```C#
public static void Main(string[] args)
{
   int num1 = 20, num2 = 30, result;   //notice that 'result' isn't initialized

   Add(num1, num2, out result);   //have to pass 'result' with the 'out' keyword

   Console.WriteLine(result);    
}

//'Add' function
public static void Add(int a, int b, out int result)
{
   result = a + b; 
}
```
> Prints: '50'

### Params
_Params_ allows a function to take a varying amount of parameters. Functions of differing [arity](https://en.wikipedia.org/wiki/Arity) are called 
[variadic functions](https://en.wikipedia.org/wiki/Variadic_function). Variadic functions are exceedingly useful in writing flexable code. This 
flexability can be extended even further by using [generics](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/generics) or the
_object[ ]_ parameter type.

```C#
public static void Main(string[] args)
{
   Console.WriteLine($"The sum of 5, 7, and 9 is: {Sum(5, 7, 9)}");
   Console.WriteLine($"The sum of 1 and 2 is: {Sum(1, 2)}");
}

public static int Sum(params int[] intList)
{
   int result = 0;

   //Add up all the parameters
   foreach (int integer in intList)
   {
      result += integer;
   }

   return result;
}
```
> Prints: <br />
> The sum of 5, 7, and 9 is: 21 <br />
> The sum of 1 and 2 is: 3 <br />
