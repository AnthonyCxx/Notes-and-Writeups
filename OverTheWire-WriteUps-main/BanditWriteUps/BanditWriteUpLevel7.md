## Header
Level: 7 -> 8 <br />
Server: bandit7@bandit.labs.overthewire.org -p 2220 <br />
Password: HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs <br />
 
## Given
There is a file in your home directory that contains the password to the next level; the password is on the same line as the word "millionth".
 
## Explanation

### What is Grep?
This level serves as an introduction to one of Linux's most loved and commonly-used features, grep. Grep is a command that stands for 
"global  /regular expression / print", which sounds strange, but tells you exactly what grep does. Basically, grep searches all the contents of whatever
information you give it, be it a file or the contents of a search, looks for all the instances of the expression you are looking for, and then prints out 
each line it finds that expression on. If you are familiar with Python's regex module, then you should find grep very familiar. 

### Piping in Linux (vs Redirection)
In addition to teaching you the basics of grep, I will also illustrate a concept that will prove essential as early as next level. This concept is called "piping". 
A pipe is a character used between two commands to redirect the output from one command to be used as the input for another and is denoted by a "|", called a pipe. 
In this example, you will be piping the contents of the data.txt file into grep. First, find the file that contains the password. Then, output the contents of the file to see if a search is even necessary. The file is very long. Use word count with the -l option to find the amount of lines in the file. There are 98,567 lines in the file - grepping is unavoidable. In one line, output the file contents with cat, write pipe symbol ('|') and then grep the contents for the word "millionth". Now, you could have just done 'grep "millionth" data.txt', as it does the same thing; however, seeing grepping and piping together is extremely common and it is best to teach the concepts in tandem.
 
 ### Final Note
 Yes, you could have just done ```grep "millionth" data.txt```, however, piping is too important to grep to not learn to use.
 
## Terminal Execution
```bash
ls
cat data.txt
wc -l data.txt
cat data.txt | grep "millionth"
```
 
## Resources
[OverTheWire Bandit Level 7](https://overthewire.org/wargames/bandit/bandit8.html) <br />
[Linux Manual Pages](https://man7.org/linux/man-pages/index.html) <br />
[Linux Manual for 'strings'](https://man7.org/linux/man-pages/man1/strings.1.html) <br />
[Linux Manual for 'grep'](https://man7.org/linux/man-pages/man1/grep.1.html) <br />
[Where G/RE/P came from](https://www.youtube.com/watch?v=NTfOnGZUZDk) <br />
[Grepping and Piping](https://www.youtube.com/watch?v=U9SI-wYRD1M) <br />
