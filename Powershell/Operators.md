# Operators in Powershell
> [Arithmetic Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#arithmetic-operators) <br />
> [Assignment Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#assignment-operators) <br />
> [Comparison Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#comparison-operators) <br />
> [Logical Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#logical-operators) <br />
> [Redirection Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#redirection-operators) <br />
> [Split and Join Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#split-and-join-operators) <br />
> [Type Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#type-operators) <br />
> [Unary Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#unary-operators) <br />
> [Special Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Operators.md#special-operators) <br />

"An operator is a language element that you can use in a command or expression. PowerShell supports several types of operators to help you manipulate values."
\- Powershell Documentation: [about\_Operators, long description](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_operators?view=powershell-7.2#long-description)

# [Arithmetic Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_arithmetic_operators?view=powershell-7.2)
Arithmetic operators preform calculations (addition, subtraction, multiplication...)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `+` | addition; string concatenation | `"Hello, " + "world!"` |
| `-` | subtraction | `10 - 5` |
| `*` | multiplication; string multiplication | `"^-^ "*3` |
| `/` | division | `3 / 2` |
| `%` | modulus | `7 % 2` |
| `-band` | bitwise AND | `5 -band 0` |
| `-bnot` | bitwise NOT | `-bnot 1` |
| `-bor` | bitwise OR | `5 -bor 0` |
| `-bxor` | bitwise XOR | `5 -bxor 5` |
| `-shl` | shift bits left | `5 -shl 2` |
| `-shr` | shift bits right | `5 -shr 2` |
> For integer division, don't just cast to `[int]`, since that rounds; use [math]::Floor()

# [Assignment Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_assignment_operators?view=powershell-7.2)
Assignment operators assign a value to a variable. The assignment operator `=` can be combined with arithmetic operators to create compound operators such
as `+=`, which adds the value of the right expression to the variable instead of overwriting it.

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `=` | assigns a value to a variable | `$today = Get-Date` |
| `+=` | adds the right expression to the variable | `$count += 5` |
| `-=` | subtracts the right expression from the variable | `$total -= 5` |
| `*=` |  | `` |
| `/=` |  | `` |
| `%=` |  | `$index %= length` |
| `++` |  | `$count++` |
| `--` |  | `$timer--` |

# [Comparison Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Logical Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_logical_operators?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Redirection Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_redirection?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Split and Join Operators]()
> [about\_Split](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_split?view=powershell-7.2) <br />
> [about\_Join](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_join?view=powershell-7.2) <br />

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Type Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_type_operators?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Unary Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_operators?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# [Special Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_operators?view=powershell-7.2)

| Operator | Function | Example | 
| -------- | -------- | ------- | 
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# Sources
- Powershell Documentation: [about\_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_operators?view=powershell-7.2)
- Powershell Documentation: [about\_Arithmetic\_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_arithmetic_operators?view=powershell-7.2)
- Powershell Documentation: [about\_Assignment\_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_assignment_operators?view=powershell-7.2)
- Powershell Documentation: [about\_Comparison\_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_comparison_operators?view=powershell-7.2)
- Powershell Documentation: [about\_Logical\_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_logical_operators?view=powershell-7.2)
- Powershell Documentation: [about\_Redirection](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_redirection?view=powershell-7.2)
- Powershell Documentation: [about\_Split](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_split?view=powershell-7.2)
- Powershell Documentation: [about\_Join](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_join?view=powershell-7.2)
- Powershell Documentation: [about\_Type_Operators](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_type_operators?view=powershell-7.2)
- MindMajix: [Powershell Operators](https://mindmajix.com/powershell-operators)
