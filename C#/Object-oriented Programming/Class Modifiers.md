# Class Modifiers in C#
Although these are not technically their own category of modifiers, I still felt they should have their own section.

# Static Classes
Often when programming, we need to use classes not for variables (i.e. not to be instantiated), but just to better organize our program. These classes are often called utility clases. Static members of a class are shared across all instances of the class and are accessed directly via `<ClassName>.<MemberName>`. 

```C#
public static class TempConverter
{
    //Enum defines the temperature unit system (Fahrenheit, Celsius, Kelvin)
    public enum UnitSystem {F, C, K};

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

```C#

```

# Sealed Classes

```C#

```

# Sources
- C# Documentation: [Static Classes and Static Class Members](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)
- C# Documentation: [Abstract and Sealed Classes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)
- C# Documentation: [Abstract Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract)
- C# Documentation: [Sealed Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sealed)
