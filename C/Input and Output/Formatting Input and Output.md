# Input/Output with Format Specifiers and Escape Sequences in C
I/O functions like [_printf()_](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) and [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm)
functions are used to read input/write output that is formatted using [format specifiers](https://tutorialsbookmarks.com/format-specifiers-in-c/). The format specifiers
allow you to [format a string](https://www.cprogramming.com/tutorial/printf-format-strings.html), control the amount of decimal places in a float, change the [radix](https://en.wikipedia.org/wiki/Radix) of a number (allowing for [octal](https://www.tutorialspoint.com/octal-number-system)/[hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) representation), and even represent a number in [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation). Format specifiers start with a _%_ sign and are alphanumeric (with the exception of _%%_). Modifiers for format
specifiers should be in the order <br /> `%[parameter][flags][width][.precision][length]<type>` (only the % followed by the datatype is necessary).

All sources are linked in the text or listed at the bottom.

## Examples
| Example | Result |
| ------- | ------ |
| %d | print a signed integer |
| %ld | print a long integer |
| %03d | prints a zero-padded integer with a width of three (001, 012, 100) |
| %+.2f | prints a float with 2 decimal places and a prefixed '+' or '-' |
| %#x | print a hexadecimal number with the '0x' prefix |
| %zu | prints a size_t integer | 


## Type Specifiers
The type specifier specifies the [datatype](https://www.geeksforgeeks.org/data-types-in-c/) of the variable.

| Specifier | Datatype |
| -------- | --------- |
| d  | ([base 10](https://www.thoughtco.com/definition-of-base-10-2312365)) signed int |
| i | signed int (can detect octal (base 8) & hexadecimal (base 16) with [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm) |
| u | unsigned int |
| o | converts an unsigned int to [octal](https://www.tutorialspoint.com/octal-number-system) |
| x | converts an unsigned int to [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (lowercase 0x, a-f) |
| X | converts an unsigned int to [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (uppercase 0X, A-F) |
| f | float (uses lowercase for [_inf_, _infinity_, and _nan_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
| F | float (uses uppercase for [_INF_, _INFINITY_, and _NAN_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
| a | [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) float (lowercase xc and fep) |
| A | [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) float (uppercase XC and FEP) |
| e | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation) (lowercase 'e') |
| E | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation)  (uppercase 'E') |
| g | returns the shorter of %f and %e |
| G | returns the shorter of %f and %E |
| c | char | 
| s | 'string' literal/char array (e.g. "Hello!") | 
| p | memory/pointer address | 
| n | none, prints nothing; used to [return the amount of character read until %n is read/written](https://www.geeksforgeeks.org/n-in-scanf-in-c-with-example/) |
| % | none, prints a percent sign (the '%' sign cannot be escaped with a backslash) |

## Length Specifiers
The length specifier indicates the size of the datatype.

| Specifier | Size |
| -------- | ----- |
| h | short |
| l | long |
| ll | long long |
| L | long (long double only) |
| z | [size_t](https://www.geeksforgeeks.org/size_t-data-type-c-language/) |
> [Here](https://en.wikipedia.org/wiki/Printf_format_string#Length_field) is a comprehensive list.

## Width Specifier
The width specifier indicates the minimum amount of characters that the string/number must come out to.

| Specifier | Result |
| --------- | ------ |
| (integer) | specifies the minimum amount of characters that need to be printed (prints spaces if needed to match the amount) |

## Precision Specifier
The precision specifier changes the amount of decimal places shown when a float is printed.

| Specifier | Result |
| --------- | ------ |
| .(integer) | specifies the amount of decimal places to show for floating-point numbers |
> You can also use this to truncate strings after a certain amount of characters

## Flag Specifiers
Flags alter the standard formatting specifications.

| Flag | Action | 
| ---- | ------ |
| - | [left-justifies](https://en.wikipedia.org/wiki/Typographic_alignment#Justified) the text (right is the default) |
| + | puts a '+' in front of positive numbers |
| (space) | puts a space in front of positive numbers to keep alignment with negative numbers |
| 0 | [zero-pads](https://stackoverflow.com/questions/153890/printing-leading-0s-in-c) the number to fit the specified width |
| # | prints a radix indicator (0, 0x, 0X) for octal and hex numbers; keeps trailing zeros for floating-point numbers (decimal point) |

## Specifiers Unique to _strftime()_
The [_strftime()_](https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm) function from [\<time.h\>](https://www.tutorialspoint.com/c_standard_library/time_h.htm)
has its own set of format specifers used to convert strings to the date/time so the _tm_ (time) struct can hold it properly.
For example, the string "Tuesday" could be converted with the _%A_ format specifier. For a full list of format specifiers, see
[this article](https://www.ibm.com/docs/en/i/7.2?topic=functions-strftime-convert-datetime-string) by IBM.

## Escape Sequences
Escape sequences allow you to treat [metacharacters](https://en.wikipedia.org/wiki/Metacharacter) literally, preventing their normal action. <br />
I've tried to list them in the order that I find myself using them.

| Escape Sequence | Character |
| --------------- | ------ | 
| \n | [newline character](https://en.wikipedia.org/wiki/Newline) |
| \0 | [null-terminating character](http://www.cs.ecu.edu/karl/2530/spr17/Notes/C/String/nullterm.html) (often used in [C-strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)) |
| \t | tab character |
| \\' | apostrophe character |
| \\" | quotation mark character |
| \\\\ | backslash character |
| \a | plays the [bel (bell) character](https://rosettacode.org/wiki/Terminal_control/Ringing_the_terminal_bell) |
| \r | [carriage return character](https://www.quora.com/How-does-the-carriage-return-work-in-C) (manually resets writing to the beginning of the line, overwriting the current one) |
| \b | backspace character |
| \v | [vertical tab character](https://stackoverflow.com/questions/3380538/what-is-a-vertical-tab) |
| \f | [form feed (page break) character](https://en.wikipedia.org/wiki/Page_break#:~:text=Form%20feed%20is%20a%20page,control%2BL%20or%20%5EL%20.), starts a new page |
| \\? | used to avoid [trigraphs](https://en.wikipedia.org/wiki/Digraphs_and_trigraphs#C) (ANSI C) |
> Note: the carriage return character is pretty useful in writing progress bars

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
- [_Data Flair: 15 Types of Escape Sequence in C that Make your Coding Better_](https://data-flair.training/blogs/escape-sequence-in-c/)
- [_Wikipedia: Escape Sequences in C_](https://en.wikipedia.org/wiki/Escape_sequences_in_C#Non-standard_escape_sequences)
- [Javatpoint: Escape Sequences in C](https://www.javatpoint.com/escape-sequence-in-c)
