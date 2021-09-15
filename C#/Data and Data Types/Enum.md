# Enums (enumerated types) in C#
An enumerated type (enum) is a user-defined value type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple values,
'On' and 'Off'. Enums may be preferable to booleans because they can represent a number of states (as opposed to a boolean's two states) and do not imply a relationship between 
some two states that a boolean would. By default, the first value of an enum is 0, the second is 1, the third is 2, and so on; however, this can be overwritten by manually 
assigning the values inside of the enum declaration. [Here](https://www.tutorialsteacher.com/csharp/csharp-enum) is a solid summary of enums.

## Enum Format


```C#
enum EnumName
{
  Value1,
  Value2,
  Value3
}
```

## A Simple Enum

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

```C#

```
