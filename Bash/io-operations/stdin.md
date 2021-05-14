# What is Stdin?

# Read
The read command accepts input from the user until a delimiter is read (newline, `\n`, by default) and then assigns the input to a variable. <br />
A general read command would like like: `read -r -p "Input: " VAR`, which prompts the user with `Input: `  and then stores the input in `$VAR`. <br />
Refer below for explanations of the flags.

### Read Options
| Option | Function |
| ------ | -------- |
| `-p <str>` | prompts the user for input |
| `-r` | read as raw string. _Always_ use this option. |
| `-a <str>` | store input in an array named `<str>` |
| `-s` | silent; do not display keystrokes on-screen |
| `-t <int>` | accepts input for only `<int>` seconds |
| `-d <str>` | stop reading after `<str>` |

### Example
```bash
read -r -p "Input: " INPUT         # User enters 'one two three'
printf "Input read: $INPUT\n"      # $INPUT outputs 'one two three'
```
> If multiple variables are specified, then each variable will get a single word, and the final variable will take the rest.

# Commandline Arguments
#### Positional Arguments
By default, each commandline argument is stored in a variable by the name of its order. `$1` is the first argument, `$2` is the second argument, etc. 
(`$0` is the name of the command)

#### Referring to All Arguments
There are two ways to refer to all arguments in Bash: `$*` and `$@`. <br />
`$*` will refer to all the arguments as a single string, while `$@` refers to them as a list of independent strings.
