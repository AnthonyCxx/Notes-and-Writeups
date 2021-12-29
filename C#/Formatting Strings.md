# Formatting Strings in C#
The [String.Format()](https://docs.microsoft.com/en-us/dotnet/api/system.string.format?view=net-6.0) method (which is indirectly called when you use [string interpolation](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/tokens/interpolated)) is incredibly dexterous and provides a wide array of tool for formatting strings.
The document contains a collection of formatting techniques as well as examples.

---

# Indexing
By default, when calling _String.Format()_, the order of the curly braces (`{}`) is the order the  arguments are interpolated; however, the order can be manually overriden
by using indices. Indices ARE zero-indexed, so be careful or you'll get a [System.FormatException](https://docs.microsoft.com/en-us/dotnet/api/system.formatexception?view=net-6.0).

```C#
string fname = "John", lname = "Doe", greeting;
int age = 34;

greeting = String.Format("Hello, my name is {1} {2} and I'm {0} years old.", age, fname, lname);

Console.WriteLine(greeting);
```
> Prints "Hello, my name is John, Doe and I'm 34 years old."

---

# Left/Right Justication
Passing an integer _n_ as the second argument of an interpolated string will pad the text with spaces until it reaches length _n_.
A positive number will right-justify the text, a negative number will left-justify it. When creating columns, text like names are
usually left-justified, whereas numbers are right-justified.

```C#
Console.WriteLine($"{"text",6}");
```
> Prints "&nbsp;&nbsp;text"

---

# Formatting Strings
When combining [string formatting components](https://docs.microsoft.com/en-us/dotnet/standard/base-types/composite-formatting#format-string-component) with [alignment components](https://docs.microsoft.com/en-us/dotnet/standard/base-types/composite-formatting#alignment-component), the alignment component should come before the string
formatting component with the string formatting component directly appended on the end like `$"{num,2:X}"` (which displays a number in hex with at least two spaces, meaning
both the hex numbers 1 and 2A will take the same space).

```C#

```

## Formatting Numbers
| Formatter | Effect | 
| --------- | ------ |
| `:Nn` | displays _n_ digits |
| `:X` | hexadecimal notation |
| `:E` | scientific notation |
| `` |  |
| `` |  |
| `` |  |

## Formatting Dates and Times
| Formatter | Effect | 
| --------- | ------ |
| `` |  |
| `` |  |
| `` |  |
