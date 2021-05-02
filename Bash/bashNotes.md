## Bash Script Format
\#! /bin/bash

## Bash I/O Streams
- Standard input (stdin) 
- Standard output (stdout)
- Standard Error  (stderr)

### Standard I/O Redirection
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

## Commands
`bash --version` - gets version of Bash

## Waiting on Commands to Finish
Adding an `&` to the end of a command will run the command 'in the background',
allowing you to continue without having to wait on it.

## Run multiple commands in a single line
`firstCommand ; secondCommand`
