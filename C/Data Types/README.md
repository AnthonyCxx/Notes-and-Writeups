# Datatypes in C

## Primitive Data Types
Anything in parentheses can be left to be implied (i.e. you can declare an signed short int using '_signed short int_','_short int_' or just '_short_'). <br />

| Datatype | Size (in bytes) | Minimum Value | Maximum Value | [Format Specifier](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Formatting%20Input%20and%20Output.md) | 
| -------- | --------------- | ------------- | ------------- | ---------------- |
| (signed) char | 1 | -128 | 127 | %c |  
| unsigned char | 1 | 0 | 255 | %c |  
| (signed) short (int) | 2 | −32,768 | 32,767 | %hi |  
| unsigned short (int) | 2 | 0 | 65,535 | %hu |  
| (signed) int | 4 | -2,147,483,648 | 2,147,483,647 | %d |  
| unsigned int | 4 | 0 | 4,294,967,295  | %u |  
| (signed) long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | %ld |  
| unsigned long (int) | 8 | 0 | 18,446,744,073,709,551,615 | %lu |  |
| (signed) long long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | %lld | 
| unsigned long long (int) | 8 | 0 | 18,446,744,073,709,551,615 | %llu |  
| float | 4 | 3.4E-38 | 3.4E+38 | %f |
| double | 8 | 1.7E-308 | 1.7E+308 | %lf |
| long double | 16 | 1.7E-308 | 1.7E+308 | %Lf |
> Note: floats have about 7 decimal places, doubles have about 15, and long doubles have about 19. <br />
> Note: to use Unicode characters, you must use [char8_t, char16_t, char32_t, or wchar_t](https://stackoverflow.com/questions/11287213/what-is-a-wide-character-string-in-c-language). <br />
>
> Sources: <br />
> [Microsoft: Integer Limits (C/C++)](https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160) <br />
> [Microsoft: Datatype Limits (C++)](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160) (still relevant) <br />
> [GeeksforGeeks: Datatypes in C](https://www.geeksforgeeks.org/data-types-in-c/) <br />
> [TutorialsPoint: C - Data Types](https://www.tutorialspoint.com/cprogramming/c_data_types.htm) <br />
> [TutorialsPoint: Format Specifiers in C](https://www.tutorialspoint.com/format-specifiers-in-c) <br />
> [Wikipedia: IEEE Standard for Floating-point Types](https://en.wikipedia.org/wiki/IEEE_754-1985) <br />

## Non-primitive Data Types
| Datatype | Function |
| -------- | -------- |
| [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Data%20Types/Arrays.md) | a data structure that stores a collection of independent elements of the same datatype |
| [Structs](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Data%20Types/Structures.md) | a data structure that stores a collection of variables as a single unit |
| [Enums](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Data%20Types/Enumerations.md) | a user-defined type that has a set of defined values (e.g. on/off or red/yellow/blue) |
| [Unions](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Data%20Types/Unions.md) | a user-defined datatype that stores a number of variables in a single space in memory |
