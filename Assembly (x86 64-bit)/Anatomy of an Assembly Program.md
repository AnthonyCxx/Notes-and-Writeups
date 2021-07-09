# Anatomy of an Assembly Program
An assembly source file (.asm) has three major sections: _.data_, _.bss_, and _.text_. Both the _.data_ and _.bss_ sections store data; _.text_ contains the source code.

## .data
The _.data_ section contains modifiable, initialized data that can be accessed anywhere in the program. When you declare a variable in the _.data_ section, it is allocated

### _.data_ Datatypes
| Datatype | Full Name | Size (in bytes) | Size (in bits) | 
| -------- | --------- | --------------- | -------------- |
| db | Byte | 1 | 8 |
| dw | Word | 2 | 16 |
| dd | Doubleword | 4 | 32 |
| dq | Quadword | 8 | 64 |
> Source: <br />
> [_Tuts: x86 Assembly Datatypes_](https://www.assemblylanguagetuts.com/x86-assembly-data-types/) <br />

## .bss
The _.bss_ section contains uninitialized data (e.g. char text[50];). Typically, the memory set aside for the _.bss_ section is initialized to all 0s.

### _.bss_ Datatypes


## .text
The _.text_ section contains the source code. The _.bss_ and _.data_ sections are stored inbetween the stack & heap and the _.text_ section to prevent them from
overwriting the _.data_ section.


## Sources
[_GeeksforGeeks: Memory Layout of a C Program_](https://www.geeksforgeeks.org/memory-layout-of-c-program/) <br />
[_TutorialsPoint: Assembly - Memory Segments_](https://www.tutorialspoint.com/assembly_programming/assembly_memory_segments.htm) <br />
[_TutorialsPoint: Assembly - Basic Syntax_](https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm) <br />
[_Wikipedia: Data Segments_](https://en.wikipedia.org/wiki/Data_segment) <br />
