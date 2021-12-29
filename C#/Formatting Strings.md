# Formatting Strings in C#

---

# Left/Right Justication
Passing an integer _n_ as the second argument of an interpolated string will pad the text with spaces until it reaches length _n_.
A positive number will right-justify the text, a negative number will left-justify it.

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
