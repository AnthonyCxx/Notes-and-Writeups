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
_Console.Read()_ will read in a single character and return its value as an ASCII decimal ([base 10](https://www.purplemath.com/modules/numbbase.htm)) integer. <br />
If there are no characters to be read, then _Console.Read()_ will return a -1.
```C#
int character;

Console.Write(Enter a character: );
character = Console.Read();

Console.WriteLine("\nYou entered: " + (char) character)
```
> Note: Putting _(char)_ in front of a variable will [type-cast](https://www.w3schools.com/cs/cs_type_casting.asp) the integer into an [ASCII](https://en.wikipedia.org/wiki/ASCII) character.

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
Plays a [bell character](https://en.wikipedia.org/wiki/Bell_character), which is often used to indicate some error or prohibited action.
```C#
System.Console.Beep();
```
