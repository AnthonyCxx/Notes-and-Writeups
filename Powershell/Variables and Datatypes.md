# Variables and Datatypes in Powershell
Variables are flexible storage locations for data that can be invoked by name. Powershell is a [strong, dynamically-typed](https://www.smashingmagazine.com/2013/04/introduction-to-programming-type-systems/) language, which means that although variables do have a datatype, they can change dynamically.

## Datatypes and Type Accelerators
Below is a table of some common datatypes and their attributes. You can find a comprehensive list of datatypes [here](https://docs.microsoft.com/en-us/powershell/scripting/lang-spec/chapter-04?view=powershell-7.2). Some of the names of the types are rather long, so Powershell provides a list of shorthands/aliases for datatypes called 
[type accelerators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_type_accelerators?view=powershell-7.2), allowing 
you to just write `[hashtable]` instead of `[System.Collections.Hashtable]`.

| Datatype | Shorthand | Function | Min Value | Max Value | Default Value | 
| -------- | --------- | -------- | --------- | --------- | ------------- |
| `[void]` | - | hides output; similar to `Out-Null` | - | - | - |
| `Null` | - | represents nothing – an absence; stored in `$null` | - | - | - |
| `[System.Object]` | `[object]` | base type for all other types | - | - | - |
| `[System.Boolean]` | `[bool]` | standard boolean type; stores _true_/_false_ | - | - | false |
| `[System.Char]` | `[char]` | unsigned 16-bit character; UTF-16 compatible | 0 | 65,535 | null |
| `[System.String]`| `[string]` | immutable sequence of chars | - | - | null |
| `[System.Byte]`| `[byte]` | 8-bit unsigned integer | 0 | 255 | 0 |
| `[System.Int32]` | `[int]` | 32-bit signed integer | -2,147,483,648 | 2,147,483,647 | 0 |
| `[System.Int64]` | `[long]` | 64-bit signed integer | -9.223 quintillion | 9.223 quintillion | 0 |
| `[System.Single]`| `[float]` | 32-bit floating-point | -3.402823E+38 | 3.402823E+38 | 0 |
| `[System.Double]`| `[double]` | 64-bit floating-point | -1.79769313486232E+308 | 1.79769313486232E+308 | 0 |
| `[System.Decimal]`| `[decimal]` | 128-bit floating-point; suitable for money | -79.228 octillion | 79.228 octillion | 0 |
| `[System.DateTime]`| `[datetime]` | object for dates and time | - | - | - |
| `[System.Array]`| `[array]` | heterogenous sequence of items | - | - | - |
| see below | `[hashtable]` | associative array | - | - | - |
> \> Types can also be accessed by their name without the `System.` prefix -> `[int]` is the same as `[Int32]` <br />
> \> The full name for `[hashtable]` is `[System.Collections.Hashtable]`, but that was too big to fit, unfortunately.

---

## Declaring and Using Variables
Variables can be declared directly by writing `$<variable_name_here>` or by using the `New-Variable` cmdlet ([ref](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/new-variable?view=powershell-7.2)). As a practice, always declare variables with static typing
if you can, as it makes the program more predicatable and easier to read.

```Powershell
# Declaring a dynamically-typed variable
$name = "foobar"       # Variable '$name' is instantiated as System.String
$name = [math]::pi     # '$name' is re-typed to [System.Double]` after being assigned '[math]::pi'

# Declaring a statically-typed variable
[byte]$smallnum = 120     # Assign the value '120' to the variable '$smallnum'
$smallnum = -12           # Assignment fails because '$smallnum' cannot be re-typed to [Int32]
```

---

# Sources
- Powershell Documentation: [about\_Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_variables?view=powershell-7.2)
- SS64: [How-to: Variables and Operators](https://ss64.com/ps/syntax-variables.html)
- Educba: [Powershell Variables](https://www.educba.com/powershell-variables/)
- Powershell Documentation: [Types - Powershell](https://docs.microsoft.com/en-us/powershell/scripting/lang-spec/chapter-04?view=powershell-7.2#41-special-types)
- The Automation Code: [Variables and Datatypes in Powershell](https://theautomationcode.com/variables-and-datatypes-in-powershell/)
- SS64: [How-to: Define PowerShell Data Types](https://ss64.com/ps/syntax-datatypes.html)
