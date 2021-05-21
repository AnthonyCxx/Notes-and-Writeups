# Header
Level: 2 -> 3 <br />
Server: bandit2@bandit.labs.overthewire.org -p 2220 <br /> 
Password: CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9 <br />

## Given
Read the contents of a file name that includes spaces, containing the password for the next level.

## Explanation

### Interpretation of Commandline Arguments
Commands in Linux take arguments, or user-given input to be used in running the command. Often, this is the name of a file or some other user input. The commandline 
differentiates between these arguments with spaces, so it's only natural that a problem would arise if you had a single argument, such a file name, with spaces in it.
Linux provides a two main ways to get around this problem: the usage of  backslashes after each word and the usage of quotation marks (single or double). As a note, 
it is often best practice to use some other method than spaces to denote different words in a filename; personally, I use camel case, but it is also common to see people
use underscores.

## Terminal Execution
```bash
ls
cat "spaces in this filename"
```

## Resources 
[OverTheWire Bandit Level 2](https://overthewire.org/wargames/bandit/bandit3.html) <br />
[Linux - Command Line Arguments](https://www.javatpoint.com/linux-arguments) <br />
[Linux - Read Files with Spaces](https://linoxide.com/linux-command/how-to-read-filename-with-spaces-in-linux/) <br />
[What is camelCase?](https://techterms.com/definition/camelcase) <br />
