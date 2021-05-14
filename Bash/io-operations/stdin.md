# What is Stdin?


## Commandline Arguments
- By default, each commandline argument is stored in a variable by the name of its order. `$1` is the first argument, etc. (`$0` is the name of the command)

### Referring to All Arguments
There are two ways to refer to all arguments in Bash: `$*` and `$@`. `$*` will refer to all the arguments as a single string, while `$@` refers to them as a list of independent strings.
