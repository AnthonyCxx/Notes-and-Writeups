# Registers in x86 Assembly
Registers are a part of the processor (CPU) that temporarily hold memory. <br />
In the x86_64 architecture, registers can hold up to 64 bits (8 bytes). <br />

## Max Capacity of a Register
| Datatype | Minimum Value | Maximum Value |
| -------- | ------------- | ------------- |
| Unsigned | 0 | 18,446,744,073,709,551,616 |
| Signed | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |


## Table of Registers
| 8-bit | 16-bit | 32-bit | 64-bit | Full Name | Function |
| ----- | ------ | ------ | ------ | --------- | -------- |
|   al  |   ax   |   eax  |  rax   | register a | [Accumulator](https://www.computerhope.com/jargon/a/accumulator.htm) (computation) | 
|   bl  |   bx   |   ebx  |  rbx   | register b | Base |
|   cl  |   cx   |   ecx  |  rcx   | register c | Counter |
|   dl  |   dx   |   edx  |  rdx   | register d | Data |
|  sil  |   si   |   esi  |  rsi   | register source index | Source (source for data copies) |
|  dil  |   di   |   edi  |  rdi   | register destination index | Destination  (destination for data copies) |
|  bpl  |   bp   |   ebp  |  rbp   | register base pointer | Stack Base Pointer (start of the stack) |
|  spl  |   sp   |   esp  |  rsp   | register stack pointer | Stack Pointer (current location in the stack, growing downwards) |
|  r8b  |   r8w  |   r8d  |   r8   | register 8 | General Purpose Register |
|  r9b  |   r9w  |   r9d  |   r9   | register 9 | General Purpose Register |
| r10b  |  r10w  |  r10d  |  r10   | register 10 | General Purpose Register |
| r11b  |  r11w  |  r11d  |  r11   | register 11 | General Purpose Register |
| r12b  |  r12w  |  r12d  |  r12   | register 12 | General Purpose Register |
| r13b  |  r13w  |  r13d  |  r13   | register 13 | General Purpose Register |
| r14b  |  r14w  |  r14d  |  r14   | register 14 | General Purpose Register |
| r15b  |  r15w  |  r15d  |  r15   | register 15 | General Purpose Register |

![image](https://user-images.githubusercontent.com/70488531/125147716-02018800-e0fb-11eb-93a8-25f0807d010e.png)
> Sources: <br />
> [_Stanford: Guide to x86-64_](https://web.stanford.edu/class/archive/cs/cs107/cs107.1216/guide/x86-64.html) <br />
> [_University of Alaska Fairbanks: Full List of x86 Registers_](https://www.cs.uaf.edu/2015/fall/cs301/lecture/09_16_stack.html) <br />
> [_Harvard: Assembly 1: Basics_](https://cs61.seas.harvard.edu/site/2018/Asm1/) <br />
> [_Seneca College: x86-64 Register and Instruction Quick Start_](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) <br />
> [_TutorialsPoint: Assembly - Registers_](https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm) <br />
