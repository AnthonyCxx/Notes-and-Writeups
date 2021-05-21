# Header
Level: 9 -> 10 <br />
Server: bandit9@bandit.labs.overthewire.org -p 2220 <br />
Password: UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR <br />

## Given
There is a file in your home directory that contains the password to the next level; however, the majority of the file is not human-readable. Find a way to find the human-readable lines and then parse that for the password. The line with the password is preceded by multiple "=" characters.

## Context
Not all sequences of characters qualify as text. In order to qualify as text, the sequences must be interpretable by a user. In this exercise, you will be presented with a file that is mostly composed of non-human-readable characters. The objective is to sort through the file by text and then sort through that text to find the password. In essence, the cat command outputs all the contents of a file, while strings only outputs text.

## Explanation
First find the file: data.txt. Now, try to read its contents with cat. Either the output will be a list a strange, meaningless symbols, or you will get no output at all. Investigate the file using the vi command. Notice that none of the contents are legible. So, instead of listing the contents of the entire file with cat, we will use the strings command to list only the human-readable content. You could just do 'strings data.txt', but we can with the wc command (word count) that the file has 69 lines, meaning that it will likely be time-consuming to sort through all the strings manually. So, you should pipe the output of the strings command and then use grep to sort through them for you. Note that the given clearly states that the password is proceeded by several equal signs - not just one - meaning that you should search for three or more equal signs.

## Terminal Execution
```bash
cat data.txt
vi data.txt
:q!
wc -l data.txt
strings data.txt | grep "==="
```

## Resources
[OverTheWire Bandit Level 9](https://overthewire.org/wargames/bandit/bandit10.html) <br />
[Linux Manual Pages](https://man7.org/linux/man-pages/index.html) <br />
[Linux Manual for 'strings'](https://man7.org/linux/man-pages/man1/strings.1.html) <br />
[Linux Manual for 'grep'](https://man7.org/linux/man-pages/man1/grep.1.html) <br />
