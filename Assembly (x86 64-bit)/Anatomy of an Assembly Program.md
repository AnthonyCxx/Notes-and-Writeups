# Anatomy of an Assembly Program
An assembly source file (.asm) has three major sections: _.data_, _.bss_, and _.text_. <br /> 
Both the _.data_ and _.bss_ sections store data; _.text_ contains the source code.

## _.data_ Section
The _.data_ section contains modifiable, initialized data that can be accessed anywhere in the program.

### _.data_ Datatypes
| [Pseudo-instruction](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) | Full Name | Size (in bytes) | Size (in bits) | 
| ------------------ | --------- | --------------- | -------------- |
| db | Define Byte | 1 | 8 |
| dw | Define Word | 2 | 16 |
| dd | Define Doubleword | 4 | 32 |
| dq | Define Quadword | 8 | 64 |
> Note: a 'word' is a unit of size equal to 16 bits (2 bytes) <br /> 

### Declaring Variables
Standard variables are declared in the format `<name> <datatype> <value>`. <br />
For example, in the [_HelloWorld.asm_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Example%20Programs/HelloWorld.asm) program, the text containing 'Hello, World!' is declared as `text db "Hello, World!"`.

### Declaring Constants
Constants can be declared with _equ_. Declaring a lucky number 7 would be: `luckynum equ 10`. Using _equ_ prevents the variable from being changed throughout the program.
> Reference: [_Posix.nl: Chapter 3, The NASM Language (Section 3.2.4 Equ: Defining Constants)_](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoc3.html) <br />

## _.bss_ Section
The _.bss_ section contains uninitialized data. Typically, the memory set aside for the _.bss_ section is initialized to all 0s.

### _.bss_ Datatypes
| [Pseudo-instruction](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) | Full Name | Size (in bytes) | Size (in bits) | 
| ------------------ | --------- | --------------- | -------------- |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |

## _.text_ Section
The _.text_ section contains the source code. The _.bss_ and _.data_ sections are stored inbetween the stack & heap and the _.text_ section to prevent them from
overwriting the _.data_ section.


## Sources
[_Tuts: x86 Assembly Datatypes_](https://www.assemblylanguagetuts.com/x86-assembly-data-types/) <br />
[_Posix.nl: _](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoc3.html) <br />
[_Tortall.net: Chapter 3, Pseudo-instructions in the NASM Language_](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) <br />
[_GeeksforGeeks: Memory Layout of a C Program_](https://www.geeksforgeeks.org/memory-layout-of-c-program/) <br />
[_TutorialsPoint: Assembly - Memory Segments_](https://www.tutorialspoint.com/assembly_programming/assembly_memory_segments.htm) <br />
[_TutorialsPoint: Assembly - Basic Syntax_](https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm) <br />
[_Wikipedia: Data Segments_](https://en.wikipedia.org/wiki/Data_segment) <br />
