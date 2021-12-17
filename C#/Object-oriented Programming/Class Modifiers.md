# Class Modifiers in C#
> [Static Classes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Object-oriented%20Programming/Class%20Modifiers.md#static-classes) <br />
> [Abstract (Base) Classes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Object-oriented%20Programming/Class%20Modifiers.md#abstract-base-classes) <br />
> [Sealed Classes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Object-oriented%20Programming/Class%20Modifiers.md#sealed-classes) <br />

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
Abstract classes are classes that cannot be inherited — only serving as a class to be inherited form. <br />

Here is a short example of a basic [Entity](https://tandemcoder.com/entity-component-system-in-games-starter-guide/) class and a Player class derived from it.
```C#
//Abstract base class 'Entity' 
public abstract class Entity
{
    //Struct to define their coordinates
    public struct Coordinates
    {
        public float X {get; set;}
        public float Y {get; set;}

        public Coordinates(float x = 0.0f, float y = 0.0f)
        {
            X = x;
            Y = y;
        }
    }

    //Player stats
    public string Name {get; init;}

    public int Health {get; protected set;}
    protected Coordinates Coords {get; set;}

    //Constructor
    public Entity(string name, float xcoord = 0, float ycoord = 0)
    {
        if (String.IsNullOrWhiteSpace(name))
            throw new ArgumentException("name cannot be null/whitespace");

        Name = name;
        Coords = new Coordinates(xcoord, ycoord);
    }
}

//Derived class 'Player'
public class Player: Entity
{
    private int _level;

    //Constructor
    public Player(string name, float xcoord = 0, float ycoord = 0): base(name, xcoord, ycoord)
    {
        //Init new data members
        _level = 0;
    }

    //Get the stats of the player
    public string GetStats() => $"{Name} [level {_level}]: ({Coords.X},{Coords.Y})";
}
```

# Sealed Classes
Sealed classes cannot be inherited from. The _sealed_ keyword is the equivalent of C++'s [final](https://en.cppreference.com/w/cpp/language/final) keyword.

```C#
public sealed class SealedClass
{
    //This class cannot be derived from
}
```

# Sources
- C# Documentation: [Static Classes and Static Class Members](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/static-classes-and-static-class-members)
- C# Documentation: [Abstract and Sealed Classes](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/abstract-and-sealed-classes-and-class-members)
- C# Documentation: [Abstract Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract)
- C# Documentation: [Sealed Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/sealed)
