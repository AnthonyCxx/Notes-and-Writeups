# Header
Level: 6 -> 7 <br />
Server: bandit6@bandit.labs.overthewire.org -p 2220 <br />
Password: DXjZPULLxYr17uwoI01bNLQbtFemEgo7 <br />

## Given
There is a file that contains the password for the next level stored somewhere on the server. This file is owned by user bandit7 under group bandit6 and is 33 bytes in size.

## Explanation
This level requires you to understand the both the Linux file hierarchy and the find command. The given is that the file is stored somewhere on the server, so we will start our search at the root directory ('/'). We can narrow the results of our search with a few options, specifically the ones that search by filetype, owner, group, and file size. '-type' searches by file type; since we are looking for a regular file, we will use '-type f'. Then, we want to search by user, using the '-user' option. Add the user's name, bandit7, after the -user option. In the same way, add '-group bandit6' to the command. Finally, you have to search by file size. You will use the '-size' option for this. Add '-size 33c' to the end of the command and hit enter (c stands for bytes; b is already reserved by 512-byte blocks). Astoundingly, many files match the specified criteria. Most you do not have access to, denoted by the ": Permission denied" tag on the end of the file name. Search for the file "bandit7.password", copy the path, and then cat the contents.

## Terminal Execution
```bash
ls
find / -type f -user bandit7 -group bandit6 -size 33c
cat /var/lib/dpkg/info/bandit7.password
```

## Resources
[OverTheWire Bandit Level 6](https://overthewire.org/wargames/bandit/bandit7.html) <br />
[Linux Manual Page for 'find'](https://man7.org/linux/man-pages/man1/find.1.html) <br />
[35 Practical Examples of the 'find' Command (reference #23, #24, & #32)](https://www.tecmint.com/35-practical-examples-of-linux-find-command/) <br />
[Intro. to the Linux File System](https://www.youtube.com/watch?v=HIXzJ3Rz9po) <br />
[The Linux File System](https://opensource.com/life/16/10/introduction-linux-filesystems) <br />
