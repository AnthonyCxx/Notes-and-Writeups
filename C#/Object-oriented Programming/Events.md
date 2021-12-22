# Events in C#
"Events enable a class or object to notify other classes or objects when something of interest occurs. The class that sends (or raises) the event is 
called the publisher and the classes that receive (or handle) the event are called subscribers." ([C# Documentation: Events](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/events/)). Events allow objects to interact with each other, creating a reactive environment.
> \*Careful with adding lambdas, because they cannot be removed since they're nameless

## Format
```C#
using System;

public event EventHandler OnClick
```
> Conventions:
> Events should start with the word 'On', (e.g. OnClick)

## Publishers

## Subscibers
