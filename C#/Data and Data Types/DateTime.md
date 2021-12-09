# DateTime Datatype in C#
The _DateTime_ type for representing date and time in C#. DateTime objects can represent any date/time between `1/1/0001 12:00:00 AM` (DateTime.MinValue) and 
`12/31/9999 11:59:59 PM` (DateTime.MaxValue). Like Strings, DateTime objects are immutable.

# Quick Reference
The constructor of a DateTime object allows you to specify the year, month, day, hour, minute, and second in that order.
```C#

```

# Fields
| Fields | Type | Value |
| ------ | ---- | ----- |
| `.MaxValue` | static | max value of a DataTime object (`12/31/9999 11:59:59 PM`) |
| `.MinValue` | static | min value of a DateTime object (`1/1/0001 12:00:00 AM`) |
| `.UnixEpoch` | static | start of the [unix epoch](https://www.howtogeek.com/759337/what-is-the-unix-epoch-and-how-does-unix-time-work/) |
> Just as a note, 'epoch' is pronounced as 'epic'

# Properties

| Properties | Type | Value | Range | 
| ---------- | ---- |  ---- | ----- | 
| `.Now` | static | the current date + time as a _DateTime_ object | - |
| `.Today` | static | the current date + a time of (00:00:00 AM) | - | 
| `.TimeOfDay` | static | the time passed since midnight as a [TimeSpan](https://docs.microsoft.com/es-es/dotnet/api/system.timespan?view=net-6.0) | - |
| `.UtcNow` | static | the current data + time in [UTC](https://en.wikipedia.org/wiki/Coordinated_Universal_Time) | - |
| `.Date` | instance | the date + a time of (00:00:00 AM) |  - |
| `.Year` | instance | the year of the object | 1-9999 |
| `.Month` | instance | the month of the object (as an int) | 1-12 |
| `.Day` | instance | the day of the object (as an int) | 1-31 |
| `.Hour` | instance | the hour of the instance | 0-23 |
| `.Minute` | instance | the minute of the instance |  0-59 | 
| `.Second` | instance | the second of the instance |  0-59 |
| `.Millisecond` | instance | the millisecond of the instance |  0-999 |
| `.Ticks` | instance | the [tick](https://docs.microsoft.com/en-us/dotnet/api/system.timespan.ticks?view=net-6.0) of the instance (equal to 100 nanoseconds) |  0-3155378975999999999 |
| `.DayOfWeek` | instance | day of the week of the instance as a string (e.g. Wednesday) | Sunday-Saturday |
| `.DayOfYear` | instance |day of the year \[int\] | 1-366 |
| `.Kind` | instance | a [DateTimeKind](https://docs.microsoft.com/es-es/dotnet/api/system.datetimekind?view=net-6.0) enum representing the  | - |
>  "A tick is equal to 100 nanoseconds or one ten-millionth of a second. There are 10,000 ticks in a millisecond." \[[src](https://docs.microsoft.com/en-us/dotnet/api/system.timespan.ticks?view=net-6.0)\]

# Methods
| Method | Function | Example | 
| ------ | -------- | ------- |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# Sources
- C# Documentation: [DateTime Struct](https://docs.microsoft.com/en-us/dotnet/api/system.datetime?view=net-6.0)
- C# Corner: [DateTime in C#](https://www.c-sharpcorner.com/article/datetime-in-c-sharp/)
