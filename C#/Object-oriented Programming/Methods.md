# Methods in C#
A method is a function that is associated with a class, record, or struct. Since all C# code is in the context of a class, record, or struct, functions and methods are
synonymous in C#. Methods are blocks of code that can be invoked by name, executing the body of the method (its code). There are two types of methods: instance and static.
By default, methods are instance, which means that they can only be called from an instance of the method's respective class. In these examples, I use the _static_ keyword
a lot; the [static keyword](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Methods.md#static-methods) just means that the method can be called without needed an [object](https://en.wikipedia.org/wiki/Instance_(computer_science)) (instance of a class)
to call it from.
```C#
static void Main(string[] args)
{
    //The method 'Bark' can now be called from any 'Dog' object
    var puppy = new Dog();  
    puppy.Bark();   //prints 'Woof!'
}

public class Dog
{
    //A method 'Bark' in the 'Dog' class, prints 'Woof!'
    public void Bark()   
    {
        Console.WriteLine("Woof!");
    }
}
```

## Anatomy of a Method
The implementation of a method requires all of the following: an [access modifier](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/AccessModifiers.md), a [return type](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Methods.md#the-return-keyword-and-return-types), a name, a [parameter list](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Methods.md#parameters), and a body. In some cases, such as with [interfaces](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Interfaces.md), you will only be asked to declare a method, in which case 
you will not need to supply a body for the method.

```C#
public void printHello()    //Access modifier (public), return type (void), name (printHello), parameter list ( () )
{
    Console.WriteLine("Hello!");  //The code to be executed in { }
}
```
> Use [PascalCase](https://techterms.com/definition/pascalcase) for method names

## The Return Keyword and Return Types
Methods can return a value to wherever it was called. The _return_ keyword returns that value, which could be a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b), a variable, an expression, or even a data structure (an array, tuple, dictionary, etc.). Once the _return_ statement is executed, 
the function ends, regardless of whether there was code after the _return_ statement. Any good compiler should warn you that the code after the _return_ statement is 'dead code' (code that cannot and will not be executed). The datatype
of the value that will be returned must be declared as a part of the method declaration (following the access modifier). Here, the _return5()_ method returns an integer, 5.
If a method does not return any value, then its return type is [_void_](https://www.geeksforgeeks.org/void-keyword-in-c-sharp/). 

```C#
public static void Main(string[] args)
{
    int num = return5();
    Console.WriteLine($"Value of num: {num}");
}

//Method 'return5' returns the integer 5
public static int return5()  
{
    return 5;
}
```
> Prints: 'Value of num: 5'

## Parameters
A function can take [parameters](https://www.thoughtco.com/definition-of-parameters-958124) (also called arguments), which are values that are passed into the function. 
The function can then use these values as variables. When declaring parameters, be sure to declare their type as well. A simple method '_Add_' could take two numbers 
as parameters and return their sum.
```C#
public static void Main(string[] args)
{
    int num = Add(5, 10);     //Instead of literals, you could pass variables
    Console.WriteLine(num);
}

//Method 'Add' adds two numbers
public static int Add(int num1, int num2)  
{
    return num1 + num2;    //The 'return' keyword is always evaluated last
}
```
> Prints: '15' <br />
>
> Note: use [camelCase](https://techterms.com/definition/camelcase) for parameters

## Default Parameters
In the event that a method is called without some or all parameters, measures can be put into place to ensure that each parameter still has some default value.
To add default parameters, simple put an equals sign followed by a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) (some value). That way, the parameter will take on that value if and only if no other value is provided.
```C#
static void Main(string[] args)
{
    Console.WriteLine($"Calling the Add method with the integers 7 and 8 as parameters: {Add(7, 8)}");   //prints 15
    Console.WriteLine($"Calling the Add method with one parameter: {Add(1)}"); //prints 1  (second parameter is implicitly 0)
    Console.WriteLine($"Calling the Add method with no parameters: {Add()}");  //prints 0 (both parameters are implictly 0)
}
        
//'Add' function
public static int Add(int param1 = 0, int param2 = 0)  //both parameters have a default value of 0
{
    return param1 + param2;    
}

```
> Prints: <br />
> Calling the Add method with the integers 7 and 8 as parameters: 15 <br />
> Calling the Add method with one parameter: 1 <br />
> Calling the Add method with no parameters: 0 <br />

## Named Parameters
Parameters can be passed out-of-order by refererring to them by name when passing the arguements like `paramter:argument`.

```C#
static void Main(string[] args)
{
    string fullname = MakeFullName(lastName:"John", firstName:"Doe");  //lastName is now "John", firstName is now "Doe"
            
    Console.WriteLine(fullname);
}

static string MakeFullName(string firstName, string lastName)
{
    return firstName + ' ' + lastName;
}
```
> C# Official Documentation: [Named and Optional Arguments](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/named-and-optional-arguments) <br />
> C# Corner: [Named And Optional Parameters In C#](https://www.c-sharpcorner.com/UploadFile/manas1/named-and-optional-parameter-in-C-Sharp/) <br />

## Constructors
A constructors is a special public method that are automatically run when an instance of the class is created. Constructors do not have a return type and _must_ 
share the name of their class and are often used to initialize the data members of said class. Constructors can be used for more than just initializing data members;
for example, in [my Hangman Game](https://github.com/EthanC2/Hangman/blob/main/header-files/GameClass.hpp) (C++), I put the _run()_ function in the constructor of my
_Game_ class so the game would automatically start when I loaded up the game. Similarly, in a video game constructors may call things like spawn animations or set 
the coordinates of the character. It is possible to combine the default and parameterized constructors by writing a parameterized constructors where each parameter has
a default value. <br />

There are two types of constructors: default and parameterized. The default constructor is called when no values are provided to initialize the new object with, and the
parameterized constructor is called when values are provided. See the example below.
```C#
static void Main(string[] args)
{
    //Invoking the default constructor
    var randomBook = new Book();
            
    //Invoking the parameterized constructor
    var aBookYouShouldRead = new Book("Un Mundo sin Fin", 1179);
}

public class Book
{
    
    public string Title { get; set; }

    public int PageCount { get; set; }

    //Default Constructor
    public Book()      //constructors do not have a return type!
    {
        Title = "A Nameless Book";
        PageCount = 0;
    }

    //Parameterized contructor
    public Book(string title, int pageCount)
    {
        Title = title;
        PageCount = pageCount;
    }
}
```
Functions can share the same name as long as they have different parameters. The computer can discern which function to call based on the data types of the paramters.
This is called [method overloading](https://www.geeksforgeeks.org/c-sharp-method-overloading/#:~:text=Method%20Overloading%20is%20the%20common,methods%20with%20different%20method%20signatures.).
> Reference: [Overloading Methods in C#](https://www.pluralsight.com/guides/overload-methods-invoking-overload-methods-csharp) <br />

## Destructors
Destructors (called _Finalizers_ in C#) are the opposite of constructors. Destructors are called when the object [goes out of scope](https://www.pluralsight.com/guides/understanding-scope-and-visibility-in-c). Like constructors, destructors must share the name of the class; however,
destructors have a single '~' before the class name to differentiate them from constructors. Finalizers are necessary for cleaning up unmanaged resources 
(such as [file handles, sockets or database connections](https://techcommunity.microsoft.com/t5/iis-support-blog/understanding-when-to-use-a-finalizer-in-your-net-class/ba-p/347760)) <br />

Finalizers have a number of things you need to pay close attention to, which are as follows:
- Implementing a finalizer (_~Class_ method) puts the [the finalization queue](https://www.dotnettricks.com/learn/netframework/net-garbage-collection-and-finalization-queue).
- "The exact time when the finalizer executes is undefined. To ensure deterministic release of resources for instances of your class, implement a Close method or provide a [IDisposable.Dispose](https://docs.microsoft.com/en-us/dotnet/api/system.idisposable.dispose?view=net-5.0) implementation."
- "The finalizers of two objects are not guaranteed to run in any specific order, even if one object refers to the other. That is, if Object A has a reference to Object B and both have finalizers, Object B might have already been finalized when the finalizer of Object A starts."
> Quotes & Reference: [C# Documentation: How Finalization Works](https://docs.microsoft.com/en-us/dotnet/api/system.object.finalize?view=net-5.0#how-finalization-works)

```C#
public static void Main(string[] args)
{
    //Create a new book with 300 pages, starting at page 0
    var tome = new MagicBook(300 , 0);
    
    //'tome' object goes out of scope at the end of the program (main function)
} 

//'MagicBook' class
class MagicBook
{ 
    //Properties
    public int PageCount { get; init; }
    public int CurrentPage { get; private set; }

    //Constructor
    MagicBook(int pageCount = 100, int currentPage = 0)   //The 'public' can be omitted. When omitted, public is assumed.
    {
        PageCount = pageCount;
        CurrentPage = currentPage;
    }

    //Destructor
    ~MagicBook()
    {
        Console.WriteLine("The book vanishes into thin air!");   //This message is displayed upon destruction
    }
}
```
> Note: You can combine the default and parameterized constructors by making all of the values in the parameterized constructor default parameters.

## Static Methods
A static method (the opposite of an instance method) is a method that does not require an object of that class in order to be called. Take the _.WriteLine(**_string_**)_ 
method for example. You don't need a _System_ nor a _Console_ object to be able to use _.WriteLine(**_string_**). Because static methods and data members are not 
associated with any object (instance of the class), the _this_ keyword cannot be used with them. <br />

Static methods are extremely useful for creating functional classes - classes that only perform some sort of function.
```C#
static void Main(string[] args)
{
    decimal celsius = TemperatureConverter.ToCelsius(90M);   //'M' literal suffix makes it a decimal literal
    decimal farenheit = TemperatureConverter.ToFahrenheit(13M);

    //Show the results with 2 decimal places
    Console.WriteLine($"90 degrees in Celius (from Farenheit) is: { Math.Round(celsius, 2) }");
    Console.WriteLine($"13 degrees in Farenheit (from Celsius) is: { Math.Round(farenheit, 2) }");
}

public class TemperatureConverter
{  
   //Uses decimal datatype to ensure accuracy.
   public static decimal ToCelsius(decimal temp)
    {
        return (temp - 32) * (5M/9M); 
    }

    public static decimal ToFahrenheit(decimal temp)
    {
        return  (9M/5M) * temp + 32;
    }
}
```
> Prints: <br />
> 90 degrees in Celius (from Farenheit) is: 32.22 <br />
> 13 degrees in Farenheit (from Celsius) is: 55.4 <br /> 
> 
> Reference: [Literal Suffixes in C#](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/README.md#primitive-data-types) <br />

## Static Constructors
Now that you understand constructors and static methods, you can use static constructors. "A static constructor is used to initialize any static data, or 
to perform a particular action that needs to be performed only once. It is called automatically before the first instance is created or any static members are referenced."
([C# Documentation: Static Constructors](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-constructors).) Because static 
constructors are only callable by the runtime, they cannot have access modifiers such as _public_ or _private_. Moreover, static constructors cannot have parameters
(this means that a class can only have one static constructor!). Last, there is no such thing as a static destructor.
```C#
public static void Main(string[] args)
{
    Console.WriteLine($"Program started at {TimeKeeper.StartTime}");
}

//Class 'TimeKeeper' keeps a rough estimate of when the program started and ended
class TimeKeeper
{
    public static DateTime StartTime { get; }   //The time the program started

    static TimeKeeper()
    {
        StartTime = DateTime.Now;
    }
}
```
> Prints 'Program started at 6/25/2021 4:46:17 PM'

## Extension Methods
In the event that you do not want to derive a new class from a new class, but still want to add to a pre-existing class, you can add methods to the pre-existing
class using extension methods. Extension methods allow you to extend the functionality of a pre-existing class, which includes the fundamental datatypes (int, string, DateTime) since C# has a [Unified Type System](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/#the-common-type-system). Unless you are adding to the fundamental
datatypes or pre-existing C# objects, you should try to avoid using extension methods. More often than not, creating a derived/static class is better than creating an 
extension method because classes provide coherent organization, replacing the otherwise unavoidable amalgamation of unrelated methods. Before using extension methods,
you should read [_Why I don't like C# Extension Methods_](https://daedtech.com/why-i-dont-like-c-extension-methods/) and [_Extension Methods and the Decline of Traditional Object-Oriented Programming_](https://blog.ndepend.com/extension-methods-decline-oop/) (If you read one, read both; his opinion changes somewhat in the second in an important way).

```C#
using System;
using Extensions;  //Namespace for string extensions

// DRIVER CODE \\
namespace ExtensionsPracticeMain
{
    class Program
    {
        public static void Main(string[] args)
        {
            string word = "kayak", game = "Minecraft";

            //Prints: The reverse of the word 'Minecraft' is: 'tfarceniM'
            Console.WriteLine($"The reverse of the word '{game}' is: '{game.Reverse()}'");

            //Prints: 'Minecraft' is the reverse of 'Mortal Kombat': False
            Console.WriteLine($"'{game}' is the reverse of 'Mortal Kombat': {game.IsReverseOf("Mortal Kombat")}");

            //Prints: 'kayak' is a palindrome: True
            Console.WriteLine($"'{word}' is a palindrome: {word.IsPalindrome()}");

            //Prints: 'Mortal Kombat' is a palindrome: False
            Console.WriteLine($"'Mortal Kombat' is a palindrome: {"Mortal Kombat".IsPalindrome()}");
        }
    }   
}

// STRING CLASS EXTENSIONS \\

//Extensions should have a separate namespace
namespace Extensions
{
     //A class dedicated to string extensions (you cannot delclare a method directly in a namespace).
    //A method must be a part of a class
    public static class StringExtensions
    {
        //The initial parameter for any extension must be the object itself (preceeded by the 'this' keyword)
        public static string Reverse(this String str)
        {
              //Since strings are immutable, using a temporary char array (mutable) 
             //is a better solution than reversing the individual members
            //of the string since it would create a lot of unnecessary garbage.
            var charArray = str.ToCharArray();
            Array.Reverse(charArray);

            return new string(charArray);
        }

        //Only the first paramter (the object itself) needs the 'this' keyword
        public static bool IsReverseOf(this String str, string other)
        {
            return str.Reverse() == other;
        }

        //Extension 'IsPalindrome' returns true if the string is a palindrome
        public static bool IsPalindrome(this String str)
        {
            return str == str.Reverse();
        }
    }
}
```
> Notice how instead of _.IsReverseOf()_ and _IsPalindrome()_ directly, I wrote out the underlying principle (_Reverse()_) and used it to write two other functions
> in a single, elegant line. <br />
> 
> Note: There is a ['.Reverse()' method under _System.Linq_](https://docs.microsoft.com/en-us/dotnet/api/system.linq.enumerable.reverse?view=net-5.0), but it's good not to rely too heavily on libraries as a beginner. <br />
> Reference: [C# Documentation: Extension Methods](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/extension-methods) <br />

## Parameter Modifiers

### Ref
When passing values as a parameter to a function, the actual variable itself is not passed, but only a copy of its contents. This means that anything that happens to the value passed will not affect the actual variable in main. To pass by reference (and avoid using a copy), you have to use the [_ref keyword_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/ref) in both the function declaration and when calling the function. It's worth noting that the _ref_, _in_, and _out_
keywords do not apply to class properties since they cannot be passed by reference.

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
_In_ passes a paramter by reference and also makes it [immutable](https://www.vocabulary.com/dictionary/immutable). Even though you cannot modifiy _in_ parameters, it is important that
the _in_ keyword exists because it allows you to immutably pass large values to functions without creating unnecessary copies. Because _in_ parameters are immutable, they 
must be initialized before being passed.

**WARNING: DO NOT RUN THIS CODE** <br />
Do _not_ run this. It eats a lot of RAM.
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
_object\[\]_ parameter type.

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
