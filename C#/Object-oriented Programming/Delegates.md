# Delegates in C#
Delegates are objects which represent functions. If you are familiar with C++, then you can think of delegates as a [std::function<T()>](https://en.cppreference.com/w/cpp/utility/functional/function) object
(a sort of [functor](https://www.geeksforgeeks.org/functors-in-cpp/))

# 

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
- []()
- []()
- []()
