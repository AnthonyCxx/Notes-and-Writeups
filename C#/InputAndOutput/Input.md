# Input Operations in C#

## Console.ReadLine()
_Console.ReadLine()_ reads characters until it hits a newline (_\n_), which means it reads until the user presses enter.
```C#
string fullname;

Console.Write("Enter your full name: ");
fullname = Console.ReadLine();
Console.WriteLine("Hello, " + fullname);
```

## Console.Read()

## Console.ReadKey()

## Console.Beep()
Plays a [bell character], which is often used to indicate some error or prohibited action.
```C#
System.Console.Beep();
```
