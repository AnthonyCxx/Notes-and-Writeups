# Header
Level: 3 -> 4 <br />
Server: bandit3@bandit.labs.overthewire.org -p 2220 <br />
Password: UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK <br />

## Given
There is a hidden file in the directory 'inhere'.

## Explanation

### Hidden Files
Some files and directories in Linux have the 'hidden' attribute, which is denoted by the fact that they start with a period. As they are hidden, these files do not show 
up when using the standard 'ls' command. Though it may seem unintuitive, having hidden files is helpful it ensures that important files are not deleted. As an added bonus, it declutters the command line and GUI interfaces, allowing for easier navigation. 

### Listing Hidden Files
To see hidden files, you will have to use the '-a' option after the 'ls' command to indicate that you would like to see all files in the directory, including hidden files. The '-a' is an example of an option (aka called a flag or a switch), which modifies the execution of a command. Options are incredibly useful as they allow for infinitely many variations of a single idea. If you choose to include multiple options, know that they can be included in any order. The only positional requirement for an option is that it must come after the command. The command should always be the first thing you write. For example, take the command that you used to connect to the Bandit 3 server:  
```ssh bandit3@bandit.labs.overthewire.org -p 2220```. If you were to write the '-p 2220' in front of the address, bandit3@bandit.labs.overthewire.org, the command would have executed just the same.

## Terminal Execution
```bash
cd inhere
ls -a
cat .hidden
```

## Resources
[OverTheWire Bandit Level 3](https://overthewire.org/wargames/bandit/bandit4.html) <br />
[Linux - Why are Some Files Hidden?](https://unix.stackexchange.com/questions/147859/why-are-some-files-and-folders-hidden) <br />
[Linux - Show Hidden Files (Terminal and GUI)](https://www.tecmint.com/hide-files-and-directories-in-linux/#:~:text=To%20view%20hidden%20files%2C%20run,al%20flag%20for%20long%20listing.&text=From%20a%20GUI%20file%20manager,view%20hidden%20files%20or%20directories) <br />
[Linux - What is an Option?](http://www.linfo.org/option.html#:~:text=An%20option%2C%20also%20referred%20to,command%20in%20some%20predetermined%20way.&text=Options%20are%20distinct%20from%20arguments,names%20of%20files%20and%20directories.) <br />
