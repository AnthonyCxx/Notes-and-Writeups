# Strings
Note: **_..._** is used to indicate a varying amount of parameters. <br />

Strings are a series of read-only characters representing text. [Strings are immutable](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/strings/#:~:text=String%20objects%20are%20immutable%3A%20they,in%20a%20new%20string%20object.); once created, any operation that changes it actually returns a new string.

# Special Strings
## Raw Strings (@)
Prefixing a string with a _@_ will make the string raw (disables metacharacters, such as escape characters). <br />
This comes in extremely handy with Windows as Windows uses backslashes as a delimiter to separate files and folders.
```C#
//Declaring a filepath
string filepath = @"C:\Program Files";
```
> To use quotation marks in a raw string, you have to use two apiece

## Interpolated Strings ($, { })
Prefixing a string with a _$_ and then putting a variable, function, expression, etc. in _{ }_ will replace it with the value/result. <br />
String interpolation is a shorthand for calling the _String.Format()_ method. <br />

> According to the [C# Coding Conventions](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/coding-style/coding-conventions#string-data-type), string interpolation should be used for concatenating short strings.
```C#
//Promp the user for their name
Console.Write("Enter your name: ");  //No implicit \n

//Read in their name
string name = Console.ReadLine();

//Greet the user by name
Console.WriteLine($"Hello, {name}"; 
```

# Methods

## .Join()
The _Join(**_separator_**, **_collection_**)_ method converts all the elements of a collection into a single string, separated
by a separator
```C#
//Declare and initialize an array of students
string[] students = {"Henry", "Charlie", "Seth"}; 

//Print the students in a comma-separated string
Console.WriteLine(string.Join(", ", students));
```
> Prints "Henry, Charlie, Seth" <br />
> Reference: [C# Documentation: What is a Collection?](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/collections)

## .Format()
The _Format(**_string_**, **_variable_**, ...)_ method replaces portions of the string the the result of an expression or value of a variable
```C#
string animal = "squirrel";
//The {0} is replaced by the value of 'animal'. If you added another variable, you'd do {1}
Console.WriteLine( string.Format("That\'s a cute {0}", animal) );
```
> Prints "That's a cute squirrel"

## .Concat
The _.Concat(**_string_**, **_string_**, ...)_ method [concatenates](https://en.wikipedia.org/wiki/Concatenation) any number of strings and returns the result.
```C#
string phrase = "hello";
Console.WriteLine( string.Concat(phrase, phrase, phrase) ); 
```
> Prints "hellohellohello"

## .Compare
The _Compare(**_string_**, **_string_**)_ method compares two strings by sort order and returns an integer based on the result. Including a _true_ as the final parameter will make
the comparison case-insensitive. Note, however, that this means that both the individual and total comparison will take longer.

| Result | Indicator |
| ------ | --------- |
| Less than 0 | the first substring precedes the second substring in the sort order |
| Exactly 0 | the substrings occur in the same position in the sort order, or length is zero. |
| Greater than 0 | the first substring follows the second substring in the sort order. |

```C#
string thing1 = "Hammer";
string thing2 = "hammmer";

Console.WriteLine( string.Compare(thing1, thing2) );   
```
> Prints '-1' (the first substring precedes the second substring in the sort order) <br />
> Reference: [Microsoft C# Documentation: String.Compare()](https://docs.microsoft.com/en-us/dotnet/api/system.string.compare?view=net-5.0)

## .StartsWith()
The _StartWith(**_string_**)_ method returns true if the string begins with the provided string/character.
```C#
string greeting = "Good morning, how are you feeling?";

if (greeting.StartsWith("Good morning")
{
  Console.WriteLine("The string is a morning greeting");
}
```
> Prints "The string is a morning greeting"

## .EndsWith()
The _.EndsWith(**_string_**)_ method returns true if the string ends with the provided string/character.
```C#
string item = "ender chest";

if (item.EndsWith("chest")
{
  Console.WriteLine("The item is a type of chest");
}
```
> Prints "The item is a type of chest"

## .ToLower()
The _ToLower()._ method converts a string into lowercase.
```C#
string companyName = "International Data Corporation";

Console.WriteLine( companyName.ToLower() );
```
> Prints "international data corporation"

## .ToUpper()
The _ToLower()._ method converts a string into uppercase.
```C#
string timidText = "im sorry :(";

Console.WriteLine( timidText.ToUpper() );
```
> Prints "IM SORRY :("

## .Trim()
The _.Trim()_ method removes excess whitespace from the string. This method is commonly used when getting input from the user.
```C#
string fillerText = "            this string is unnecessarily long               ";

Console.WriteLine( fillerText.Trim() );
```
> Prints "this string is unnecessarily long"

## .TrimStart()
The _.TrimStart()_ method removes excess whitespace from the beginning of a  string.
```C#
string fillerText = "            this string is unnecessarily long               ";

Console.WriteLine( fillerText.TrimStart() );
```
> Prints "this string is unnecessarily long  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    "

## .TrimEnd()
The _.TrimEnd()_ method removes excess whitespace from the beginning of a  string.
```C#
string fillerText = "            this string is unnecessarily long               ";

Console.WriteLine( fillerText.TrimEnd() );
```
> Prints " &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   this string is unnecessarily long"

## .PadLeft()
The _.PadLeft(**_int_**, **_char_**)_ method [pads](https://www.computerhope.com/jargon/p/padding.htm) the beginning of the string with **_char_** until it reaches length **_int_**. <br />
If the string is already longer than **_int_**, then the string is not padded.
```C#
int[] numbers = {1, 2, 3, 10, 11, 12, 100, 101, 102};
char pad = '0';

foreach (int num in numbers)
{
  Console.WriteLine( num.ToString().PadLeft(3, pad) );   //zero-fills the number to length 3
}
```
> Prints: <br />
> 001 <br />
> 002 <br /> 
> 003 <br />
> 010 <br />
> 011 <br />
> 012 <br />
> 100 <br />
> 101 <br />
> 102 <br />

## .PadRight()
The _.PadRight(**_int_**, **_char_**)_ method [pads](https://www.computerhope.com/jargon/p/padding.htm) the end of the string with **_char_** until it reaches length **_int_**. <br />
If the string is already longer than **_int_**, then the string is not padded.
```C#
string[] things = {"car", "cow", "bow" };

foreach (string thing in things)
{
  Console.WriteLine( thing.PadRight(4, 's') );   //makes three-letter words plural
}
```
> Prints: <br />
> cars <br />
> cows <br />
> bows <br />

## .Replace()
The _.Replace(**_string_**, **_string_**)_ method replaces all instances of the first string with the second string.
```C#
string text = "This is an example sentence to show this concept";

Console.WriteLine( text.Replace("this", "that") );
```
> Prints "That is an example sentence to show that concept"

## .IndexOf()
The _IndexOf(**_string_**)_ method returns the index of the first instance of the given character/string as an integer.
```C#
string dialogue = "And that's when...";

Console.WriteLine( dialogue.IndexOf(' ') );
```
> Prints "3" (remember, [computers are 0-indexed](https://en.wikipedia.org/wiki/Zero-based_numbering))

## .LastIndexOf()
The _.LastIndexOf(**_string_**)_ method returns the index of the last instance of a character/string as an integer.
```C#
string text = "...Dr. Quillen is here to see you.";

Console.WriteLine( text.LastIndexOf(".") );
```
> Prints the index: 33

## .Substring
The _.Substring(**_string_**)_ method returns a snippet of the original text, from the index of the provided integer to the end of the string.
```C#
string textToSearch = "This is a some really long, unnecessary sentence - let\'ts cut it down to size";
int index = textToSearch.IndexOf("-") + 2;      //Add 2 to start at 'l' instead of '-'

Console.WriteLine( textToSearch.Substring(index) );
```
> Prints "let's cut it down to size"

## .Contains()
The _.Contains(**_string_**)_ method returns true if the string contains the given substring.
```C#
string text = "This is an advertisement so you buy our product; I sure hope you don't use custom software to block it using keywords.";

if (text.Contains("buy"))
{
  Console.WriteLine("Yeah, it's an advertisement.");
}
```

## .Split()
The _.Split(**_character_**)_ method returns a string array, splitting the string up into elements based on a provided [delimiter](https://en.wikipedia.org/wiki/Delimiter#:~:text=A%20delimiter%20is%20a%20sequence,expressions%20or%20other%20data%20streams.&text=Another%20example%20of%20a%20delimiter,the%20transmission%20of%20Morse%20code.)
```C#
string someIPAddress = "192.168.1.1";
string[] IPAddressFields = someIPAddress.Split('.');

Console.WriteLine($"The beginning of the IP Address is {IPAddressFields[0]} ");
```
> Prints "The beginning of the IP Address is 192" <br />
>
> Consider splitting a sentence into individual words with _.Split(' ')_
