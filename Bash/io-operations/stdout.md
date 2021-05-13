# Echo
Prints text to stdout (the terminal) <br />

A note: If you use single quotes, any variables will not be replaced. Use no quotes or standard, double quotes.

| Option | Function |
| ------ | -------- | 
| `-n` | do not include newline | 
| `-e` | enable escape characters |
| `-E` | disable escape characters (default) |

# Printf
Like _echo_, _printf_ outputs text to the screen; however, although more complex,  _printf_ provides more control over the formatting of the output. <br />
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
| Character | Function |
| --------- | -------- |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |

#### Sources
- Linuxize: [Bash Printf Command](https://linuxize.com/post/bash-printf-command/)
- The Linux Documentation Project: [Escape Characters](https://tldp.org/LDP/abs/html/escapingsection.html)
