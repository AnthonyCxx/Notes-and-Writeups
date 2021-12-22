# Delegates in C#
Delegates are types which represent functions (one with a parameter list and a return type). If you are familiar with C++, then you can think of delegates as a [std::function<T()>](https://en.cppreference.com/w/cpp/utility/functional/function) object (a type used for creating [functors](https://www.geeksforgeeks.org/functors-in-cpp/)).
To declare a delegate, use the `delegate` followed by a standard function delclaration like `public delegate int Comparison(int x, int y);`. Although delegates don't seem
particularly useful at first glance, they are incredibly useful in both events and polymorphism. Again, the delcartion of a delegate is a _type_ — like a class. If you want
to actually use a delegate, you have to create a variable of the desired delegate type.

```C#
class DelegatePractice
{
    //Declaration of a delegate type called 'Comparison' that takes two ints and returns an int
    public delegate int Comparison(int x, int y);

    //Static delegate objects: 'Lesser' and 'Greater' and objects that alias functions 'Min()' and 'Max()'
    public static Comparison Lesser = Min;
    public static Comparison Greater = Max;

    //Existing methods for the delegates to alias
    public static int Min(int x, int y)
    {
        return x < y ? x : y;
    }

    public static int Max(int x, int y)
    {
        return x > y ? x : y;
    }
}
```
> Usage: `int lesser = DelegatePractice.Lesser(10,20);`

# Func<> and Action<>


# Example Usage: Creating an Array of Functions
A bit niche, but an interesting example nonetheless; this example uses delegates to declare an array of functions, which can be individually accessed or looped through.
Practically, this could be used to avoid having to write a function to evaluate a user's choice and then call the corrosponding function. However, that's a very obscure
approach so I wouldn't recommend it in real practice. (full example in C: [click](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Example%20Programs/LookupTables.c)).

```C#
//Defines a delegate (a functor) to a method that takes 2 doubles and return 1
public delegate double Operation(double a, double b);

//Static class for basic math operations
static class MathOperations
{
    public static double Add(double x, double y) => x + y;
    public static double Sub(double x, double y) => x - y;
    public static double Mul(double x, double y) => x * y;
    public static double Div(double x, double y) => x / y;
    public static double Mod(double x, double y) => x % y;
} 


//Main
static void Main(string[] args)
{
    //An array of delegates, acting as a lookup table
    Operation[] BasicOperations = {
                                    MathOperations.Add, 
                                    MathOperations.Sub,
                                    MathOperations.Mul,
                                    MathOperations.Div,
                                    MathOperations.Mod
                                 };

    //Loop through the array, applying every basic operation to the numbers 10 and 20
    foreach(Operation op in BasicOperations)
    {
        Console.WriteLine( op(10, 20) );
    }
}
```

# Sources
- C# Documentation: [Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/)
- C# Documentation: [Using Delegates](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/using-delegates)
- C# Corner: [Delegates in C#](https://www.c-sharpcorner.com/article/delegates-in-c-sharp/)
- C# Corner: [Func, Action And Predicate Delegates In C#](https://www.c-sharpcorner.com/article/func-action-predicate-delegates-in-c-sharp/)
- Medium: [C# 9 — Delegate, Action and Func](https://mohamadlawand.medium.com/c-9-delegate-action-and-func-82900ed02be)
