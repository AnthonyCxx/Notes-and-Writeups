# Header
Level: 12 -> 13 <br />
Server: bandit12@bandit.labs.overthewire.org -p 2220 <br />
Password: 5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu <br />
 
## Given
In your home directory, there is a text file that contains the result of a hexdump of a file that was repeatedly compressed. <br />
Create a directory in /tmp, copy data.txt over to it, and get to work.

## Context
This challenge is going to make you _very_ familiar with a few things - checking file types, renaming files, and unzipping/decompressing them. However, 
the first part of this challenge is dealing with a hexdump. 

### Hexdumps
A hexdump (or hex dump) is a hexadecimal representation of raw binary data. Since the data is unchanged during the dumping process, getting back to the
original form is just a matter of understanding and then reversing the processes the file underwent. As you will see in this challenge, you can go from a 
hexdump of a file that has been compressed over eight times all the way back to the original text.

### File Compression in Linux
Linux has a great variety of free tools to help users with a wide array of tasks, each of which is best suited to a more specific task. Here, you will
see a variety of Linux compressing softwares in use (tar, zip, bzip2) and use them sequentially to decompress a text file that has been compressed many times over.

### /tmp Directory
The /tmp directory is a root directory that stores files that are not meant to be permenant. Usually, the files contained in this folder are being used by running applications
to store data. Because of this, the contents of /tmp and /var/tmp are typically necessary to integrity of the running processes and can cause application crashes (and in
some cases system crashes) when deleted prematurely. Here, you are using the /tmp directory as your working directory because the system automatically clears the folder
between reboots. Additionally, programs such as _tmpwatch_ will automatically delete the files after the files have not been accessed for some days (10 days by default).

## Explanation

### The Hexdump

#### Understanding the Hexdump
Start by creating your working directory in /tmp. Name it whatever you want, I'll name mine /tmp/Bandit12Exercise. Then, copy the data.txt over to the new directory
and make it your working directory. Now, take a look at the data.txt file and try to understand the hexdump. The left-most column indicates the address of the bytes,
the middle column is the bytes in hex and in rows of 8 two-byte 'words', and the final column is an ASCII representation of the bytes. If the character cannot be printed
do to being outside the range of representatble ASCII characters (20 to 7E, or space to ~), then the program will simply print a single period to keep alignment.

#### Reversing the Hexdump
To reverse the hexdump, use the _xxd_ command, which will read the hex bytes and translate the hex back into its original binary form. Using the _-r_ option, which 
stands for 'reverse', will do this easily. Use commandline I/O redirection to put the output into a new file, which I named 'tempfile'. Normally I would put '.txt' or
some other extention, but you really shouldn't as you don't know the file type yet.

### Decompressing the Reversed Hexdump
This next part is not hard, but it is tedious. As mentioned earlier, the file has been compressed a total of 8 times by different file-compressing programs.
All you have to do is use the _file_ command to check the file type, use _mv_ to rename the file so it ends with the extention that said program takes, and then
decompress the file with said program. Below is a chart of the programs you need, their file extentions, and how to unzip a file with them.

Something worth noting is that decompressing a .tar archive doesn't get rid of the initial archive, so you'll have to do that manually. You may want to save them in
a subdirectory as checkpoints though.

| Program | File Extention | Unzip Command |
| ------- | -------------- | ------------- |
| gzip    | .gz            | gzip -d somefile.gz |
| tar     | .tar           | tar -xf  somefile.tar |
| bzip2   | .bz2           | bzip2 -d somefile.bz2 |

## Terminal Execution
```bash 
   #Setting up
   mkdir /tmp/Bandit12Exercise              #Make the new directory
   cp data.txt /tmp/Bandit12Exercise        #Copy the data file to it
   cd /tmp/Bandit12Exercise                 #Move to the new directory
   
   #Reversing the hexdump
   cat data.txt                             #Peek at the hexdump in the .txt file
   xxd -r data.txt > tempfile               #Reverse the hexdump with xxd, redirecting the output to a new file 'tempfile'

   #Decompressing the file
   file                                     #Determine the file type 
   mv tempfile tempfile.gz                  #Rename the file
   gzip -d tempfile.gz                      #Decompress the file
   
   file                                     #Determine the file type 
   mv tempfile tempfile.bz2                 #Rename the file
   bzip2 -d tempfile.bz2                    #Decompress the file
   
   file tempfile                            #Determine the file type 
   mv tempfile tempfile.gz                  #Rename the file
   gzip -d tempfile.gz                      #Decompress the file
   
   file tempfile                            #Determine the file type 
   mv tempfile tempfile.tar                 #Rename the file
   tar -xf tempfile.tar                     #Decompress the file
   
   file tempfile                            #Determine the file type 
   mv tempfile tempfile.tar                 #Rename the file
   tar -xf tempfile.tar                     #Decompress the file
   rm tempfile.tar                          #Dispose of old file
   
   file tempfile                            #Determine the file type
   mv tempfile tempfile.tar                 #Rename the file
   tar -xf tempfile.tar                     #Decompress the file
   rm tempfile.tar                          #Dispose of old file
   
   file data5.bin
   mv data5.bin tempfile.tar                ...
   tar -xf tempfile.tar
   rm tempfile.tar 
    
   file data6.bin                           ...
   mv data6.bin tempfile.bz2
   bzip2 -d tempfile.bz2 
   
   file tempfile                            ...
   mv tempfile tempfile.tar 
   tar -xf tempfile.tar
   rm tempfile.tar
   
   file data8.bin                           ...
   mv data8.bin tempfile.gz               
   gzip -d tempfile.gz                     
   
   #Print the original ASCII file 
   cat tempfile                           
```

## Resources and References
[Linux Manual - _file_ Command](https://man7.org/linux/man-pages/man1/file.1.html) <br />
[Linux Manual - _mv_ Command](https://man7.org/linux/man-pages/man1/mv.1.html) <br />
[Linux Manual - _tar_ Command](https://man7.org/linux/man-pages/man1/tar.1.html) <br />

[TutorialsPoint - Unix _xxd_ Command](https://www.tutorialspoint.com/unix_commands/xxd.htm) <br />
[Linuxize - _gzip_ Command](https://linuxize.com/post/gzip-command-in-linux/) <br />
[TecMint - How to Decompress a .bz2 File](https://www.tecmint.com/linux-compress-decompress-bz2-files-using-bzip2/) <br />

[The Linux Documentation Project - What is /tmp?](https://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/tmp.html) <br />
[Foss Linux - Everything You Need to Know about /tmp](https://www.fosslinux.com/41739/linux-tmp-directory-everything-you-need-to-know.htm) <br />
[Quora - What is a Hexdump and How Can I use it?](https://www.quora.com/What-is-hex-dump-and-how-can-I-use-it) <br />
[OpenSource - How Hexdump Works](https://opensource.com/article/19/8/dig-binary-files-hexdump) <br />
[Wikipedia - Hex Dumps](https://en.wikipedia.org/wiki/Hex_dump) <br />
