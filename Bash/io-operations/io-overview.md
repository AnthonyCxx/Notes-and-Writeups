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

### Redirect/dispose of error messages
`2>/dev/null` - what is [/dev/null](https://en.wikipedia.org/wiki/Null_device)?
