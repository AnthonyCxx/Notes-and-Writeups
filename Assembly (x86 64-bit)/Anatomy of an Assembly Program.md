# Anatomy of an Assembly Program
An assembly source file (.asm) has three major sections: _.data_, _.bss_, and _.text_. <br /> 
Both the _.data_ and _.bss_ sections store data; _.text_ contains the source code.

## _.data_ Section
The _.data_ section contains modifiable, initialized data that can be accessed anywhere in the program.

### _.data_ Datatypes
| [Pseudo-instruction](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) | Full Name | Size (in bytes) | Size (in bits) | 
| ------------------ | --------- | --------------- | -------------- |
| db | Define a Byte | 1 | 8 |
| dw | Define a Word | 2 | 16 |
| dd | Define a Doubleword | 4 | 32 |
| dq | Define a Quadword | 8 | 64 |
| dt | Define Ten Bytes | 10 | 80 |
> Note: a 'word' is a unit of size equal to 16 bits (2 bytes) <br /> 

### Declaring Variables
Standard variables are declared in the format `<name> <datatype> <value>`. <br />
For example, in the [_HelloWorld.asm_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Example%20Programs/HelloWorld.asm) program, the text containing 'Hello, World!' is declared as `text db "Hello, World!"`.

### Declaring Constants
Constants can be declared with _equ_. Declaring a lucky number 7 would be: `luckynum equ 7`. <br />
Using _equ_ prevents the variable from being changed throughout the program.
> Reference: [_Posix.nl: Chapter 3, The NASM Language (Section 3.2.4 Equ: Defining Constants)_](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoc3.html) <br />

## _.bss_ Section
The _.bss_ section contains uninitialized data. When you declare variables in the _.bss_ section, you are effectively reserving the memory for them.
Typically, the memory set aside for the _.bss_ section is initialized to all 0s. Since variables in the _.bss_ sections do not have values, the 'value'
section is replaced by the number to reserve. For example, `charArr resb 20` reserves 20 bytes.

### _.bss_ Datatypes
| [Pseudo-instruction](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) | Full Name | Size (in bytes) | Size (in bits) | 
| ------------------ | --------- | --------------- | -------------- |
| resb | Reserve a Byte | 1 | 8 |
| resw | Reserve a Word | 2 | 16 |
| resd | Reserve a Doubleword | 4 | 32 |
| resq | Reserve a Quadword | 8 | 64 |
| rest | Reserve Ten Bytes | 10 | 80 |

## _.text_ Section
The _.text_ section contains the source code. The _.bss_ and _.data_ sections are stored inbetween the stack & heap and the _.text_ section to prevent them from
overwriting the _.data_ section.

```nasm
; Example Assembly Program: Hello World

; .data  :  where all data is defined before compilation (known values)
section .data
        text db "Hello, World!",0      ; 'text' defines a byte (db) that points to the first character ('H') of the string. 
                                       ; The '0' is the null-terminating char ('\0') in ASCII

; .bss   :  where all data is allocated for future use (unknown values)
section .bss
; Empty section, used for uninitialized variables
       
; .text  :  where the code will go
section .text
        global main

                             
main:                          ; label 'main' : an identifier which can be placed before a statement as an instruction operand
        mov     rax, 1         ; move 1 (the num. ID of sys_write) into the rax register
        mov     rdi, 1         ; move 1 (the arg. ID of standard output) into the rdi 
        mov     rsi, text      ; reference the text (put 'text' from '.data' into the register source index register
        mov     rdx, 13        ; 13 is the size of "Hello, World!"(don't count null terminating char). 
        syscall                ; sys_write(1, text, 13)  -- (stdout, text, 13 characters)

        mov     rax, 60        ; move 60 (the num. ID of sys_exit) into the rax register
        mov     rdi, 0         ; move exit code 0 (EXIT_SUCCESS) into the rdi register
        syscall                ; sys_exit(0)  -- (exit code)
```


## Sources
[_Tuts: x86 Assembly Datatypes_](https://www.assemblylanguagetuts.com/x86-assembly-data-types/) <br />
[_TutorialsPoint: Assembly - Variables_](https://www.tutorialspoint.com/assembly_programming/assembly_variables.htm) <br />
[_Posix.nl: Chapter 3, The NASM Language_](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoc3.html) <br />
[_Tortall.net: Chapter 3, Pseudo-instructions in the NASM Language_](https://www.tortall.net/projects/yasm/manual/html/nasm-pseudop.html) <br />
[_GeeksforGeeks: Memory Layout of a C Program_](https://www.geeksforgeeks.org/memory-layout-of-c-program/) <br />
[_TutorialsPoint: Assembly - Memory Segments_](https://www.tutorialspoint.com/assembly_programming/assembly_memory_segments.htm) <br />
[_TutorialsPoint: Assembly - Basic Syntax_](https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm) <br />
[_Wikipedia: Data Segments_](https://en.wikipedia.org/wiki/Data_segment) <br />
