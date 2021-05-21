# Header
Level: 11 -> 12 <br />
Server:  bandit11@bandit.labs.overthewire.org -p 2220 <br />
Password: IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR <br />

## Given
There is a password in your home directory containing the password for the next level; however, the password has been enciphered using rot13 (rotation 13) enciphering for all upper and lowercase letters. There are no numbers

## Context

### What is rot13?
Rot13 is a commonly known substitution cipher, and is a type of Caesar cipher. The cipher is incredibly simple - to encipher plaintext using Rot13, all you have to do is substitute each letter with the letter 13 places down from said letter in the alphabet. This makes Rot13 a fixed-key substitution cipher, and, since it is very well-known, also makes it a remarkably weak enciphering method. In fact, Rot13 is considered so weak that most people use it as the go-to example of how not to write an enciphering method. If you are interested in substitution ciphers, you may also be interested in transposition ciphers.
	
#### Something Worth Noting
Deciphering Rot13 text is the exact same an enciphering it, as each letter is translated 13 positions and there are only 26 letters in the alphabet.

## Explanation

### The _tr_ Command
As mentioned above, all you will have to do to decipher the key is translate all the characters over 13 positions. Use the 'tr' command for this. The tr command, which is short for 'translate', transforms characters from standard input (in this case, the output from cat). 

### Translation Sets
The first thing to know about the tr command is that it takes two sets: one to translate from, and one to translate to. Another thing to note is that 'tr' does not use brackets for the ranges, as they are treated literally. You can prevent them from being read literally with the '-d' option. First, cat the file into the tr command using a pipe. Then, you will need to create your two sets. The first set will be the standard alphabet, and the second will be the alphabet rotated (transposed) thirteen places over. The first key will be written as ```'a-zA-Z'```, which equals ```[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ]```. The second, ```'n-za-mN-ZA-N'``` will be short for ```[nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM]```, which, again, is the alphabet shifted thirteen places over. 

### Terminal Interpretation of Ranges
Something worth noting is that the range character only affects one character to both the left and right of it - this is why we can do 'n-za-m' without any problems, as it is really the ranges 'n-z' and 'a-m' respectively. 

### External Resources and their Use
Now is probably a little late to tell you that there is a rot13 Linux command as well as online decipherers, but you should learn to do things manually since it forces you to take your time and grapple with the concept; moreover, you may not have access to certain tools, such as rot13, on a foreign system. Knowing how to get the job done with native tools ensures your ability to be able to work in any environment.

## Terminal Execution
``` bash
ls cat 
data.txt
cat data.txt | tr 'a-zA-Z' 'n-za-mN-ZA-N'
```


## Resources
[Practical Cryptography: What is Rot13?](http://practicalcryptography.com/ciphers/rot13-cipher/) <br />
[En/Deciphering Rot13 via Command Line](https://stackoverflow.com/questions/5442436/using-rot13-and-tr-command-for-having-an-encrypted-email-address) <br />
[How Does 'a-zA-z' 'n-za-mN-ZA-M' Work?](https://unix.stackexchange.com/questions/19772/how-does-tr-a-z-n-za-m-work) <br />
[Online Deciphering Tool (CyberChef)](https://gchq.github.io/CyberChef/) <br />
