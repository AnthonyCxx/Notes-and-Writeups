# Does Bash have Variable Types?
Well, no, not really. Take a look at this excerpt from [The Linux Documentation Project](https://tldp.org/LDP/abs/html/untyped.html): <br />
> Unlike many other programming languages, Bash does not segregate its variables by "type." 
Essentially, Bash variables are character strings, but, depending on context, Bash permits arithmetic operations and comparisons on variables. 
The determining factor is whether the value of a variable contains only digits.

When using _printf_, you should think of conversion specifiers more as a sort of formatting than anything. <br />
Below are some of the qualities and operations of variables and strings.

# Variables
## Qualities of a Variable
1. Begin with a letter or an underscore (underscores are considered alphabetic in Bash and in programs like [Vim](https://www.vim.org/))  
2. Can contain letters, numbers, or an underscore
3. Are case-sensitive; e.g. `myvar` is not the same as `myVar`
4. Are called in the program with a `$` prepended

## Declaring a Variable
1. Assigned values EXACTLY as follows: `var=10`. Bash is _very_ picky about spacing.
2. `declare -x <var>` exports a variable (lets you use it outside the current script). Alternatively, use `export <var>`

## Pre-defined Variables
| Variable | Function |
| -------- | -------- |
| `$?` | stores whether or not the proceeding command succeeded or failed |
| `$PS1` | the standard prompt string for your shell |
| `$PATH` | the path environmental variable. Do _**not**_ play with this. |
| `$USER` | the username of the script executer |
| `$*` or `$@ `| all the commandline arguments for the script |

# Strings

#### Modifying Strings
```bash
string="some phrase"

echo this is a ${string#some}
```
This snippet would echo `this is a phrase`, as the `string#some` would remove `some` from the string.

# Miscellaneous and Closing Notes
1. You can assign a string to a variable without using quotes if it has no spaces
2. If you need to attach something directly to a variable, set apart the variable with {}
3. Calling a non-declaring variable is the same as calling no variable at all
4. Variables act as substitutions. Putting a command into a variable and calling it will just run that command
