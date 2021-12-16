# Conversion and Operator Overloading in C#
[Operator overloading](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170) is the ability to define how operators such as `+`, `-`, `*`, and `/` 
should interact with user-defined types (classes/structs). By default, built-in operators like `+` are not implicitly defined. Because of this, you have to explicitly define
how operators should work with classes using operator overloading. In C#, operator overloads are defined as `public static` methods. Overloads
can be further modified with the [implicit and explicit keywords](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/user-defined-conversion-operators).

# Operator Overloading
A simple _Point_ class representing a pair of x- and y-coordinates, with an overloaded `+` operator that returns a new point.

```C#
public readonly struct Point
{
    //X and Y coordinates
    public readonly double X {get; init;}
    public readonly double Y {get; init;}

    //Constructor
    public Point(double x, double y) {X = x; Y = y;}

    //Operator overloads
    public static Point operator+(Point a, Point b) => new Point(a.X + b.X, a.Y + b.Y);
}
```

# Conversion Overloading
This version of of the _Point_ struct overrides the [.ToString()](https://docs.microsoft.com/en-us/dotnet/api/system.object.tostring?view=net-6.0) method and defines
the (string) conversion.
```C#
public readonly struct Point
{
    //X and Y coordinates
    public readonly double X {get; init;}
    public readonly double Y {get; init;}

    //Constructor
    public Point(double x, double y) {X = x; Y = y;}
    
    //Methods
    public override string ToString() => $"({X},{Y})";

    //Operator overloads
    public static Point operator+(Point a, Point b) => new Point(a.X + b.X, a.Y + b.Y);
    
    //Conversion operator overloads
    public static explicit operator string(Point p) => p.ToString();
}
```

# Sources
- C# Documentation: [Operator Overloading](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/operator-overloading#overloadable-operators)
- Educba.com [Operator Overloading in C#](https://www.educba.com/operator-overloading-in-c-sharp/)
- GeeksforGeeks: [C# Operator Overloading](https://www.geeksforgeeks.org/c-sharp-operator-overloading/)
