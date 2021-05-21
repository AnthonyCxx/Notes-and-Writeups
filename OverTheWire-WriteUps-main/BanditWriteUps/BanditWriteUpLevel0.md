# Header
Level: 0 -> 1 <br />
Server: bandit0@bandit.labs.overthewire.org -p 2220 <br />
Password: bandit0 <br />

## Given
There is a file in your home directory that contains the password for the next level. All you have to do is log onto the server and read the file.

## Explanation

### Background Context
This is an introductory level to get you used to how OverTheWire's Bandit challenges work. In essence, you receive a problem, connect to a server, and then attempt
to solve that problem with the resources (files and tools) provided on that server. **You do not need to have Linux installed on your computer to do these challenges.** 
As long as you can connect to the ssh server, you can do the challenges. <br />
For reference, the servers all run on Devaun Linux

### Connecting to the Bandit SSH Server
Each problem has its own SSH (secure shell host) server, which creates a direct, private connection between you and the server when you access it. To connect to the server,
open any terminal (command prompt, Powershell, Mac Terminal - really anything works) and then type in 'ssh' followed by the address to the server above. When you connect
to the server, it will prompt you for the password. Normally, the password is obtained by completing the previous level, but as this is the first level, they give it to
you: _bandit0_. <br />
Full command: ```ssh bandit0@bandit.labs.overthewire.org -p 2220```

### Solving Your First Challenge
Now that you have logged in, you are ready to start solving. Type in ```ls``` (which is short for list) to list all the files in the folder (directory) you are in.
As you can see, there is a single file name 'readme'. There are a number of ways you could read this file, but we're going to use the _cat_ command to read the file. The 
_cat_ command, which is short for concatenate, displays the contents of a file onto the screen. Just type 'cat' and then the name of the file (_readme_) and you'll have 
solved your first challenge! Copy the password and move on to the next challenge.

## Terminal Execution
```bash
ls
cat readme
```

Resources and References:  <br />
[OverTheWire Bandit Level 0](https://overthewire.org/wargames/bandit/bandit1.html) <br />
[Linuxize - _ls_ Command](https://linuxize.com/post/how-to-list-files-in-linux-using-the-ls-command/)  <br />
[GeeksForGeeks - _cat_ Command](https://www.geeksforgeeks.org/cat-command-in-linux-with-examples/)  <br />
