[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis/AWK): AWK main folder

# AWK Pre-defined Variables
| Variable | Full Name | Stores | 
| -------- | --------- | -------- | 
| `$N` | N/A |  the *N*th field |
| `NF` | Number of Fields | the amount of fields on the current line | 
| `NR` | Number of Records | the amount of lines |
| `FS` | Field Separator | determines what separates fields | 
| `OFS` | Output Field Separator | output field separator |
| `RS` | Record Separator | determines what constitutes a newline |
| `ORS` | Output Record Separator | determine what constitutes a newline for output |
| `length` | N/A | the length of the current line |
| `FILENAME` | N/A | the name of the current file |
| `CONVFMT` | Conversion Format | the amount of places in a number (pre- and post-decimal point) |
| `OFMT` | Output Format | controls the conversion format for the output |
| `IGNORECASE` | N/A | when set to 1, the program ignores case |

## Printing Specific Fields: $N
```AWK
#Prints fields 1 and 3
awk '{print $1, $3}' <file>
```
> AWK uses reserved variables of the format `$N` where _N_ is replaced by an integer to print the *N*th field. <br />
These fields are not zero-indexed; `$0` prints the entire line. You can alter these fields directly through assignment. To get rid of a row, do `$N=""`.

## Counting the Amount of Fields: NF
```AWK
#Prints lines with more than three fields
awk '{if (NF > 3) {print}}' <file>
```
> When used without parameters, `{print}` prints the entire line.

## Counting the Amount of Lines: NR
```AWK
#Prints the amount of lines read so far, updating each time it reads a line
awk '{print NR}' <file>
```
> To print the total amount of lines once, do `awk 'END {print NR}' <file>`.

## Defining the Field Separator: FS
```AWK
#Prints the first and second field as determined by the separating character, a colon
awk 'BEGIN {FS = ":"} {print $1, $2}' <file>
```
> Always assign `FS` at the beginning. <br />
> Use a [character class](https://www.regular-expressions.info/charclass.html), _\[ \]_, to use multiple field separators. Ex. `awk 'BEGIN {FS="[/:]"} {print}'`. This way, _FS_ separates with `:` and `/`.

## Altering Output Format: OFS
```AWK
#Prints fields 1, 2, and 3 in a comma-separated list
awk 'BEGIN {OFS = ", "} {print $1, $2, $3}' <file>
```
> Always assign `OFS` at the beginning.

## Choosing Newline Value: RS
```AWK
#Separate lines by period, not newline character
awk 'BEGIN {RS = "."} {print}' <file>
```
> Always assign `RS` at the beginning.


## Choosing Newline Value for Output: ORS
```AWK
# When printing, separate lines by period, not newline character
awk 'BEGIN {ORS = "."} {print}' <file>
```
> Always assign `ORS` at the beginning.

## Altering Number Precision with CONVFMT
The _CONVFMT_ format equals the total amount of digits that will be shown when displaying a number **_including_** numbers before the decimal point.
```AWK
# Default CONVFMT is %.6g , which shows 6 digits. This snippet sets it to show 4 digits
awk 'BEGIN {CONVFMT="%.4g"} {print}' <file>
```
> Always asign `CONVFMT` at the beginning.

## Ignoring Case: IGNORECASE
```AWK
# Searches for "pattern", but is case insensitive
awk 'BEGIN {IGNORECASE=1} /pattern/ {print}' <file>
```
> Always assign `IGNORECASE` at the beginning. By default, AWK is case-sensitive. <br />
> Set _IGNORECASE_ to 1 to make the program case insensitive.
