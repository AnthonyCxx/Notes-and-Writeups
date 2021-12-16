# Class Modifiers in C#
Although these are not technically their own category of modifiers, I still felt they should have their own section.

# Static Classes
Often when programming, we need to use classes not for variables (i.e. not to be instantiated), but just to better organize our program. Such classes are called utility classes. 
To make a class static, just prefix the `class` keyword with `static` as `static class`...

Below is an example of a fully fleshed-out temperature converter as a utility class, which implements a `.Convert()` method to convert a temperature from one unit into another

```C#
public static class TempConverter
{
    //Enum defines the temperature unit system (Fahrenheit, Celsius, Kelvin)
    public enum UnitSystem {F, C, K};

    //Parent function, converts a given temperature from the source units to the destination units (e.g. 100°C => 212°F) 
    public static double Convert(double temp, UnitSystem src, UnitSystem dst) => dst switch
    {
            //Destination units dictates which conversion function to call
            UnitSystem.F => ToFahrenheit(temp, src),
            UnitSystem.C => ToCelsius(temp, src),
            UnitSystem.K => ToKelvin(temp, src),
            _ => throw new ArgumentException("UnitSystem parmaeter \'dst\' is invalid (not F, C, or K); check for bad casts"),
    };

    private static double ToFahrenheit(double temp, UnitSystem src) => src switch
    {
        //Source units => Fahrenheit Conversion
        UnitSystem.F => temp,
        UnitSystem.C => ((9.0D/5.0D) * temp) + 32,
        UnitSystem.K => ((9.0D/5.0D) * (temp - 273)) + 32,
        _ => throw new ArgumentException("UnitSystem parmaeter \'src\' is invalid (not F, C, or K); check for bad casts"),
    };

    private static double ToCelsius(double temp, UnitSystem src) => src switch
    {
        //Source units => Celsius Conversion
        UnitSystem.F => (5.0D/9.0D) * (temp - 32),
        UnitSystem.C => temp,
        UnitSystem.K => temp - 273,
        _ => throw new ArgumentException("UnitSystem parmaeter \'src\' is invalid (not F, C, or K); check for bad casts"),
    };

    private static double ToKelvin(double temp, UnitSystem src) => src switch
    {
        //Source units => Kevlin Conversion
        UnitSystem.F => ((5.0D/9.0D) * (temp - 32)) + 273,
        UnitSystem.C => temp + 273,
        UnitSystem.K => temp,
        _ => throw new ArgumentException("UnitSystem parmaeter \'src\' is invalid (not F, C, or K); check for bad casts"),
    };
}

//Usage Example
public static void Main(string[] args)
{   
    double temp = 100;
    var srcUnit = TempConverter.UnitSystem.C;
    var dstUnit = TempConverter.UnitSystem.K;
    Console.WriteLine($"{temp}°{srcUnit} in °{dstUnit} is: {TempConverter.Convert(temp, srcUnit, dstUnit):N3}");
}
```

# Abstract (Base) Classes
Abstract classes are classes that cannot be inherited — only serving as a class to be inherited form.

```C#

```

# Sealed Classes
Sealed classes cannot be inherited from. The _sealed_ keyword is the equivalent of C++'s [final](https://en.cppreference.com/w/cpp/language/final) keyword.

```C#

```

# Sources
- C# Documentation: [Static Classes and Static Class Members](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)
- C# Documentation: [Abstract and Sealed Classes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)
- C# Documentation: [Abstract Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract)
- C# Documentation: [Sealed Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sealed)
