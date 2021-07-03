# Formatting Input and Output with Format Specifiers in C
The [_printf()_](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) and [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm)
functions are used to read input/write output that is formatted using [format specifiers](https://tutorialsbookmarks.com/format-specifiers-in-c/). The format specifiers
allow you to [format a string](https://www.cprogramming.com/tutorial/printf-format-strings.html), control the amount of decimal places in a float, change the [radix](https://en.wikipedia.org/wiki/Radix) of a number (allowing for [octal](https://www.tutorialspoint.com/octal-number-system)/[hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) representation), and even represent a number in [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation). Format specifiers start with a _%_ sign and are alphanumeric (with the exception of _%%_). Modifiers for format
specifiers should be in the order `%[parameter][flags][width][.precision][length]<type>` (only the % followed by the datatype is necessary.

## Type Specifiers
The type specifier specifies the [datatype](https://www.geeksforgeeks.org/data-types-in-c/) of the variable.

| Specifier | Datatype |
| -------- | --------- |
| d  | ([base 10](https://www.thoughtco.com/definition-of-base-10-2312365)) signed int |
| i | signed int (can detect octal (base 8) & hexadecimal (base 16) with [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm) |
| u | unsigned int |
| o | converts an unsigned int to [octal](https://www.tutorialspoint.com/octal-number-system) |
| x | converts an unsigned int to [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (lowercase a-f) |
| X | converts an unsigned int to [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (uppercase A-F) |
| f | float (uses lowercase for [_inf_, _infinity_, and _nan_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
| F | float (uses uppercase for [_INF_, _INFINITY_, and _NAN_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
| a | [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) float (lowercase xc and fep) |
| A | [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) float (uppercase XC and FEP) |
| e | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation) (lowercase 'e') |
| e | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation)  (uppercase 'E') |
| g | returns the shorter of %f and %e |
| G | returns the shorter of %f and %E |
| c | char | 
| s | char string literal (e.g. "Hello!") | 
| p | memory/pointer address | 
| n | none, prints nothing; used to [return the amount of character read until %n is read/written](https://www.geeksforgeeks.org/n-in-scanf-in-c-with-example/) |
| % | none, prints a percent sign (the '%' sign cannot be escaped with a backslash) |

## Length Specifiers
The length specifier indicates the size of the datatype. This list is not comprehensive, see [here](https://en.wikipedia.org/wiki/Printf_format_string#Length_field).

| Specifier | Size |
| -------- | ----- |
| h | short |
| l | long |
| ll | long long |
| L | long (long double only) |
| z | [size_t](https://www.geeksforgeeks.org/size_t-data-type-c-language/) |

## Width Specifier
| Specifier | Result |
| --------- | ------ |
| (integer) | specifies the minimum amount of character that need to be printed (prints spaces if needed to match the amount) |

## Precision Specifier
| Specifier | Result |
| --------- | ------ |
| .(integer) | specifies the amount of decimal places to show for floating-point numbers |

## Flag Specifiers
Flags alter the standard formatting specifications.

| Flag | Action | 
| ---- | ------ |
| - | [left-justifies](https://en.wikipedia.org/wiki/Typographic_alignment#Justified) the text (right is the default) |
| + | puts a '+' in front of positive numbers |
| (space) | puts a space in front of positive numbers to keep alignment with negative numbers |
| 0 | [zero-pads](https://stackoverflow.com/questions/153890/printing-leading-0s-in-c) the number to fit the specified width |
| # | prints a radix indicator (0, 0x, 0X) for octal and hex numbers, and keeps trailing zeros for floating-point numbers (decimal point) |

## Examples
Replace anything in curly braces, _{ }_, with the appropriate item.

| Example | Result |
| ------- | ------ |
| %03d | prints a zero-padded integer with a width of three (001, 012, 100) |
| %+.2f | prints a float with 2 decimal places and a prefixed '+' or '-' |
|  |  |

Use [https://en.wikipedia.org/wiki/Printf_format_string](https://en.wikipedia.org/wiki/Printf_format_string)


## Sources
This was so much research. Barely any of the websites were comprehensive. Here are the websites I didn't link in the text:
- [_C PLus PLus reference: cstdio: printf()_](https://www.cplusplus.com/reference/cstdio/printf/)
- [_TutorialsPoint: Format Specifiers in C_](https://www.tutorialspoint.com/format-specifiers-in-c) 
- [_TutorialsBookmarks: All 19 C Format Specifiers_](https://tutorialsbookmarks.com/format-specifiers-in-c/) 
- [_University of Illinois Chicago: Summary of C Datatypes_](https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/DataTypesSummary.pdf) 
- [_Linux Man. Pages: Printf() Format Specifiers_](https://linux.die.net/man/3/printf) 
- [_Laboratoire d'informatique de l'École Polytechnique: printf format identifiers_](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)
- [_Wikipedia: Printf() String Formatting_](https://en.wikipedia.org/wiki/Printf_format_string) 
- [_StackOverflow: %f vs %g and %G in C_](https://stackoverflow.com/questions/5913102/what-is-the-difference-between-g-and-f-in-c) 
- [_StackOverflow: %f vs %F in C_](https://stackoverflow.com/questions/51908513/difference-between-f-and-f-in-printf/51908594)
- [_GeeksforGeeks: %d vs %i in C_](https://www.geeksforgeeks.org/difference-d-format-specifier-c-language/)
- [_GeeksforGeeks: %n in C_](https://www.geeksforgeeks.org/n-in-scanf-in-c-with-example/) 
- [_armKIEL: Hexadecimal_ floating-point numbers (%a, %A) in C99](https://www.keil.com/support/man/docs/armcc/armcc_chr1359124238525.htm)
