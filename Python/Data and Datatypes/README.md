# The Bare Basics of Python

| File | Function |
| ---- | -------- |
| [Primitive Datatypes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Primitive%20Types.md) | the basic datatypes that make up Python |
| [Non-primitive Datatypes](https://github.com/EthanC2/Notes-and-Writeups/tree/main/Python/Data%20and%20Datatypes#non-primitive-datatypes) | the basic data structures that make up Python |
| [Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Built-in%20Operators.md) | functions associated with tokens |
| [Functions](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Common%20Functions.md) | a collection of the most common Python functions |
| [Slicing](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Slicing.md) | access a portion of any iterable (strings, lists, tuples, etc.) |

## Primitive Datatypes
There are four primitive types: [strings](https://realpython.com/python-data-types/#strings), [integers](https://realpython.com/python-data-types/#integers), [floating-point numbers](https://realpython.com/python-data-types/#floating-point-numbers), and [booleans](https://realpython.com/python-data-types/#boolean-type-boolean-context-and-truthiness)
> Reference: [String Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/String%20Methods.md)

## Non-primitive Datatypes
> All data structures can store collections of varying types without problem. <br />

| Datatype | Purpose |
| -------- | ------- |
| [list](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Lists.md) | a dynamically-sized array |
| [tuple](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Tuples.md) | an immutable sequence of elements |
| [dict](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Dictionary.md) | a data structure that stores key-value pairs |
| [set](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md) | an collection of unique elements |
| [frozenset](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md) | an immutable set |
| [Binary Sequence Types]() | [_bytes_](https://www.programiz.com/python-programming/methods/built-in/bytes), [_bytearray_](https://www.programiz.com/python-programming/methods/built-in/bytearray), and [_memoryview_](https://www.geeksforgeeks.org/memoryview-in-python/) |
> _immutable_ means unalterable/unchangable.

## Operator Precedence
| Order | Operator(s) | Description |
| ----- | ----------- | ----------- |
| 01 | () | Expressions inside parentheses |
| 02 | [], (), . | Subscription, slicing, calls, attribute references |
| 03 | [await](https://docs.python.org/3/reference/expressions.html#await-expression) | await expression |
| 04 | \*\* | Exponent |
| 05 | +, -, ~ | Unary plus, unary minus, and one's complement |
| 06 | \*, @, /, //, % | Multiplication, matrix multiplication, division, modulus |
| 07 | +, - | Binary addition, subtraction |
| 08 | <<, >> | Bit shifts |
| 09 | & | Bitwise AND |
| 10 | ^ | Bitwise XOR |
| 11 | \| | Bitwise OR |
| 12 | in, not in, is, is not, <, <=, >, >=, ==, != | any comparison |
| 13 | not | Boolean NOT |
| 14 | and | Boolean AND |
| 15 | or | Boolean OR |
| 16 | __ if __ else __ | Ternary Operator |
| 17 | lambda | Lambda Expression |
| 18 | := | Assignment within Expression (Walrus Operator) |
> Source: [_Python Documentation: Section 6.17, Operator Precedence_](https://docs.python.org/3/reference/expressions.html#operator-precedence) <br />
