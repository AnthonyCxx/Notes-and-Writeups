## What is encoding?
"Encoding is the process of putting a sequence of characters such as letters, numbers and other special characters into a specialized format for efficient transmission. <br />

Decoding is the process of converting an encoded format back into the original sequence of characters. It is completely different from Encryption which we usually misinterpret. <br />

Encoding and decoding are used in data communications and storage. Encoding should NOT be used for transporting sensitive information." <br />
\- an excerpt from [TutorialsPoint](https://www.tutorialspoint.com/security_testing/encoding_and_decoding.htm#:~:text=Encoding%20is%20the%20process%20of,the%20original%20sequence%20of%20characters.)

**Note: be aware that there are variations of nearly every encoding scheme. If you're not getting results, look into similar schemes.** <br />
For example, if you are not getting results from something that looks like base64, try base58 or base85.

## Binary
Binary is a base-2 number system. Binary (the number system) is distinct from binary (machine) code; however, the binary number system does underlie binary code.
Binary is used for computer systems as it is a reliable (less error-prone) way of evaluating the state of an electrical signal.

### Examples
| Example | Translation | 
| ------- | ----------- |
| 01110011 01101111 01101101 01100101 00100000 01110100 01100101 01111000 01110100 | some text |
| 01110100 01100101 01101100 01100101 01110000 01101000 01101111 01101110 01100101 | telephone |
| 01110000 01100101 01101110 01100011 01101001 01101100 | pencil |

### Translators
- [Binary to ASCII](https://www.rapidtables.com/convert/number/binary-to-ascii.html)
- [ASCII to Binary](https://www.rapidtables.com/convert/number/ascii-to-binary.html)
- [Binary to Hexademcimal](https://www.rapidtables.com/convert/number/binary-to-hex.html)
- [Hexadecmimal to Binary](https://www.rapidtables.com/convert/number/hex-to-binary.html)
- [Binary to Decimal](https://www.rapidtables.com/convert/number/binary-to-decimal.html)
- [Decimal to Binary](https://www.rapidtables.com/convert/number/decimal-to-binary.html)


## Octal
Octal is a base-8 number system consisting of the numbers 0-7. It only need 3 bits to represent a number, so octal is often used when the amount of bits is evenly divisible by
3. The octal system uses less digits than both decimal and hex, and so is both safer and more efficient. Nevertheless, it is less popular.

### Examples
| Example | Translation | 
| ------- | ----------- |
| 064 103 061 063 166 063 062 120 064 063 063 167 060 062 144 015 012 | 4C13v32P433w02d |
| 171 145 154 154 157 167 040 151 163 040 141 156 040 165 147 154 171 040 143 157 154 157 162 | yellow is an ugly color |
| 167 145 141 153 040 160 141 163 163 167 157 162 144 | weak password |

### Translators
- [Octal to ASCII](http://www.unit-conversion.info/texttools/octal/)
- [ASCII to Octal](http://www.unit-conversion.info/texttools/octal/)
- [Octal to Hex](https://ncalculators.com/digital-computation/hex-octal-converter.htm)
- [Hex to Octal](https://ncalculators.com/digital-computation/hex-octal-converter.htm)
- [Octal to Binary](https://www.w3resource.com/convert/number/octal-to-binary.php)
- [Binary to Octal](https://www.w3resource.com/convert/number/binary-to-octal.php)
- [Octal to Decimal](https://www.rapidtables.com/convert/number/octal-to-decimal.html)
- [Decimal to Octal](https://www.rapidtables.com/convert/number/decimal-to-octal.html)


## Hexadecimal
Hexadecimal is a base-16 number system consisting of the numbers 0-9 and character A-F (case is irrelevant). Characters were used for the final 6 members because they are distrinct from numbers. Hexadecimal is often used as a compact method of representing binary data where each character represents 4 bits (this way, every 2 hex digits is one byte). <br />

### Examples
| Example | Translation | 
| ------- | ----------- |
| 506974746d616e20697320746865 | Pittman is the |
| 656d7065726f72206f66 | emperor of |
| 656d7065726f72206f66 | all mankind |


### Translators
- [Hex to ASCII](https://www.rapidtables.com/convert/number/hex-to-ascii.html)
- [ASCII to Hex](https://www.rapidtables.com/convert/number/ascii-to-hex.html)
- [Hex to Binary](https://www.rapidtables.com/convert/number/hex-to-binary.html)
- [Binary to Hex](https://www.rapidtables.com/convert/number/binary-to-hex.html)
- [Hex to Decimal](https://www.rapidtables.com/convert/number/hex-to-decimal.html)
- [Decimal to Hex](https://www.rapidtables.com/convert/number/decimal-to-hex.html)

## Base64
Base64 is an encoding scheme that transforms (mostly) alphanumeric strings, translating three (3) characters at a time. Because of its small value table, Base64 is quite limited; regardless, it is sufficient for simple encoding. The Base64 table includes letters, numbers, and the symbols '+' and '/'; you will also see '=' for padding, but only for last or last two characters when needed to make the amount of characters a multiple of three.   <br />

A key identifier that a string could be encoded with Base64 is that the amount of characters is a multiple of three — this is especially the likely if the last or last two characters are '='. <br />

In standard practice, you will only see strings encoded with Base64 with characters from the Base64 table; however, in competitions such as CTFs, you may see impure strings that are encoded in Base64. To decode these strings, you will need to utilize the `-i` flag to ignore garbage (irrelevant characters), such as symbols.

### Examples
| Example | Translation | 
| ------- | ----------- |
| YSByYW5kb20gc2VyaWVzIG9mIHdvcmRz | a random series of words |
| c3Vuc2V0OTg3Ng== | sunset9876 |
| MzVyaXZlcnR5cGU1MQ== | 35rivertype51 |

### Translators
- [Base64 to ASCII](https://www.base64decode.org/)
- [ASCII to Base64](https://www.base64encode.org/)


## Sources
### Binary
### Octal
[TutorialsPoint](https://www.tutorialspoint.com/octal-number-system)
### Hexadecimal
### Base64
[Wikipedia: Base64](https://en.wikipedia.org/wiki/Base64) <br />
[Applications of Base64 in Web Design](https://www.youtube.com/watch?v=l44-FOuJXYw) <br />
[Video: What is Base64?](https://www.youtube.com/watch?v=8qkxeZmKmOY1) <br />
[Video: Base64 Encoding/Decoding with Bash](https://www.youtube.com/watch?v=TzG_iflIiig) <br />
