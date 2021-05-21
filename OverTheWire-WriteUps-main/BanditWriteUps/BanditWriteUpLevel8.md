# Header
Level: 8 -> 9 <br />
Server: bandit8@bandit.labs.overthewire.org -p 2220 <br />
Password: cvX2JJa4CFALtqS87jk27qwqGhBM9plV <br />

## Given
There is a file in your home directory that contains the password for the next level; the password only appears once in said file, while every other string appears twice or more. 

## Explanation
First things first, see if you can find the string easily by using cat. You will quickly see that this file is rather long. Use the word count 
command to see how long the file is. The file is 1001 lines long. For this challenge, you should use the uniq command to find all lines which do not appear once. 
The only catch is that the uniq command only compares adjacent lines, so first you will need to sort the file. The sort command is very straight-forward, 
and you will not need to use any sort modifiers. All you have to do is sort the file and then pipe the contents into the uniq command, searching for all the unique lines.

## Terminal Execution
```bash
ls
wc -l data.txt
sort data.txt | uniq -u
```

## Resources
[OverTheWire Bandit Level 8](https://overthewire.org/wargames/bandit/bandit9.html) <br />
[Linux Manual Pages](https://man7.org/linux/man-pages/index.html) <br />
[Linux Manual for 'sort'](https://man7.org/linux/man-pages/man1/sort.1.html) <br />
[Linux Manual for 'uniq'](https://man7.org/linux/man-pages/man1/uniq.1.html) <br />
