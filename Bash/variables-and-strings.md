# Does Bash have Variable Types?
Well, no, not really. Take a look at this excerpt from [The Linux Documentation Project](https://tldp.org/LDP/abs/html/untyped.html): <br />
> Unlike many other programming languages, Bash does not segregate its variables by "type." 
Essentially, Bash variables are character strings, but, depending on context, Bash permits arithmetic operations and comparisons on variables. 
The determining factor is whether the value of a variable contains only digits.

When using _printf_, you should think of conversion specifiers more as a sort of formatting than anything. <br />
Below are some of the qualities and operations of variables and strings.

# Variables
## Qualities of a Variable
1. Begin with a letter or an underscore (underscores are counted as letters in Bash and in programing like [Vim](https://www.vim.org/))  
2. Can contain letters, numbers, or an underscore
3. Are case-sensitive; e.g. `myvar` is not the same as `myVar`
4. Are called in the program with a `$` prepended

## Declaring a Variable
1. Assigned values EXACTLY as follows: `var=10`. Bash is _very_ picky about spacing.
2. `declare -x <var>` exports a variable (lets you use it outside the current script). Alternatively, use `export <var>`

## Pre-defined Variables

# Strings

#### Modifying Strings
```bash
string="some phrase"

echo this is a ${string#some}
```
This snippet would echo `this is a phrase`, as the `string#some` would remove `some` from the string.
