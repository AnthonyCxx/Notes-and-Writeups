# Wildcards and Regular Expressions in Powershell
> [Wildcards](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Wildcards%20and%20Regular%20Expressions.md#wildcards) <br />
> [Regular Expressions](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Wildcards%20and%20Regular%20Expressions.md#regular-expressions) <br />

Wildcards and regular expressions are methods of using a series of characters (i.e. a string) to define a pattern that can be matched against. For example, if you wanted
a 3-5 digit number from your user, you could do it arithmetically by repeatedly dividing by 10 and incremeting a counter each time, but it can be done more easily by just
defining a pattern. In this case, the regular expression `\d{3,5}` would match with any number that's 3-5 digits long.

# [Wildcards](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_wildcards?view=powershell-7.2)
Wildcards are the simplest form of pattern creating, supporting basic matching operations. When using wildcards, you use the `-like` and <br /> `-notlike` operators.

| Metacharacter | Matches with | Example |
| ------------- | -------- | ------- |
| `*` | 0 or more of any character | `Get-Command -Name "Test-*"` |
| `?` | 1 of any character | `Get-Command -Name "?et-Net*"` |
| `[]` | 1 of any character in the square brackets | `$arr.where({$_ -like "[cdt]ry"})` |
> [] can also represent a range of characters via a hyphen (e.g. [a-z])

# [Regular Expressions](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_regular_expressions?view=powershell-7.2)
Regular expressions are far more comprehensive than wildcards, allowing for complex expressions like [this email validator](https://www.emailregex.com/). As a consequence,
though, they are much harder to read. Regular expressions use the `-match`, `-notmatch`, and `-replace` operators as well as the `Select-String` cmdlet.

## Patterns
| Metacharacter | Matches with | Example |
| ------------- | -------- | ------- |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

## Quantifiers
| Quantifier | Matches \_ Times | Example | 
| ---------- | ---------------- | ------- |
| `*` | 0+ times | `` |
| `+` | 1+ times | `` |
| `?` | 0-1 time | `` |
| `{n,m}` | [n,m) times | `` |

## Structures

| Structure | Function | Example |
| ------------- | -------- | ------- |
| `[]` | matches with one of a set of characters | `[abc]` |
| `[^]` | matches with one of any character not in the set | `[^abc]` |
| `[-]` | matches with one of a range of characters | `[a-z0-9]` |

# Sources
- Powershell Documentation: [about\_Wildcards](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_wildcards?view=powershell-7.2) 
- Powershell Documentation: [about\_Regular\_Expressions](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_regular_expressions?view=powershell-7.2) 
- .NET [Regular Expressions Quick Reference](https://docs.microsoft.com/en-us/dotnet/standard/base-types/regular-expression-language-quick-reference) <br />
- .NET [.NET Regular Expressions](https://docs.microsoft.com/en-us/dotnet/standard/base-types/regular-expressions) <br />
- .NET [Details of Regular Expression Behavior](https://docs.microsoft.com/en-us/dotnet/standard/base-types/details-of-regular-expression-behavior)
- .NET: [Best Practices for Regular Expressions](https://docs.microsoft.com/en-us/dotnet/standard/base-types/best-practices) <br />
- Microsoft TechNet: [Working with Regular Expressions (regex)](https://social.technet.microsoft.com/wiki/contents/articles/4310.powershell-working-with-regular-expressions-regex.aspx) <br /> 
