# Bash I/O Streams
- Standard input (stdin) 
- Standard output (stdout)
- Standard Error  (stderr)

### I/O Redirection
|  |  |
| -- | -- |
| stdin | `<` |
| stdout | `>` |
| stderr | `2>` |
| stdout and stderr | `&>` |
| redirect stderr to where stdout is directed | `2&>1` |
| redirect stdout from one command to input of another | `\|` |
| redirect stdout and stderr from one command to stdin of another | `2&>1 \|` |
| take in from stdin until specified, isolated string | `<< <string>` |
