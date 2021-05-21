# Header
Level: 10 -> 11 <br />
Server: bandit10@bandit.labs.overthewire.org -p 2220 <br />
Password: truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk <br />

## Given
There is a file in your home directory that contains the password for the next level; however, the password is encoded using Base64.

## Context

### What is Base64?
Base64 is an encoding scheme that transforms (mostly) alphanumeric strings, translating three (3) characters at a time. Because of its small value table,
Base64 is quite limited; regardless, it is sufficient for simple encoding. The Base64 table includes letters, numbers, and the symbols '+' and '/'; you will 
also see '=' for padding, but only for last or last two characters when needed to make the amount of characters a multiple of three. A key identifier that a 
string could be encoded with Base64 is that the amount of characters is a multiple of three — this is especially the likely if the last or last two characters are '='. 
In standard practice, you will only see strings encoded with Base64 with characters from the Base64 table; however, in competitions such as CTFs, you may 
see impure strings that are encoded in Base64. To decode these strings, you will need to utilize the -i option to ignore garbage (irrelevant characters), such as symbols.

### Additional Notes - Base64 vs Base58
There is a version of Base64 called Base58 that is commonly used in blockchain, specifically Bitcoin. Base58 removes a total of 6 characters from the Base64 set,
those being 0, O, l, I, /, and +. This makes Base58 more practical as it excludes homoglyphs and is purely alphanumeric.

## Explanation

### Decoding Base64 Encoded Text
First, find the data file and look at the contents with cat. As you can see, not only is the string all letters and numbers, but the last two characters are both '=',
meaning that it is extremely likely that this string has been encoded with Base64. Just to be sure, check how many characters the file has and make sure
it is a multiple of three. Remember that a character is only one (1) byte, so the amount of bytes is always equal to the amount of characters. You will have to 
use the base64 command to decode the file. Refer to the manual if you do not know how to do so. After you have decoded the file, copy the password and proceed to level 11.

## Terminal Execution
```bash
ls
cat data.txt
wc -m data.txt
base64 -d data.txt
```

## Resources
[OverTheWire Bandit Level 10](https://overthewire.org/wargames/bandit/bandit11.html) <br />
[Linux Manual Pages](https://man7.org/linux/man-pages/index.html) <br />
[Wikipedia on Base64](https://en.wikipedia.org/wiki/Base64) <br />
[What is Base64? (Warning: poor audio)](https://www.youtube.com/watch?v=8qkxeZmKmOY1) <br />
[Base64 Encoding and Decoding with Bash](https://www.youtube.com/watch?v=TzG_iflIiig) <br />
[Applications of Base64 in Web Design](https://www.youtube.com/watch?v=l44-FOuJXYw) <br />
[Base64 vs Base58](https://bitcoin.stackexchange.com/questions/70942/why-is-bitcoin-address-encoded-in-base58) <br />
[What are Homoglyphs?](https://en.wikipedia.org/wiki/Homoglyph) <br />
