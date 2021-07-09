# Registers in x86 Assembly
Registers are a part of the processor (CPU) that temporarily hold memory. <br />
In the x86_64 architecture, registers can hold up to 64 bits (8 bytes). <br />

## Max Capacity of a Register
| Datatype | Minimum Value | Maximum Value |
| -------- | ------------- | ------------- |
| Unsigned | 0 | 18,446,744,073,709,551,616 |
| Signed | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |


## Table of Registers
| 8-bit | 16-bit | 32-bit | 64-bit | Function |
| ----- | ------ | ------ | ------ | -------- |
|   al  |   ax   |   eax  |  rax   | [Accumulator](https://www.computerhope.com/jargon/a/accumulator.htm) (computation) |
|   bl  |   bx   |   ebx  |  rbx   | Base |
|   cl  |   cx   |   ecx  |  rcx   | Counter |
|   dl  |   dx   |   edx  |  rdx   | Data |
|  sil  |   si   |   esi  |  rsi   | Source (source for data copies) |
|  dil  |   di   |   edi  |  rdi   | Destination  (destination for data copies) |
|  bpl  |   bp   |   ebp  |  rbp   | Stack Base Pointer (start of the stack) |
|  spl  |   sp   |   esp  |  rsp   | Stack Pointer (current location in the stack, growing downwards) |
|  r8b  |   r8w  |   r8d  |   r8   | General Purpose Register |
|  r9b  |   r9w  |   r9d  |   r9   | General Purpose Register |
| r10b  |  r10w  |  r10d  |  r10   | General Purpose Register |
| r11b  |  r11w  |  r11d  |  r11   | General Purpose Register |
| r12b  |  r12w  |  r12d  |  r12   | General Purpose Register |
| r13b  |  r13w  |  r13d  |  r13   | General Purpose Register |
| r14b  |  r14w  |  r14d  |  r14   | General Purpose Register |
| r15b  |  r15w  |  r15d  |  r15   | General Purpose Register |
> Note: chars are 8-bit, shorts are 16-bit, ints are 32-bit, and longs are 64-bit (generally) <br />
>
> Sources: <br />
> [_Stanford: Guide to x86-64_](https://web.stanford.edu/class/archive/cs/cs107/cs107.1216/guide/x86-64.html) <br />
> [_University of Alaska Fairbanks: Full List of x86 Registers_](https://www.cs.uaf.edu/2015/fall/cs301/lecture/09_16_stack.html) <br />

## Registers by Name
| Register | Full Name |
| -------- | --------- |
| rax | register a extended |
| rbx | register b extended |
| rcx | register c extended |
| rdx | register d extended |
| rbp | register base pointer |
| rsp | register stack pointer |
| rsi | register source index |
| rdi | register destination index |
| r8 | register 8 |
| r9 | register 9 |
| r10 | register 10 |
| r11 | register 11 |
| r12 | register 12 |
| r13 | register 13 |
| r14 | register 14 |
| r15 | register 15 |
> Sources: <br />
> [_Harvard: Assembly 1: Basics_](https://cs61.seas.harvard.edu/site/2018/Asm1/) <br />
> [_Seneca College: x86-64 Register and Instruction Quick Start_](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) <br />
> [_TutorialsPoint: Assembly - Registers_](https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm) <br />

 ## Register Usage with Syscall (ID : rax)
Order of Arguments for Syscall
rdi, rsi, rdx, rcx, r8d, r9d (destination, source, data, counter, general register 8, general register 9) 
> Sources: <br />
> [_Seneca College: x86-64 Register and Instruction Quick Start_](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) <br />
