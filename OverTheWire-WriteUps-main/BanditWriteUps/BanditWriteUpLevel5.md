# Header
Level: 5 -> 6 <br />
Server: bandit5@bandit.labs.overthewire.org -p 2220 <br />
Password: koReBOKuIDDepwhWk7jZC0RTdopnAYKh <br />

## Given
There is a parent directory with 20 child directories inside of it, each with nine (9) files within those child directories. Find the file containing the key without leaving the initial parent directory, 'bandit5'. The file containing the key is human-readable, not an executable, and 1033 bytes in size. Use these three parameters to find the file.

## Context
Linux's 'find' command searches a specified directory (even possibly the root directory '\') for a file based on some criteria and then list the matching files at the  console. If no directory is given, then it will assume the current directory. If no criteria is given, then the find command will recursively list every file within the given directory. The format for the find command is: 'find <search_directory> <criteria>'.

## Explanation
As an initial exercise, start by running 'find .' to see how the find command works. Add the option '-type f' to the line, which searches only for regular files.
Now, add the '-readable' option to the line, specifying that you are only looking for text files (files that are human-readable). The next step requires you
to search for non-executables; however, there is no command that specifically searches for non-executables. So, you will have to use the '-executable' and negate
it by putting a '!' character followed by a space in front of the executable option. If you are not familiar with the '!' character (bang) being used for negation,
then you should memorize it, as the bang character is ubiquitous in programming languages for negation. Finally, you can add the '-size' option, which specifies 
the file size in bytes, kibibytes, mebibytes, or gibibytes (no, not kilobytes, etc.) based on the letter included after the number - for example, 10M is 10 mebibytes.
In our case, as we are looking to measure the bytes of the file, we should use '-size 1033c' to represent 1033 bytes. 'c' is used for bytes instead of 'b' since 'b' 
is already reserved for searching by 512-bit blocks. Run the command and then cat the contents of the file.
 
## Terminal Execution
```bash
ls
find . -type f -readable ! -executable -size 1033c
```

## Extra Notes
1. You may think that I misspelt "kilobytes", "megabytes", and "gigabytes", but here I am deliberately referring to
   -ibibyte units. Most people are familiar with the -ib- infix (a prefix, but in the middle of a word), but mistakenly exclude it, only using the -byte ending. 
   Put shortly, the -byte suffix alone measures bytes to the power of ten (10), while units with the -ib- infix measure bytes to the power of two (2). 
   This means that a kilobyte is equal to 1000 bytes and a kibibyte is equal to 1024 bytes. Originally, a kilobyte was actually 1024 bytes, which is the 
   reason for all the confusion, but it was changed in 1998 by the IEC (International Electrotechnical Commission) when they created standardized prefixes for binary. 
   Still, most people, including manufacturers tend to equate the -byte alone with 1024 bytes, as measuring in actual kibibytes would make it seem like 
   their devices have less storage and memory. 

2.  Though it is not used here, the '-name' option is extremely useful, especially when paired with the wildcards '?' and '*'.

 
## Resources
[OverTheWire Bandit Level 5](https://overthewire.org/wargames/bandit/bandit6.html) <br />
[Linux Manual Page for 'find'](https://man7.org/linux/man-pages/man1/find.1.html) <br />
[Bash Special Characters](https://mywiki.wooledge.org/BashGuide/SpecialCharacters) <br />

[What is a kibibyte? Kibibyte vs kilobyte](https://superuser.com/questions/287498/what-is-the-difference-between-a-kibibyte-a-kilobit-and-a-kilobyte) <br />
[Storage Size Abbreviations (KiB vs KB vs kB)](https://ux.stackexchange.com/questions/13815/files-size-units-kib-vs-kb-vs-kb) <br />
[NIST Prefixes for Binary Multiples](https://physics.nist.gov/cuu/Units/binary.html) <br />
