# Enums (enumerated types) in C#
An enumerated type (enum) is a user-defined value type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple values,
'On' and 'Off'. Enums may be preferable to booleans because they can represent a number of states (as opposed to a boolean's two states) and do not imply a relationship between 
some two states that a boolean would. By default, the first value of an enum is 0, the second is 1, the third is 2, and so on; however, this can be overwritten by manually 
assigning the values inside of the enum declaration. [Here](https://www.tutorialsteacher.com/csharp/csharp-enum) is a solid summary of enums.

## Enum Format
Enums are declared with the _enum_ keyword followed by the name of the enum and the list of values the enum has.

```C#
enum EnumName
{
  Value1,
  Value2,
  Value3
}
```

## A Simple Enum
Here is a simple enum called '_Team_' that contains the possible teams a player can be one, based on color.

By default, using an enum like '_Team.Red_' will return the value as a string (e.g. 'Red').
```C#
enum Team
{
  Red,           //Red == 0
  Yellow,       //Yellow == 1
  Blue,        //Blue == 2
  Green       //Green == 3
}
```

## Enum with Manually Assigned Values
Each possible value of an enum is mapped to an integer constant that is always one greater than the last (starting at 0). If you assign the values manually, then the values 
of the enum will take on said integer value. If you assign one value manually and do not assign the ones that follow it, then the following values will just follow the 
pattern of adding one to the previous value.

```C#
enum Team
{
  Red,                //Red == 0
  Yellow = 12,       //Yellow == 12
  Blue,             //Blue == 13
  Green            //Green == 14
}
```

## Integer Casting
To get the integer value from an enum, cast it appropriately. 

```C#
enum Days
{
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
}

static void Main(string[] args)
{
  Console.WriteLine($"{Days.Monday}: {(int) Days.Monday}");
}
```
