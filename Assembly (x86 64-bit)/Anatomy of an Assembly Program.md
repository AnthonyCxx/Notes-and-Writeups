# Anatomy of an Assembly Program
An assembly source file (.asm) has three major sections: _.data_, _.bss_, and _.text_. Both the _.data_ and _.bss_ sections store data; _.text_ contains the source code.

## .data
The _.data_ section contains modifiable, initialized data that can be accessed anywhere in the program. Data is declared in the format <br /> `<name> <datatype> <value>`.
For example, in the [_HelloWorld.asm_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Example%20Programs/HelloWorld.asm) program,
the text containing 'Hello, World!' is declared as <br /> `text db "Hello, World!"`. 

### _.data_ Datatypes
| Code | Full Name | Size (in bytes) | Size (in bits) | 
| -------- | --------- | --------------- | -------------- |
| db | Define Byte | 1 | 8 |
| dw | Define Word | 2 | 16 |
| dd | Define Doubleword | 4 | 32 |
| dq | Define Quadword | 8 | 64 |
> Note: a 'word' is a unit of size equal to 16 bits (2 bytes) <br />
> 
> Source: [_Tuts: x86 Assembly Datatypes_](https://www.assemblylanguagetuts.com/x86-assembly-data-types/) <br />

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
