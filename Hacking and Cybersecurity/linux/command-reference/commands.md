# A Reference for Linux Terminal Commands
Replace anything in `< >` or `[ ]` with the proper substitute. `< >` denotes necessary things and `[ ]` denotes things that are optional.

## Basic Commands
| Command | Action |
| ------- | ------ |
| ls | list the files and subdirectories of the current directory |
| cd \<path\> | change directories |
| whoami | echos username; equal to `echo $USER` |
| pwd | echos the name of the current directory |

## Getting Help  
| Command | Action |
| ------- | ------ |
| \<command\> --help | display the help page for a command |
| man \<command\> | display the manual page |
  
## Working with Files and Directories
| Command | Action |
| ------- | ------ |
| touch \<filename\> | create a file with the given filename |
| mkdir \<dir name\> | create a new directory (folder) |
| rm \<filename/directory\> | remove (delete) a file |
| rmdir \<directory\> | remove (delete) a directory (requires _-r_ flag if the directory is not empty) |
| cat \<file\> | prints the content of a file |
| nl \<file\> | cat a file, but with line numbers |
| mv <file> <new path/name> | move/rename a file ; [reference](https://www.serverlab.ca/tutorials/linux/administration-linux/how-to-rename-and-move-files-and-directories-on-linux/)|
| head \<filename\> | lists the first few lines of a file |
| tail \<filename\> | lists the last few lines of a file |

  
## Locating Items
| Command | Action |
| ------- | ------ |
| locate \<file\> | returns the [absolute file path](https://www.linux.com/training-tutorials/absolute-path-vs-relative-path-linuxunix/) of the specified file |
| whereis \<binary\> | returns the absolute file path of the specified [binary](https://www.sciencedirect.com/topics/computer-science/executable-binary-file) |
| which \<binary\> | returns the absolute file path of the specified binary (only searches [$PATH](http://www.linfo.org/path_env_var.html)) |
| find \<item\> | finds an item; has many options that provide more specific searches |
| grep | _global/regular expression/print_: searches for patterns in plaintext using [regular expressions](https://www.guru99.com/linux-regular-expressions.html) |

## System Management
| Command | Function |
| -------- | -------- |
| ps | lists running processes |
| ifconfig | analyze network information |

## Shell Operators: Wildcards, I/O Redirection, etc.
Wildcards are [metacharacters](https://en.wikipedia.org/wiki/Metacharacter) that match with other characters in special ways.

### Wildcards
| Wildcard | Function |
| -------- | -------- |
| ? | matches with any one character |
| * | match with any amount of any characters, including no characters |
| \[ \] | matches with any character provided between the brackets |

### I/O Redirection
See [this article](https://www.putorius.net/linux-io-file-descriptors-and-redirection.html#:~:text=In%20Linux%20and%20computer%20programming,and%20standard%20error%20(stderr).) for an explanation on Linux I/O streams.

| Operator | Function |
| -------- | -------- |
| < | redirect stdin |
| > | redirect stout |
| 2> | redirect |
| \| | redirect stdout of one command as stdin of the next - [guide](https://www.geeksforgeeks.org/piping-in-unix-or-linux/) |
