# Header
Level: 4 -> 5 <br />
Server: bandit4@bandit.labs.overthewire.org -p 2220 <br />
Password: pIwrPrtPN36QITSp3EQaw936yaFoFgAB <br />

## Given
In your home directory, there is a child directory. In the child directory, there are ten (10) files. Find out which file contains the password without opening any of them nor outputting the contents. 

## Context

### The _file_ Command
The 'file' command in Linux attempts to classify a file based on its qualities into a given category. Some common categories are: directories, executables, text files, and data
files. Directories are files that hold the name and address in memory to other files (in Linux, everything is a file). Executables contain a compiled program and its
information. Data files are hard to group, since there are so many kinds of data, but it is not uncommon for a data file to contain binary or to contain non-printable 
characters. Text files only contain printable characters (typically ASCII characters, but could be UTF-8 or other).

## Don't Forget!
Remember from level one (1) that in order to work with a file that begins with a hyphen, you have to use './' as a delimiter

## Explanation

### Assessing the Situation
First find and navigate to the child directory that the files are located in. Then, list the contents of the directory. 

### Determing the File Type of All Files Simultaneously
You could do ```file ./<file>``` for each and every file individually, but it would be far more efficient to use the '*' wildcard. The '*' wildcard matches to any and 
all patterns of characters, including no characters. Thus, doing ```file ./*``` would perform the ```file``` command on each file in the current directory sequentially. In the 
event that you wanted to limit what files you wanted to work with, you could use wildcards along with text. For example, ```file *.txt``` would perform the file command on all
.txt files.

### Finding the Text File
Now that you have listed all the types of files, look for the file marked _ASCII_. _ASCII_, which stands for "American Standard Code for Information Exchange" is a system
that maps the values of integers to characters. This standardization was developed in the 1960s and allowed computers to communicate reliably, as you could guarantee that
the message you sent would be the message that they received.

### Is all Text ASCII?
Put shortly: no, Not all text is ASCII; however, all ASCII is text. ASCII is _a_ standardized system used for representing characters/text. Although ASCII is common, it is
notably limited to simple English characters. More modern systems use more all-encompassing systems which can represent more characters, such as foreign languages. For
example, Windows uses [UTF-16](https://www.ibm.com/docs/en/i/7.2?topic=unicode-utf-16) internally.

## Terminal Execution
```bash
ls
cd inhere/
ls
file ./*
cat ./-file07
```

## Resources
[OverTheWire Bandit Level 4](https://overthewire.org/wargames/bandit/bandit5.html) <br />
[Linux Manual for 'file'](https://www.man7.org/linux/man-pages/man1/file.1.html) <br />
[GNU/Linux Tool Summary for Wildcards and Regular Expressions](https://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm) <br />
[Wikipedia - ASCII](https://en.wikipedia.org/wiki/ASCII) <br />
[Microsoft Docs - Windows Internal Unicode](https://docs.microsoft.com/en-us/windows/win32/intl/unicode) <br />
