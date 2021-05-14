# What is Stdout?
...

# Echo
Prints text to stdout (the terminal) <br />

A note: If you use single quotes, any variables will not be replaced. Use no quotes or standard, double quotes.

| Option | Function |
| ------ | -------- | 
| `-n` | do not include newline | 
| `-e` | enable escape characters |
| `-E` | disable escape characters (default) |

# Printf
Like _echo_, _printf_ outputs text to the screen; however, _printf_ is more complex and provides more control over the formatting of the output. <br />
Futhermore, _printf_ should be used where portability is important, as the behavior of _echo_ varies from system to system.

### Escape Characters
| Character | Function |
| --------- | -------- |
| `\n` | newline |
| `\t` | horizontal tab |
| `\\` | single backslash |
| `\r` | carraige return |
| `\b` | backspace |
| `\v` | vertical tab |
| `\a` | alert (error sound, [bel character](https://en.wikipedia.org/wiki/Bell_character)) |

### Conversion Specifiers
| Character | Replaced By |
| --------- | -------- |
| `%d` | an decimal (base-10) integer |
| `%f` | a decimal floating point |
| `%s` | a string |
| `%%` | a percent sign |
| `%x`, `%X` | a hexadecimal integer |

This list is not [comprehensive](https://linuxize.com/post/bash-printf-command/)

#### Notes
- Putting a whole number after the `%` in a numeric specifier will change the width field to equal that amount of characters.
- If you put a `0` in front of the width specifier, it will pad the empty space with 0s.
- You can change the precision of a float by putting a decimal after the `%` in `%f` (`.2` for two decimal places).
- Putting a `#` before the `x` in `%x` / `%X` will prepend a `0x` to indicate it is a hex digit.

## Sources
- Linuxize: [Bash Printf Command](https://linuxize.com/post/bash-printf-command/)
- The Linux Documentation Project: [Escape Characters](https://tldp.org/LDP/abs/html/escapingsection.html)
