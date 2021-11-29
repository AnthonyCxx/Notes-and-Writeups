# Variables and Datatypes in Powershell
Variables are flexible storage locations for data that can be invoked by name. Powershell is a [strong, dynamically-typed](https://www.smashingmagazine.com/2013/04/introduction-to-programming-type-systems/) language, which means that although variables do have a datatype, they can change dynamically.

## Datatypes (Type Accelerators)

| Datatype | Shorthand | Function | Min Value | Max Value | Default Value | 
| -------- | --------- | -------- | --------- | --------- | ------------- |
| `[void]` | - | uninstantiable; hides output; similar to `Out-Null` | - | - | - |
| `Null` | - | represents nothing – an absence; stored in `$null` | - | - | - |
| `[System.Object]` | `[object]` | base type for all other types | - | - | - |
| `[System.Boolean]` | `[bool]` | standard boolean type; stores _true_/_false_ | - | - | false |
| `[System.Char]` | `[char]` | unsigned 16-bit character; UTF-16 compatible | 0 | 65,535 | null |
| `[System.Byte]`| `[byte]` | 8-bit unsigned integer | 0 | 255 | 0 |
| `[System.Int32]` | `[int]` | 32-bit signed integer | -2,147,483,648 | 2,147,483,647 | 0 |
| `[System.Int64]` | `[long]` | 64-bit signed integer | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 0 |
| `[]`| `` |  |  |  |  |
| `[]`| `` |  |  |  |  |
| `[]`| `` |  |  |  |  |
| `[]`| `` |  |  |  |  |
> Types can also be accessed by their name without the `System.` prefix -> int == Int32

---

## Declaring and Using Variables


```Powershell
$name = "foobar"
```

---

# Sources
- Powershell Documentation: [about\_Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_variables?view=powershell-7.2)
- SS64: [How-to: Variables and Operators](https://ss64.com/ps/syntax-variables.html)
- Educba: [Powershell Variables](https://www.educba.com/powershell-variables/)
- Powershell Documentation: [Types - Powershell](https://docs.microsoft.com/en-us/powershell/scripting/lang-spec/chapter-04?view=powershell-7.2#41-special-types)
- The Automation Code: [Variables and Datatypes in Powershell](https://theautomationcode.com/variables-and-datatypes-in-powershell/)
- SS64: [How-to: Define PowerShell Data Types](https://ss64.com/ps/syntax-datatypes.html)
