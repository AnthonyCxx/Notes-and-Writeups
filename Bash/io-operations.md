# Bash I/O Streams
- Standard input (stdin) 
- Standard output (stdout)
- Standard Error  (stderr)

### I/O Redirection
|  |  |
| -- | -- |
| redirect stdin | `<` |
| redirect stdout | `>` |
| redirect stderr | `2>` |
| redirect stdout _and_ stderr | `&>` |
| redirect stderr to where stdout is directed | `2&>1` |
| redirect stdout from one command to input of another | `\|` |
| redirect stdout and stderr from one command to stdin of another | `2&>1 \|` |
| take in from stdin until specified, isolated string | `<< <string>` |

### Redirect/dispose of native error messages
`2>/dev/null` - what is [/dev/null](https://en.wikipedia.org/wiki/Null_device)?

### Echo
Prints text to stdout (the terminal) <br />

A note: If you use single quotes, any variables will not be replaced. Use no quotes or standard, double quotes.

| Option | Function |
| ------ | -------- | 
| `-n` | do not include newline | 
| `-e` | enable escape characters |
| `-E` | disable escape characters (default) |

### Printf

### Escape Characters
| Character | Function |
| --------- | -------- |
| `\\` | single backslash |
| `\b` | backspace |
| `\n` | newline |
| `\r` | carraige return |
| `\t` | horizontal tab |
| `\v` | vertical tab |
| `\a` | alert (error sound, [bel character](https://en.wikipedia.org/wiki/Bell_character)) |



#### Sources
- Linuxize: [Bash Printf Command](https://linuxize.com/post/bash-printf-command/)
- The Linux Documentation Project: [Escape Characters](https://tldp.org/LDP/abs/html/escapingsection.html)
