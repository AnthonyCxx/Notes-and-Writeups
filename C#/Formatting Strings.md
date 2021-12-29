# Formatting Strings in C#
The [String.Format()](https://docs.microsoft.com/en-us/dotnet/api/system.string.format?view=net-6.0) method (which is indirectly called when you use [string interpolation](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/tokens/interpolated)) is incredibly dexterous and provides a wide array of tool for formatting strings.
The document contains a collection of formatting techniques as well as examples.

---

# Indexing
By default, when calling _String.Format()_, the order of the curly braces (`{}`) is the order the  arguments are interpolated; however, the order can be manually overriden
by using indices.

```C#

```

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

| Format | Effect | 
| ------ | ------ |
| `:Nn` |  |
| `` |  |
