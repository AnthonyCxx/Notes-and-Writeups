# What is encyphering?
Enciphering is the process of transforming a message such that is is unreadable without some key and/or knowing how it has been transformed. <br />

# Substitution Ciphers

## Rot-N Cipher
A [rot-N cipher](https://medium.com/@jt.redden/rot-n-cipher-4e7039ca721d) (pronounced 'wrote-en' - short for 'rotation') is a substitution cipher where each chacter has been moved over **_N_** positions. <br />
If you were to move each character over 13 positions, it would be a [rot-13 cipher](https://en.wikipedia.org/wiki/ROT13) (the most common rot-N cipher). <br />
You may also see this cipher referred to as a [_Caesarian Shift Cipher_](https://en.wikipedia.org/wiki/Caesar_cipher). <br />

### Tell
Figure out how many character you would need to make the first letter `S` (for `SKY`) or `N` (for `NCL`) and then try those rotations.

### Examples
| Example | Rotation | Translation |
| ------- | -------- | ----------- |
| FXL-TGNX-0751 | 13 | SKY-GTAK-0751 |
| IAO-WJQA-3174 | 10 | SKY-GTAK-3174 |

### Translators
- Script : [Rot-N Decoder](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/cryptography/scripts/rot-n.py) -- this one is better, it tests every combination at once and just gives you the answer
- [Caesarian Shift Decryptor](http://rumkin.com/tools/cipher/caesar.php)

## Atbash Cipher
The [Atbash cipher](https://en.wikipedia.org/wiki/Atbash) encrypts a string by substituting each character with the character on the opposite end of the alphabet. <br />
For example, `A` becomes `Z`, `B` becomes `Y`, and so on. Note that this means that Atbash ciphers and deciphered the same way there are enciphered. <br />

### Tell
Looking at [letter distribution in English](https://en.wikipedia.org/wiki/Letter_frequency), we can clearly see that some letters are far more common than others. 
Because of this, the most common letters should then become those on the opposite end of the alphabet. So, since [the most common English letters are E, A, R, and I](https://www.rd.com/article/common-letters-english-language/), the most common letters after applying the Atbash cipher would be V, Z, I, and R respectively. 

Similarly, you should see very little of the characters on the opposite end of [the least common English letters](https://www.grammarly.com/blog/rarest-letter-in-english/): J, Q, X, and Z. <br /> By this logic, the result of an Atbash cipher should contain very little Q's, J's, C's, and A's. <br />
Essentially, just look for letter frequency. Anything that looks really weird may just be Atbash.

### Examples
| Example | Translation | 
| ------- | ----------- |
| ovhhvhxzkv | lessescape |
| zgyzhs xrksvi | atbash cipher |

### Tranlators
- [Atbash Cipher Decryptor](http://rumkin.com/tools/cipher/atbash.php)

## A1Z26 Cipher
The name itself is the explanation. The A1Z26 cipher is a simple, direct substitution cipher that just replaces letters with their numeric equivalent. A is 1, B is 2, C is 3,
and so on. 

### Tell
A series of numbers where the letters of each word are connected by hyphens.

### Examples
| Example | Translation |
| ------- | ----------- |
| 9 12-5-6-20 9-20 9-14 20-8-5 19-15-21-20-8-19-9-4-5 4-5-1-4 4-18-15-16 9-14 20-8-5 16-1-18-11 | i left it in the southside dead drop in the park |
| 20-8-5 16-1-3-11-1-7-5 9-19 23-9-20-8 20-8-5 2-1-18-20-5-14-4-5-18 | the package is with the bartender |

### Translators
- [Online A1Z26 Encoder/Decoder](https://planetcalc.com/4884/)
- Script : [A1Z26 Decoder](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/cryptography/scripts/A1Z26-decoder.py)

## T9 Cipher
Using a telephone keypad as its base, this cipher replaces each letter in a string with what you would have to enter on an old cellphone keypad to get said letter.

### Tell
A series of **repeated** numbers, where each number is separated by a hyphen and each word is separated by a space.

### Examples
| Example | Translation |
| ------- | ----------- |
| 333-444-66-33 66-33-9-7777 | fine news |
| 2 0-7-44-666-66-33-66-88-6-22-33-777 | a phonenumber |

### Translators
- [Online T9 Encoder/Decoder](https://www.dcode.fr/t9-cipher)
- Script : [T9 Decoder](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/cryptography/scripts/telephone-keypad-decoder.py) -- more convenient, uses NCL format so you don't have to format it yourself

## Sources
[What is Enciphering?](https://www.thefreedictionary.com/cipher) <br />
[Enciphering v.s. Encoding v.s. Encrypting](https://www.quora.com/Is-this-true-Enciphering-encoding-encryption-and-by-the-same-token-deciphering-decoding-decryption)
