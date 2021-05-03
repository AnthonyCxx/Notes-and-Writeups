# Bash Script Format
\#! /bin/bash <br />
\<script>       <!-- Had to put a '\<' because '<script>' is an html tag... -->

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

### Waiting on Commands to Finish
Adding an `&` to the end of a command will run the command 'in the background',
allowing you to continue without having to wait on it.

### Bash Options
- `bash -n` - reads the program without executing it. Used to check the syntax of a program
- `bash -v` - echoes the commands as it runs (includes comments)
- `bash -x` - echoes the command BEFORE it runs the command (does not include comments)


# Control Flow

### Operators
|  |  |
| -- | -- |
| Run second command if first succeeds | `&&` |
| Run second command if first fails | `\|\|` |


### Redirect/dispose of native error messages
`2>/dev/null`

### Control Operators
|  |  |
| -- | -- |
| group commands in main shell | `{ command1 ; command2 ; }` |
| run commands in subshell | `( command1 ; command2 ; )` |

### Control Syntax
- If statement
```bash
if [ ! -d someDir ]   # Normally, you would not use need the [], but here you do           
then                 
  echo directory \'someDir\' does not exist, creating directory \'someDir\'
  mkdir someDir
else
  echo directory \'someDir\' exists...
```

# Brackets
### Square Brackets []
#### Globbing - [link](https://tldp.org/LDP/abs/html/globbingref.html)

### Curly Brackets {}
#### Building Arrays
|  |  |
| -- | -- |
| `echo {0..10}` | print the numbers 0-10 |
| `echo {10..0}` | print 0-10 backwards |
| `echo {0..10..2}` | print every other element in the list 0-10 (2, 4, 6, 8, 10) |
| `echo {0..9}{0..9}` | combine sequences, printing all numbers 0-99 |

#### Accessing Array Elements
```bash
someArray=("firstElement", "secondElement", "thirdElement")
itemOne={someArray[0]}
```
# Arrays
`personalInfo=("John Doe", "(000)-000-0000", "000 something road, 00000")`


# Sources
[Linux.com](https://www.linux.com/): [curly braces](https://www.linux.com/topic/desktop/all-about-curly-braces-bash/), square braces [part 1](https://www.linux.com/training-tutorials/using-square-brackets-bash-part-1/) and [part 2](https://www.linux.com/training-tutorials/using-square-brackets-bash-part-2/) <br />
