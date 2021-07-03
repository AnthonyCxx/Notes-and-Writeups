# Formatting Input and Output with Format Specifiers in C
The [_printf()_](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) and [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm)
functions are used to read input/write output that is formatted using [format specifiers](https://tutorialsbookmarks.com/format-specifiers-in-c/). The format specifiers
allow you to control the amount of decimal places in a float, change the [radix](https://en.wikipedia.org/wiki/Radix) of a number (allowing for [octal](https://www.tutorialspoint.com/octal-number-system)/[hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) representation), and even represent the number
in [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation).
## Master List of Format Specifiers

### Datatype Placeholders
| Datatype | Specifier | 
| -------- | --------- |
| char | %c |
| short | %hi |
| unsigned short | %hu |
| int | %d |
| unsigned int | %u |
| long | %uld | 
| unsigned long | %uld |
| long long | %lld |
| unsigned long long | %llu |
| float | %f |
| double | %lf |
| long double | %Lf |
> Sources: <br />
> [_TutorialsPoint: Format Specifiers in C_](https://www.tutorialspoint.com/format-specifiers-in-c) <br />
> [_TutorialsBookmarks: All 19 C Format Specifiers_](https://tutorialsbookmarks.com/format-specifiers-in-c/) <br />
> [_University of Illinois Chicago: Summary of C Datatypes_](https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/DataTypesSummary.pdf) <br />

### Other Format Specifiers
| Specifier | Function |
| --------- | -------- |
| %s | placeholder for a string literal (e.g. "Hello, World!") |
| %p | memory address (and pointer) placeholder (do not use %d) |
| %n | prints nothing; used to [return the amount of character read until %n is read/written](https://www.geeksforgeeks.org/n-in-scanf-in-c-with-example/) |
| %% | prints a percent sign (the '%' sign cannot be escaped with a backslash) |
| %e | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation) (lowercase 'e') |
| %e | converts a float to [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation)  (uppercase 'E') |
| %g | returns the shorter of %f and %e |
| %G | returns the shorter of %f and %E |
| %o | converts an unsigned integer to the [octal](https://www.tutorialspoint.com/octal-number-system) system |
| %x | converts an unsigned integer into [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (lowercase a-f) |
| %X | converts an unsigned integer into [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (uppercase A-F) |
> Sources: <br />
> [_Linux Man. Pages: Printf() Format Specifiers_](https://linux.die.net/man/3/printf) <br />
> [_Wikipedia: Printf() String Formatting_](https://en.wikipedia.org/wiki/Printf_format_string) <br />
> [_StackOverflow: %f vs %g and %G_](https://stackoverflow.com/questions/5913102/what-is-the-difference-between-g-and-f-in-c) <br />
