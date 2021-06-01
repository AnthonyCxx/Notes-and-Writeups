# Input Operations in C#

## Console.ReadLine()
_Console.ReadLine()_ reads characters until it hits a newline (_\n_), which means it reads until the user presses enter.
This method returns a string.
```C#
string fullname;

Console.Write("Enter your full name: ");
fullname = Console.ReadLine();
Console.WriteLine("Hello, " + fullname);
```

## Console.Read()

## Console.ReadKey()
_Console.ReadKey()_ returns a single character and is often used with prompts. <br />
_Console.ReadKey()_ will only read a character; to use the character, use the _.KeyChar_ ReadKey() data member.
```C#
char choice;

//Get the character
Console.Write("Choose 1 or 2: ");
choice = Console.ReadKey().KeyChar;

//Make a decision
switch (choice)
{
  case '1':
    Console.WriteLine("You chose 1!");
    break;
case '2':
    Console.WriteLine("You chose 2!");
    break;
default:
  Console.WriteLine("Unknown choice");
  break;
```
> Reference: [How to Read a Character in C#](https://www.includehelp.com/dot-net/methods-to-read-a-character-in-c-sharp.aspx)

## Console.Beep()
Plays a [bell character], which is often used to indicate some error or prohibited action.
```C#
System.Console.Beep();
```
