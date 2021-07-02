# Datatypes in C

## Primitive Data Types
Anything in parentheses can be left to be implied (i.e. you can declare an unsigned short int using '_signed short int_','_short int_' or just '_short_').
The actual size of the datatypes (in bytes) and their min/max values may vary from system to system (especially 32- vs 64-bit systems).
Run [this script](https://github.com/steven-schronk/C-Programming-Examples/commit/077c0d23312f66cd8209683c639516e56b06eb47) to find correct values for your system.
| Datatype | Size (in bytes) | Minimum Value | Maximum Value | Format Specifier |
| -------- | --------------- | ------------- | ------------- | ---------------- |
| (signed) char | 1 | -128 | 127 | %c |
| unsigned char | 1 | 0 | 255 | %c |
| (signed) short (int) | 2 | −32,768 | 32,767 | %hi |
| unsigned short (int) | 2 | 0 | 65,535 | %hu |
| (signed) int | 4 | -2,147,483,648 | 2,147,483,647 | %d |
| unsigned int | 4 | 0 | 4,294,967,295  | %u |
| (signed) long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | %ld |
| unsigned long (int) | 8 | 0 | 18,446,744,073,709,551,615 | %lu |
| (signed) long long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | %lld |
| unsigned long long (int) | 8 | 0 | 18,446,744,073,709,551,615 | %lld |
| float (6 dec. places) | 4 | 3.4E-38 | 3.4E+38 | %f |
| double (15 dec. places) | 8 | 1.7E-308 | 1.7E+308 | %lf |
| long double (19  dec. places) | 16 | 1.7E-308 | 1.7E+308 | %Lf |
> Note: floats have about 7 decimal places, doubles have about 15, and long doubles have about 19. <br />
>
> Sources: <br />
> [Microsoft: Integer Limits (C/C++)](https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160) <br />
> [Microsoft: Datatype Limits (C++)](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160) (still relevant) <br />
> [GeeksforGeeks: Datatypes in C](https://www.geeksforgeeks.org/data-types-in-c/) <br />
> [TutorialsPoint: C - Data Types](https://www.tutorialspoint.com/cprogramming/c_data_types.htm) <br />
> [TutorialsPoint: Format Specifiers in C](https://www.tutorialspoint.com/format-specifiers-in-c) <br />
> [Wikipedia: IEEE Standard for Floating-point Types](https://en.wikipedia.org/wiki/IEEE_754-1985) <br />

## Non-primitive Data Types
- [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Data%20Types/Arrays.md)
- Structs
- Unions
- Enums
