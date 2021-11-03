# C# Data Types

| File | Description | 
| ---- | ----------- |
| [Variables](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Variables.md) | declaring variables, global variables, and nullable variables |
| [Primitive Datatypes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/README.md#primitive-datatypes) | primitive datatypes (int, float, double, bool...) |
| [Non-primitive Datatypes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/README.md#non-primitive-datatypes) | non-primitive datatypes (array, enum, class, interface...) |
| [Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Operators.md) and [Operator Precedence](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/#operator-precedence) | operators and [operator precedence](https://www.ibm.com/docs/en/xl-c-and-cpp-aix/11.1.0?topic=operators-operator-precedence-associativity) |
| [Type-casting](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Type%20Casting.md) | Type-casting in C# |

## Primitive Datatypes
Technically, a string is a reference type, but I included it here too since it fits nicely.

| Datatype | Full Name | Bytes | Minimum Value | Maximum Value | Default Value | Literal Suffix | 
| --------- | ----------------------- | ----- | ------------- | ------------- | ------------- | -------------- |
| [bool](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/bool) | System.Boolean | 1 | false | true | false | N/A 
| [char](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/char) | System.Char | 2 | 0 | 65,535 | \0 (U+0000) | N/A |
| [string](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/strings/) | System.String | N/A | 0 / null | 2,048 bytes | null | N/A |
| [sbyte](https://docs.microsoft.com/en-us/dotnet/api/system.sbyte?view=net-5.0) | System.SByte | 1 | -128 | 127 | 0 | N/A |
| [byte](https://docs.microsoft.com/en-us/dotnet/api/system.byte?view=net-5.0) | System.Byte | 1 | 0 | 255 | 0 | N/A |
| [short](https://docs.microsoft.com/en-us/dotnet/api/system.int16?view=net-5.0) | System.Int16 | 2 | -32,768 | 32,767 | 0 | N/A |
| [ushort](https://docs.microsoft.com/en-us/dotnet/api/system.uint16?view=net-5.0) | System.UInt16 | 2 | 	0 | 65,535 | 0 | N/A |
| [int](https://docs.microsoft.com/en-us/dotnet/api/system.int32?view=net-5.0) | System.Int32 | 4 | -2,147,483,648 | 2,147,483,647 | 0 | N/A |
| [uint](https://docs.microsoft.com/en-us/dotnet/api/system.uint32?view=net-5.0) | System.UInt32 | 4 | 0 | 4,294,967,295 | 0 | _U_ or _u_ |
| [long](https://docs.microsoft.com/en-us/dotnet/api/system.int64?view=net-5.0) | System.Int64 | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 0 | _L_ or _l_ |
| [ulong](https://docs.microsoft.com/en-us/dotnet/api/system.uint64?view=net-5.0) | System.UInt64 | 8 | 0 | 18,446,744,073,709,551,615 | 0 | _UL_ or _ul_
| [float](https://docs.microsoft.com/en-us/dotnet/api/system.single?view=net-5.0) | System.Single | 4 | -3.402823 x 10^38 | 3.402823 x 10^38 | 0 | _F_ or _f_ |
| [double](https://docs.microsoft.com/en-us/dotnet/api/system.double?view=net-5.0) | System.Double | 8 | -1.79769313486232 x 10^308 | 1.79769313486232 x 10^308 | 0 | _D_ or _d_ |
| [decimal](https://docs.microsoft.com/en-us/dotnet/api/system.decimal?view=net-5.0) | System.Decimal | 16 | ±1.0 × 10^−28 | ±7.9 × 10^28 | 0 | _M_ or _m_ |
> Note: Always use the uppercase literal suffixes, as they are clearer. <br />
> Reference: [C# Documentation: Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/value-types) <br />
> Reference: [C# Documentation: Default Values of C# Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/default-values) <br />
> Reference: [Literal Suffixes in C#](https://www.c-sharpcorner.com/article/data-type-suffixes-in-c-sharp/) <br />

---
Doubles also have a special set of values for supporting infinity and NaN (see IEEE standard: [formats](https://en.wikipedia.org/wiki/IEEE_754#Formats)). 

| Concept | Float Representation | Double Representation |
| ------- | -------------------- | --------------------- |
| [Not a Number (NaN)](https://docs.microsoft.com/en-us/dotnet/api/system.double.nan?view=net-5.0#remarks) | `float.NaN` | `double.NaN` |
|  |  |  |
|  |  |  |
|  |  |  |

---

## Non-primitive Datatypes
| Datatype | Description |
| -------- | ----------- | 
| [String](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Strings.md) | text represented by an immutable sequence of characters |
| [Array](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Arrays.md) | a sequential collection of data of the same type |
| [Tuple](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Tuples.md) | an immutable collection of elements of different types |
| [Enum](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Enum.md) | a user-defined type that takes on one of a set of values |
| [Class](https://github.com/EthanC2/Notes-and-Writeups/tree/main/C%23/Object-oriented%20Programming) |  |
| [Struct](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Data%20and%20Data%20Types/Structs.md) | a simple, value-type for storing related data |
| Interface |  |
| Record |  |
| Delegate |  |

## Notes
-  private variables should have a `_` prepended (per industry standard, not my opinion) 
-  Instead of commas, C# uses underscores to separate digits (Ex. 1_000_000 == 1000000) 
- Strings use double quotation marks, and chars use single quotation marks
- Although the _decimal_ type is larger than _single_ and _double_, it also stores the decimals exactly. Use the _decimal_ type when the exact figure is important.
