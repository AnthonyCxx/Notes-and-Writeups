Note: This is unfinished, but not on my list of priorities. I will return to it eventually (5/16/21)

# A Guide to Sed, a Stream Editor
Sed is a text manipulation tool; however, unlike AWK, it is not a programming language. Like with AWK, the body of the program is in single quotes.

## Sed GNU Extention
| Character | Function | 
| --------- | -------- |
| `\L` | turn the replacement to lowercase until a _\U_ or _\E_ is found |
| `\l` | turn the next character to lowercase |
| `\U` | turn the replacement to uppercase until a _\L_ or _\E_ is found |
| `\u` | turn the next character to uppercase |
| `\E` | stop case conversion started by _\L_ or _\U_ |


# Replacing/Substituting Text

## Replace _N_ or All Instances
Replace text using the format `sed 's/old_pattern/new_pattern/g'`. This old pattern can be a regular expression, but the new one must be text. <br />
Putting a number _n_ after the last `/` will only replace the *n*th instance. Putting a `g` (for global) replaces all instances.
```bash
# Output <file>, but replace all instances of 'cat' with 'dog'.
cat <file> | sed 's/cat/dog/g' 
```
> The 's' at the beginning stands for 'substitute'.

## Replace Only the Last Match per Line
```bash
# Patterns should replace <pattern>
sed 's/\(.*\)<old_pattern>/\1<new_pattern>/'
```
