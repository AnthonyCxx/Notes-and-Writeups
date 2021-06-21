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
The implementation of a method requires all of the following: an [access modifier](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/AccessModifiers.md), a [return type](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Methods.md#the-return-keyword-and-return-types), a name, a parameter list, and a body. In some cases, such as with [interfaces](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Interfaces.md), you will only be asked to declare a method, in which case 
you will not need to supply a body for the method.

```C#
public void printHello()    //Access modifier (public), return type (void), name (printHello), parameter list ( () )
{
    Console.WriteLine("Hello!");  //The code to be executed in { }
}
```

## The Return Keyword and Return Types
Methods can return a value to wherever it was called. The _return_ keyword returns that value, which could be a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b), a variable, or an expression. Once the _return_ statement is executed, the function ends, regardless of whether there was code after
the _return_ statement. Any good compiler should warn you that the code after the _return_ statement is 'dead code' (code that cannot and will not be executed). The datatype
of the value that will be returned must be declared as a part of the method declaration (following the access modifier). Here, the _return5()_ method returns an integer, 5.
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
A function can take parameters (also called arguments), which are values that are passed into the function. The function can then use these values as variables.
A simple method '_Add_' could take two numbers as parameters and return their sum.
```C#
public static void Main(string[] args)
{
    int num = Add(5, 10);
    Console.WriteLine(num);
}

//Method 'Add' adds two numbers
public static int Add(int num1, int num2)  
{
    return num1 + num2;    //The 'return' keyword is always evaluated last
}
```
> Prints: '15'

## Default Parameters
In the event that a method is called without some or all parameters, measures can be put into place to ensure that each parameter still has some default value.
To add default parameters, simple put an equals sign followed by a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) (some value). That way, the parameter will take on that value if and only if no other value is provided.
```C#
static void Main(string[] args)
{
    Console.WriteLine($"Calling the Add method with the integers 7 and 8 as parameters: {DummyClass.Add(7, 8)}");   //prints 15
    Console.WriteLine($"Calling the Add method with no parameters: {DummyClass.Add()}"); //prints 2
}
        
public class DummyClass
{
    public static int Add(int param1 = 1, int param2 = 1)  //both parameters have a default value of 1
    {
        return param1 + param2;    
    }
}
```
> Prints: <br />
> Calling the Add method with the integers 7 and 8 as parameters: 15 <br />
> Calling the Add method with no parameters: 2 <br />

## Constructors
A constructors is a special public method that are automatically run when an instance of the class is created. Constructors do not have a return type and _must_ 
share the name of their class and are often used to initialize the data members of said class. Constructors can be used for more than just initializing data members;
for example, in [my Hangman Game](https://github.com/EthanC2/Hangman/blob/main/header-files/GameClass.hpp) (C++), I put the _run()_ function in the constructor of my
_Game_ class so the game would automatically start when I loaded up the game. Similarly, in a video game constructors may call things like spawn animations or set 
the coordinates of the character. <br />

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
    private string _title;
    private int _totalPages;
    
    public string Title
    {
        get => _title;
        set => _title = value;
    }

    public int PageCount
    {
        get => _totalPages;
        set => _totalPages = value;
    }

    //Default Constructor
    public Book()      //constructors do not have a return type!
    {
        _title = "Unknown";
        _totalPages = 0;
    }

    //Parameterized contructor
    public Book(string title, int pageCount)
    {
        _title = title;
        _totalPages = pageCount;
    }
}
```
Functions can share the same name as long as they have different parameters. The computer can discern which function to call based on the data types of the paramters.
This is called [method overloading](https://www.geeksforgeeks.org/c-sharp-method-overloading/#:~:text=Method%20Overloading%20is%20the%20common,methods%20with%20different%20method%20signatures.).
> Reference: [Overloading Methods in C#](https://www.pluralsight.com/guides/overload-methods-invoking-overload-methods-csharp) <br />

## Static Methods
A static method (the opposite of an instance method) is a method that does not require an object of that class in order to be called. Take the _.WriteLine(**_string_**)_ 
method for example. You don't need a _System_ nor a _Console_ object to be able to use _.WriteLine(**_string_**)_. <br />

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
> Reference: [Literal Suffixes in C#](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/README.md#primitive-data-types) <br />
