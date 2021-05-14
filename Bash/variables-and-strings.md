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
2. Can contain letters, numbers, or an underscore.
3. Are case-sensitive; e.g. `myvar` is not the same as `myVar`.
4. Are called in the program with a `$` prepended.

## Declaring a Variable
1. Assigned values _exactly_ as follows: `var=10`. Bash is _very_ picky about spacing.
2. `declare -x <var>` exports a variable (lets you use it outside the current script). Alternatively, use `export <var>`.

## Notes on Variables
- You can assign a string to a variable without using quotes if it has no spaces (`var=string`).
- Calling a non-declaring variable is the same as calling no variable at all.
- Variables act as substitutions. Putting a command into a variable and calling it will just run that command.

## Modifying Variable Calls
### Infixing a Variable in a String
To set apart a variable, put `{ }` around it.
```bash
letterH='H'
snippet=' sharpen'

echo ${letterH}ouse       #Echos 'House'
echo pencil${snippet}er   #Echos 'Pencil Sharpener'
```

### Substituting Text in a String
You can substitute text in a string with the structure `${var/old_pattern/new_pattern}`. 
```bash
var="a house made of three and a fourth walls"
echo ${var/made of/with}   #Replaces 'made of' with 'with' in the string
```

### Removing the Beginning of a String
Calling a variable in `{ }` with a `#' on the end and a set of the character from the beginning will remove them from the output
```bash
string="some phrase"

echo this is a ${string#some} #Echos 'this is a phrase'
```

### Removing the End of a String
Calling a variable in `{ }` with a `%` on the end and a a set of the final characters will remove them from the output
```bash
var=call
echo ${var%ll}   #Echos 'ca'
```
> Note: If you do not know the characters, use the Shell wildcards `?` and `*`. <br />
  On another note, `%%` or `##` can be used directly after the variable name to make the result greedy.

## Pre-defined Variables
Bash has some useful variables built-in that are exteremely useful when writing scripts. <br />
Below is a list of some of those variables.

| Variable | Function |
| -------- | -------- |
| `$?` | stores whether or not the proceeding command succeeded or failed |
| `$PS1` | the standard prompt string for your shell |
| `$USER` | the username of the script executer |
| `$*` or `$@ `| all the commandline arguments for the script |
| `$PATH` | the path environment variable. Do _**not**_ play with this. |

This list is not comprehensive, but [this one](https://sodocumentation.net/bash/topic/4797/internal-variables) is.
