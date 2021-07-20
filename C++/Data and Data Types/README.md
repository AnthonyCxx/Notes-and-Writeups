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
| [Structs](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20and%20Data%20Types/Structures.md) | a user-defined type that stores a collection of variables as a single unit |
| [Enums](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Enumerations.md) | a user-defined type that has a set of defined values (e.g. on/off or red/yellow/blue) |
| [Unions](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Unions.md) | a user-defined datatype that stores a number of variables in a single space in memory |
| [Pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20and%20Data%20Types/Pointers.md) | a derived type that stores the memory address of an object in memory (not the class kind of object) |

## Operator Precedence
| Precedence	| Operator | Description | Associativity |
| ----------- | -------- | ----------- | ------------- |
| 1 | :: | [Scope Resolution](https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-160) | N/A |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
| 2 | . and -> | [Member Access](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160) | L -> R |
| 2 | \[\] | [Array Subscript](https://docs.microsoft.com/en-us/cpp/cpp/subscript-operator?view=msvc-160) | L -> R |
| 2 | () | [Function Call](https://docs.microsoft.com/en-us/cpp/cpp/function-call-operator-parens?view=msvc-160) | L -> R |
| 2 | ++ | [Postfix Increment](https://docs.microsoft.com/en-us/cpp/cpp/postfix-increment-and-decrement-operators-increment-and-decrement?view=msvc-160) | L -> R |
| 2 | -- | [Postfix Increment](https://docs.microsoft.com/en-us/cpp/cpp/postfix-increment-and-decrement-operators-increment-and-decrement?view=msvc-160) | L -> R |
| 2 | typeid() | [Type Name](https://docs.microsoft.com/en-us/cpp/cpp/typeid-operator?view=msvc-160) | L -> R |
| 2 | const_cast\<\>() | [Constant Type Conversion](https://docs.microsoft.com/en-us/cpp/cpp/const-cast-operator?view=msvc-160) | L -> R |
| 2 | dynamic_cast\<\>() | [Dynamic Type Conversion](https://docs.microsoft.com/en-us/cpp/cpp/dynamic-cast-operator?view=msvc-160) | L -> R |
| 2 | reinterpret_cast\<\>() | [Reinterpreted Type Conversion](https://docs.microsoft.com/en-us/cpp/cpp/reinterpret-cast-operator?view=msvc-160) | L -> R |
| 2 | static_cast\<\>() | [Static Type Conversion](https://docs.microsoft.com/en-us/cpp/cpp/static-cast-operator?view=msvc-160) | L -> R |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
| 3 | sizeof() | [Size of Object or Type](https://docs.microsoft.com/en-us/cpp/cpp/sizeof-operator?view=msvc-160) | R -> L |
| 3 | ++ | [Prefix Increment](https://docs.microsoft.com/en-us/cpp/cpp/prefix-increment-and-decrement-operators-increment-and-decrement?view=msvc-160) | R -> L |
| 3 | -- | [Prefix Decrement](https://docs.microsoft.com/en-us/cpp/cpp/prefix-increment-and-decrement-operators-increment-and-decrement?view=msvc-160) | R -> L |
| 3 | ~ | [One's Complement Operator](https://docs.microsoft.com/en-us/cpp/cpp/one-s-complement-operator-tilde?view=msvc-160) | R -> L |
| 3 | ! | [Logical Not](https://docs.microsoft.com/en-us/cpp/cpp/logical-negation-operator-exclpt?view=msvc-160) | R -> L |
| 3 | + | [Unary Plus](https://docs.microsoft.com/en-us/cpp/cpp/unary-plus-and-negation-operators-plus-and?view=msvc-160) | R -> L |
| 3 | - | [Unary Minus](https://docs.microsoft.com/en-us/cpp/cpp/unary-plus-and-negation-operators-plus-and?view=msvc-160) | R -> L |
| 3 | & | [Address-of](https://docs.microsoft.com/en-us/cpp/cpp/address-of-operator-amp?view=msvc-160) | R -> L |
| 3 | * | [Indirection/Dereferencing](https://docs.microsoft.com/en-us/cpp/cpp/indirection-operator-star?view=msvc-160) | R -> L |
| 3 | new | [Create Object](https://docs.microsoft.com/en-us/cpp/cpp/new-operator-cpp?view=msvc-160) | R -> L |
| 3 | delete | [Destroy Object](https://docs.microsoft.com/en-us/cpp/cpp/delete-operator-cpp?view=msvc-160) | R -> L |
| 3 | () | [C-Style Cast](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) | R -> L |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
| 4 | .* and ->* | [Pointer to Member](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160) | L -> R |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
| 5 | \* | [Multiplication](https://docs.microsoft.com/en-us/cpp/cpp/multiplicative-operators-and-the-modulus-operator?view=msvc-160) | L -> R |
| 5 | / | [Division](https://docs.microsoft.com/en-us/cpp/cpp/multiplicative-operators-and-the-modulus-operator?view=msvc-160) | L -> R |
| 5 | % | [Modulus](https://docs.microsoft.com/en-us/cpp/cpp/multiplicative-operators-and-the-modulus-operator?view=msvc-160) | L -> R |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
| 6 |  | []() |  |
| 6 |  | []() |  |
| 6 |  | []() |  |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
> Sources:
> Microsoft: [_C++ built-in operators, precedence, and associativity_](https://docs.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-160) <br />
> CPPReference: [_C++ Operator Precedence_](https://en.cppreference.com/w/cpp/language/operator_precedence) <br />
> Wikipedia: [_Operators in C and C++_](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) <br />
> Bowling Green State Univeristy CS: [_C++ Operator Precedence_](https://www.bgsu.edu/arts-and-sciences/computer-science/cs-documentation/c-plus-plus-operator-precedence.html) <br />
