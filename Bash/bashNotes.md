# Bash Script Format
\#! /bin/bash <br />
\<script>       <!-- Had to put a '\<' because '<script>' is an html tag... -->

# Bash I/O Streams
- Standard input (stdin) 
- Standard output (stdout)
- Standard Error  (stderr)

## Standard I/O Redirection
|  |  |
| -- | -- |
| stdin | `<` |
| stdout | `>` |
| stderr | `2>` |
| stdout and stderr | `&>` |
| redirect stderr to where stdout is directed | `2&>1` |
| redirect stdout from one command to input of another | `\|` |
| redirect stdout and stderr from one command to input of another | `2&>1 \|` |
| take in from stdin until specified, isolated string | `<< <string>` |

## Waiting on Commands to Finish
Adding an `&` to the end of a command will run the command 'in the background',
allowing you to continue without having to wait on it.

## Bash Options
- `bash -n` - reads the program without executing it. Used to check the syntax of a program
- `bash -v` - echoes the commands as it runs (includes comments)
- `bash -x` - echoes the command BEFORE it runs the command (does not include comments)


# Control Flow

## Operators
|  |  |
| -- | -- |
| Run second command if first succeeds | `&&` |
| Run second command if first fails | `\|\|` |


### Redirecting native error messages
`2>/dev/null`



