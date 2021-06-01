# Output Operations in C#

## Console.Write()
_Console.Write()_ displays the given string/value to the console.
```C#
//Print "Console.Write() leaves the cursor where it is" to the screen
Console.Write("Console.Write() leaves the cursor where it is");
```

## Console.WriteLine()
_Console.WriteLine()_ writes the given string/vaue to the console, ending the line after it finishes.
```C#
//Print "Console.WriteLine implicitly ends the line" and then end the line
Console.WriteLine("Console.WriteLine implicitly ends the line");
```

## Formatting Strings with Variables
Strings can be formatted with the contents of variables by providing the variables (set off by commas) after the string. <br />
Put the ordinal position of the variable inside of curly braces (_{ }_) to replace said expression with the variable's content. <br />
Alternatively, you can use [interpolated strings](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/Strings.md). <br />
```C#
//Variables
string name = "human";
string creature = "person";

//Print a string, replacing the {num} with the variable contents
Console.WriteLine("Hello, my name is {0}, and I am a {1}", name, creature);
```
