# Languages and Codes
This is a reference of languages/codes used in previous NCL challenges:

# Morse Code
Morse code is a communication system consisting of long beeps (dashes) and short beeps (dots). <br />
Morse Code : [Manual Reference Table](https://www.electronics-notes.com/articles/ham_radio/morse_code/characters-table-chart.php)

## Examples
| Example | Translation | 
| ------- | ----------- |
|  ... --- ... | SOS |
| -- --- .-. ... .  -.-. --- -.. . | MORSECODE |
| -... --- -..- | BOX |

## Translators
- Script: [Morse Code Decoder](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/cryptography/scripts/morse-code-decoder.py)
- [Encode/decode text](https://www.boxentriq.com/code-breaking/morse-code)
- [Decode audio](https://morsecode.world/international/decoder/audio-decoder-adaptive.html)

# Military Alphabets (NATO and Western Union)
The NATO and Western Union codes allowed radiotelegraph operators to communicate more securely by replacing each letter with a whole word. 
NATO tends to be a tad dated in terms of its choice of words, which gives it away. The tell of Western Union is all the names of people and cities that it uses. 
You can read more about the history of the codes [here](https://www.nato.int/cps/fr/natohq/declassified_136216.htm#R583639-516307ef).

### Examples
| Example | Translation |
| ------- | ----------- |
| union-new_york-thomas-ida-denver-young sugar-ocean-chicago-king-sugar (Western Union) | UNTIDY SOCKS |
| lima-alfa-november-delta-lima-uniform-bravo-bravo-echo-romeo-sierra (NATO) | LANDLUBBERS |


### Translators
- [NATO/Western Union Alphabet to ASCII](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/cryptography/scripts/military-alphabet-decoder.py) - formatted to NCL specifications

# Unicode Braille (Grade 1, 2, and 3)
[Braille has different grades](http://www.acb.org/tennessee/braille.html) (1, 2, and 3) based on its complexity. <br />
Level 1 is standard Braille; level 2 contains some contractions to allow for shorthands (ex. I will -> I'll). <br />
Level 3 includes more shorthands, but is not standardized and so is not used in publications. <br />
When translating, use grade 2 as it is a superset of grade 1.

## Examples 
| Example | Translation |
| ------- | ----------- | 
| ⠠⠺⠑ ⠥⠏⠙⠁⠞⠑⠙ ⠞⠓⠑ ⠏⠁⠎⠎⠺⠕⠗⠙ ⠕⠝ ⠍⠕⠃⠊⠇⠑ ⠁⠉⠉⠑⠎⠎ ⠏⠕⠊⠝⠞ | ,we updated the password on mobile access point |
| ⠉⠕⠝⠞⠗⠁⠉⠞⠊⠕⠝⠎ ⠙⠕⠝⠄⠞ ⠝⠕⠞ ⠺⠕⠗⠅ ⠊⠝ ⠠⠃⠗⠁⠊⠇⠇⠑ | contractions don't not work in Braille |
| ⠞⠓⠊⠎ ⠊⠎ ⠃⠗⠁⠊⠇⠇⠑ | this is braille |

## Translators
- [ASCII to Braille](https://qaz.wtf/u/braille.cgi?text=this+is+braille)
- [Braille to ASCII](https://www.brailletranslator.org/) -- this one can take a while, be patient.
- [Manual Translation Reference](https://en.wikipedia.org/wiki/Braille_Patterns)


# Futurama Alien Language
No, I'm not joking. This actually showed up on an NCL challenge.

## Examples
| Language | Example | Translation |
| -------- | ------- | ----------- |
| Alien Language 1 | ![image](https://user-images.githubusercontent.com/70488531/117673708-03edb000-b179-11eb-94bc-68aa1490a18c.png) | alien language |
| Alien Language 2 | ![image](https://user-images.githubusercontent.com/70488531/117673811-1e278e00-b179-11eb-9d76-b43536d3fc52.png) | alien language |

## Translators
- [Futurama Translators and Reference](http://www.gotfuturama.com/Interactive/AlienCodec/)
