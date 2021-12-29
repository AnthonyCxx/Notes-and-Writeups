# Formatting Strings in C#
The [String.Format()](https://docs.microsoft.com/en-us/dotnet/api/system.string.format?view=net-6.0) method (which is indirectly called when you use [string interpolation](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/tokens/interpolated)) is incredibly dexterous and provides a wide array of tool for formatting strings.
The document contains a collection of formatting techniques as well as examples. Generally, you should use string interpolation instead of concatenation because it's more
efficient, especially for concatenating multiple strings.

Here, string interpolation is an effective choice for the _FullName_ property because the first and last name may change after being initialized.
```C#
public struct Person
{
    public string FirstName {get; private set;}
    public string LastName {get; private set;}

    //String interpolation
    public string FullName { get => $"{FirstName} {LastName}";}

    Person(string fname, string lname)
    {
        FirstName = fname;
        LastName  = lname;
    }
}
```

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
//Show Pi to three digits
Console.WriteLine($"{Math.PI:N2}");
```
> Prints "3.14"

## Formatting Numbers
| Formatter | Effect | 
| --------- | ------ |
| `:Nn` | displays _n_ digits 
| `:D` | decimal (base 10) notation ||
| `:X` | hexadecimal notation |
| `:E` | scientific notation |
| `:C` | displays as currency |
| `:P` | displays as a percent |

## Formatting Dates and Times
Trust me when I tell you there are _a lot_ of DataTime formats. Here are just some common ones. For more information, see [Standard Date and Time Format Strings](https://docs.microsoft.com/en-us/dotnet/standard/base-types/standard-date-and-time-format-strings#table-of-format-specifiers) and [Custom Date and Time Format Strings](https://docs.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings). You should be aware that the format you choose will slightly change from
region to region; for example, the `{DateTime.Now:U}` yields `Wednesday, 29 December 2021 16:01:56` for English speakers and `miércoles, diciembre 29, 2021 4:00:09 PM` 
for Spanish speakers (the month and day and swapped), which is only a slight difference in this case but is still good to know.

| Abbrev. | Full Expression | Example |
| ------- | --------------- | ------- | 
| `d` | `MM/dd/yyyy` | 12/29/2021 |
| `D` | `dddd, dd MMMM yyyy` |  Wednesday, 29 December 2021 |
| `f` | `dddd, dd MMMM yyyy HH:mm` | Wednesday, 29 December 2021 16:17 | 
| `F` | `dddd, dd MMMM yyyy HH:mm:ss` | Wednesday, 29 December 2021 16:19:25 |
| `g` | `MM/dd/yyyy HH:mm` | 12/29/2021 16:20 |
| `G` | `MM/dd/yyyy HH:mm:ss` | 12/29/2021 16:20:12 |
| `` | `` |  |
| `` | `` |  |
| `` | `` |  |
| `` | `` |  |
| `` | `` |  |
| `` | `` |  |


# Sources 
- C# Documentation: [Standard Date and Time Format Strings](https://docs.microsoft.com/en-us/dotnet/standard/base-types/standard-date-and-time-format-strings)
- C# Documentation: [Custom Date and Time Format Strings](https://docs.microsoft.com/en-us/dotnet/standard/base-types/custom-date-and-time-format-strings)
- daveoncsharp: [Formatting a DateTime Object in C#](https://www.daveoncsharp.com/2009/09/formatting-a-datetime-object-in-csharp/)
- TutorialsTeacher: [DateTime Formats in C#](https://www.tutorialsteacher.com/articles/datetime-formats-in-csharp)
- StackOverflow: [DateTime Formats used in InvariantCulture](https://stackoverflow.com/questions/46778141/datetime-formats-used-in-invariantculture)
