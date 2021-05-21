# Header
Level: 1 -> 2 <br />
Server: bandit1@bandit.labs.overthewire.org -p 2220 <br />
Password: boJ9jbbUNNfktd78OOpsqOltutMc3MY1 <br />

## Given
There is a file in the home directory that is named '-'. Read the file, as it contains the password for the next level

## Context

### Character Interpretation by the Terminal
Bash is a wonderfully flexible tool, and that flexibility is predicated on a set of special characters and operators, 
which are not interpreted literally and instead perform special instructions. In this exercise, you are tasked with reading a file whose name is just an operator. 
This means that you will need to find a workaround; what you need is a way to indicate that the operator should be interpreted literally. 
The given operator,  a dash or the '-' symbol, in bash can be used for giving a command an option and some programs also use it for reading 
from stdin (standard input).

## Explanation

### Initial Assesement
As always, start by getting a feel for the problem. Use the 'ls' command to list all the files in the directory (folder). 

### Terminal Interpretation of the _-_ Character
You can try to read the file with 'cat -', but this will cause the program from stdin (your keyboard in this case). If you did actually just try that, then use the command 'ctrl + c' to terminate the command/program.

### Delimiting 
Now, to explicitly indicate that '-' is a file, you can put the pathname './' in front of it. The '.' refers to the current directory (folder) and the '/' separates the current directory and the name of the file. So, if you try 'cat ./-', you will be able to read the contents of the file.

## Terminal Execution
```bash
ls
cat ./-
```

## Resources
[OverTheWire Bandit Level 1](https://overthewire.org/wargames/bandit/bandit2.html) <br />
[Bash - Special Characters and Operators](https://www.cs.ait.ac.th/~on/O/oreilly/unix/upt/ch08_19.htm) <br />
[How to Read Dashed Files](https://stackoverflow.com/questions/42187323/how-to-open-a-dashed-filename-using-terminal) <br />
[Linux - What is Standard Input?](http://www.linfo.org/standard_input.html) <br />
