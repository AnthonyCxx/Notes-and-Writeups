# Formatting Input and Output with Format Specifiers in C
The [_printf()_](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) and [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm)
functions are used to read input/write output that is formatted using [format specifiers](https://tutorialsbookmarks.com/format-specifiers-in-c/). The format specifiers
allow you to [format a string](https://www.cprogramming.com/tutorial/printf-format-strings.html), control the amount of decimal places in a float, change the [radix](https://en.wikipedia.org/wiki/Radix) of a number (allowing for [octal](https://www.tutorialspoint.com/octal-number-system)/[hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) representation), and even represent a number in [scientific notation](https://www.merriam-webster.com/dictionary/scientific%20notation). Format specifiers start with a _%_ sign and are alphanumeric (with the exception of _%%_). Modifiers for format
specifiers should be in the order `%[parameter][flags][width][.precision][length]<type>` (only the % followed by the datatype is necessary.

## Type Specifier
The type specifier specifies the [datatype](https://www.geeksforgeeks.org/data-types-in-c/) of the variable.

| Specifier | Datatype |
| -------- | --------- |
| d  | ([base 10](https://www.thoughtco.com/definition-of-base-10-2312365)) signed int |
| i | signed int (detects octal (base 10) & hexadecimal (base 16) with [_scanf()_](https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm) |
| u | unsigned int |
| o | converts an unsigned int to the [octal](https://www.tutorialspoint.com/octal-number-system) system |
| x | converts an unsigned int into [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (lowercase a-f) |
| X | converts an unsigned int into [hexadecimal](https://www.tutorialspoint.com/hexadecimal-number-system) (uppercase A-F) |
| f | float (uses lowercase for [_inf_, _infinity_, and _nan_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
| F | float (uses uppercase for [_INF_, _INFINITY_, and _NAN_](https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html)) | 
|  |  | 
|  |  | 
|  |  | 
|  |  |

## Table 2

<table>
  <tr><th>Table 1 Heading 1 </th><th>Table 1 Heading 2</th><th>Table 1 Heading 3</th></tr>
<tr><td>

|Table 1| Middle | Table 2|
|--|--|--|
|a| not b|and c |

</td><td>

|b|1|2|3| 
|--|--|--|--|
|a|s|d|f|

</td><td>
  
| a | b | c |
| - | - | - |
|  |  |  |\
</tr> </table>

## List of Common Format Specifiers

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

## Formatting Tricks
Replace anything in curly braces, _{ }_, with the appropriate item.

Use [https://en.wikipedia.org/wiki/Printf_format_string](https://en.wikipedia.org/wiki/Printf_format_string)

| Specifier | Example | Function |
| --------- | ------- | -------- |
| %0d |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |

## Sources
Dear god, this was so much research. Barely any of the lists were comprehensive.

- [_C PLus PLus reference: cstdio: printf()_](https://www.cplusplus.com/reference/cstdio/printf/)
- [_TutorialsPoint: Format Specifiers in C_](https://www.tutorialspoint.com/format-specifiers-in-c) <br />
- [_TutorialsBookmarks: All 19 C Format Specifiers_](https://tutorialsbookmarks.com/format-specifiers-in-c/) <br />
- [_University of Illinois Chicago: Summary of C Datatypes_](https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/DataTypesSummary.pdf) <br />
- [_Linux Man. Pages: Printf() Format Specifiers_](https://linux.die.net/man/3/printf) <br />
- [_Wikipedia: Printf() String Formatting_](https://en.wikipedia.org/wiki/Printf_format_string) <br />
- [_StackOverflow: %f vs %g and %G in C_](https://stackoverflow.com/questions/5913102/what-is-the-difference-between-g-and-f-in-c) <br />
- [_StackOverflow: %f vs %F in C_](https://stackoverflow.com/questions/51908513/difference-between-f-and-f-in-printf/51908594) <br />
- [_GeeksforGeeks: %d vs %i in C_](https://www.geeksforgeeks.org/difference-d-format-specifier-c-language/) <br />
