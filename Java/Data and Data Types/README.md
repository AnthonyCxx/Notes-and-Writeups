# Datatypes in Java

## Primitive Data Types
| Data Type | Bytes | Minimum Value | Maximum Value | Default Value | Literal Suffix | 
| --------- | ----- | ------------- | ------------- | ------------- | -------------- |
| byte | 1 | -128 | 127 | 0 | N/A |  
| short | 2 | -32,768 | 32,767 | 0 | N/A |  
| int | 4 | -2,147,483,648 | 2,147,483,647 | 0 | N/A |  
| long | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 0L | L |  
| float | 4 | 4.9e-324 | 1.8e+308 | 0.00f | f |  
| double | 8 | 1.4e-045 | 3.4e+038 | 0.00d | d |  
| boolean | 1/8 (1 bit) | 0 | 1 | false | N/A |  
| char | 2 | 0 | 65,535 | '\u0000' | N/A | 
> Sources: <br />
> docs.oracle.com: [_Primitive Datatypes_](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html) <br />
> W3Schools: [_Java Data Types_](https://www.w3schools.com/java/java_data_types.asp) <br />
> Java: The Complete Reference, 11th Edition (2018)

## Non-primitive Datatypes
| Datatype | Function | 
| -------- | -------- |
| Class |  |
| [Array](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Java/Data%20and%20Data%20Types/Arrays.md) | data structure that stores a collection of elements of the same type |
| String |  |

## Operators
| Operator | Type | Function |
| -------- | ---- | -------- |
| = | binary |variable assignment |
| + | binary | addition |
| - | binary | subtraction |
| * | binary | multiplication |
| / | binary | division |
| % | binary | [modulus](https://en.wikipedia.org/wiki/Modular_arithmetic) |
| ! | unary prefix | logical not | 
| ++ | unary prefix | increment by 1 |
| -- | unary prefix | decrement by 1 | 
| ++ | unary postfix | increment by 1 |
| -- | unary postfix | decrement by 1 |
| == | binary | equality |
| != | binary | inequality |
| < | binary | less than|
| > | binary | greater than |
| <= | binary | less than or equal to |
| >= | binary | greater than or equal to |
| instanceof | binary | true if class or subclass of |
| && | binary | logical and |
| \|\| | binary | logical or |
| ? : | ternary | [ternary operator](https://www.geeksforgeeks.org/java-ternary-operator-with-examples/) |
| ~ | unary prefix | [bitwise complement](https://www.javatpoint.com/bitwise-operator-in-java) |
| & | binary | [bitwise and](https://www.programiz.com/java-programming/bitwise-operators#and) |
| \| | binary | [bitwise or](https://www.programiz.com/java-programming/bitwise-operators#or) |
| ^ | binary | [xor](https://en.wikipedia.org/wiki/Exclusive_or) (exclusive or) |
| >> | binary | [left bit-shift](https://www.interviewcake.com/concept/java/bit-shift) |
| << | binary | [right bit-shift](https://www.interviewcake.com/concept/java/bit-shift) |
| >>> | binary | [unsigned right bit-shift](https://www.javatpoint.com/unsigned-right-shift-operator-in-java) |
