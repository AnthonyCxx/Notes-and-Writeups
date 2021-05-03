# Bash Script Format
\#! /bin/bash <br />
\<script>       <!-- Had to put a '\<' because '<script>' is an html tag... -->

### Waiting on Commands to Finish
Adding an `&` to the end of a command will run the command 'in the background',
allowing you to continue without having to wait on it.

### Bash Options
- `bash -n` - reads the program without executing it. Used to check the syntax of a program
- `bash -v` - echoes the commands as it runs (includes comments)
- `bash -x` - echoes the command BEFORE it runs the command (does not include comments)

# Brackets
### Square Brackets []
#### Globbing - [link](https://tldp.org/LDP/abs/html/globbingref.html)
`ls -l file01[359]` - lists files file013, file015, and file019

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


# Wildcards
|  |  |
| -- | -- |
| * | mactches any character 0 or more times |
| ? | maches any character 1 or more times |
| \[\] | maches any character in the set |

# Sources
[Linux.com](https://www.linux.com/): [curly braces](https://www.linux.com/topic/desktop/all-about-curly-braces-bash/), square braces [part 1](https://www.linux.com/training-tutorials/using-square-brackets-bash-part-1/) and [part 2](https://www.linux.com/training-tutorials/using-square-brackets-bash-part-2/) <br />
