# Datatypes in C++
Anything in parentheses can be omitted.

## Primitive Types
| Datatype | Size (in bytes) | Minimum Value | Maximum Value | Literal Suffix |
| -------- | --------------- | ------------- | ------------- | -------------- | 
| (signed) char | 1 | -128 | 127 | N/A |  
| unsigned char | 1 | 0 | 255 | N/A |  
| (signed) short (int) | 2 | −32,768 | 32,767 | N/A |  
| unsigned short (int) | 2 | 0 | 65,535 | u/U |  
| (signed) int | 4 | -2,147,483,648 | 2,147,483,647 | N/A (default) |  
| unsigned int | 4 | 0 | 4,294,967,295  | u/U |  
| (signed) long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | l/L |  
| unsigned long (int) | 8 | 0 | 18,446,744,073,709,551,615 | ul/UL |
| (signed) long long (int) | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | ll/LL | 
| unsigned long long (int) | 8 | 0 | 18,446,744,073,709,551,615 | %ull/ULL |  
| float | 4 | 3.4E-38 | 3.4E+38 | f |
| double | 8 | 1.7E-308 | 1.7E+308 | N/A (default) |
| long double | 16 | 1.7E-308 | 1.7E+308 | L |
| bool | 1 | false | true | N/A |
> Note: floats have about 7 decimal places, doubles have about 15, and long doubles have about 19. <br />
> 
> Sources: <br />
> Microsoft: [_Built-in Types (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-160) <br />
> Microsoft: [_Datatype Limits (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160) <br />
> Microsoft: [_Integer Limits (C/C++)_](https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160) <br />

## Non-primitive Data Types
| Datatype | Function |
| -------- | -------- |
| [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Arrays.md) | a derived type that stores a collection of independent elements of the same datatype |
| [Structs](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Structs.md) | a user-defined type that stores a collection of variables as a single unit |
| [Enums]() | a user-defined type that has a set of defined values (e.g. on/off or red/yellow/blue) |
| [Unions]() | a user-defined datatype that stores a number of variables in a single space in memory |
| [Pointers]() | a derived type that stores the memory address of an object in memory (not the class kind of object) |
