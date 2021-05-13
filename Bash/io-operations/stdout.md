## Echo
Prints text to stdout (the terminal) <br />
`echo` performs differently from OS to OS, use `printf` in industry scripts. <br />

A note: If you use single quotes, any variables will not be replaced. Use no quotes or standard, double quotes.

| Option | Function |
| ------ | -------- | 
| `-n` | do not include newline | 
| `-e` | enable escape characters |
| `-E` | disable escape characters (default) |

## Printf
Like _echo_, _printf_ outputs text 

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
To be done :/
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
