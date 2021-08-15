# Registers in x86 Assembly
Registers are a part of the processor (CPU) that temporarily hold data that the CPU is currently working with/on. <br />
Registers can be accessed by the CPU _much_ faster than memory.

As a note, you can treat a register like a pointer by surrounding it in brackets like _\[rax\]_.

## Max Capacity of a Register
In the x86_64 architecture, registers can hold up to 64 bits (8 bytes). 

| Data Type | Minimum Value | Maximum Value |
| -------- | ------------- | ------------- |
| Unsigned | 0 | 18,446,744,073,709,551,616 |
| Signed | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |


## Table of Registers
| 8-bit | 16-bit | 32-bit | 64-bit | Full Name (64-bit) | Function |
| ----- | ------ | ------ | ------ | --------- | -------- |
|  ah/al  |   ax   |   eax  |  rax   | register a extended | [Accumulator](https://www.computerhope.com/jargon/a/accumulator.htm) (stores the result of arithmetic operations) | 
|   bh/bl  |   bx   |   ebx  |  rbx   | register b  extended| Base (base offset for instructions) |
|   ch/cl  |   cx   |   ecx  |  rcx   | register c extended | Counter (for loops) |
|   dh/dl  |   dx   |   edx  |  rdx   | register d extended | Data |
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
> The 'ah/al' refer to how the [8-bit registers can either be can either be low or high](https://riptutorial.com/x86/example/6973/8-bit-registers). <br />
> Reference: [When should I use low vs high registers?](https://stackoverflow.com/questions/53562739/if-i-have-an-8-bit-value-is-there-any-advantage-to-using-an-8-bit-register-inst)

### Visualization
<img src="https://user-images.githubusercontent.com/70488531/125147735-1776b200-e0fb-11eb-8a21-46af83ae5cb7.png" width="1200" height="150"/>

> Image via Wikiepdia: [_x86 Assembly/X86 Architecture_](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture#General-Purpose_Registers_(GPR)_-_16-bit_naming_conventions)

## Status/Flag Register

| Bit | Abbrev. | Description | If 1 | If 0 |
| --- | ------- | ----------- | ---- | ---- |
| 0   |   CF  | [Carry flag](https://en.wikipedia.org/wiki/Carry_flag) | Carry == True | Carry == False |
| 2   |   PF  |  [Parity flag](https://en.wikipedia.org/wiki/Parity_flag) | Parity == Even | Parity == Odd |
| 4   |   AF  |  [Auxiliary carry flag](https://en.wikipedia.org/wiki/Adjust_flag) | Auxillary Carry == True | Auxillary Carry == False |
| 6   |   ZF  |  [Zero flag](https://en.wikipedia.org/wiki/Zero_flag) | Result == Zero | Result != Zero |
| 7   |   SF  |  [Sign flag](https://en.wikipedia.org/wiki/Negative_flag) | Result == Negative | Result == Positive |
| 8   |   TF  |  [Trap flag](https://en.wikipedia.org/wiki/Trap_flag) | Interrupt after Instruction == True | Interrupt after Instruction == False |
| 9   |   IF  |  [Interrupt enable flag](https://en.wikipedia.org/wiki/Interrupt_flag) | Interruptable == True | Interruptable == False |
| 10  |   DF  |  [Direction flag](https://en.wikipedia.org/wiki/Direction_flag) | Direction == Down (right -> left) | Direction == Up (left -> right) |
| 11  |   OF  |  [Overflow flag](https://en.wikipedia.org/wiki/Overflow_flag) | Overflow == True | Overflow == False |

## Sources

### Registers
Stanford University: [_Guide to x86-64_](https://web.stanford.edu/class/archive/cs/cs107/cs107.1216/guide/x86-64.html) <br />
University of Alaska Fairbanks: [_Full List of x86 Registers_](https://www.cs.uaf.edu/2015/fall/cs301/lecture/09_16_stack.html) <br />
Harvard University: [_Assembly 1: Basics_](https://cs61.seas.harvard.edu/site/2018/Asm1/) <br />
Seneca College: [_x86-64 Register and Instruction Quick Start_](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) <br />
TutorialsPoint: [_Assembly - Registers_](https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm) <br />
StackOverflow: [_How to know if a register is a “general purpose register”?_](https://stackoverflow.com/questions/45538021/how-to-know-if-a-register-is-a-general-purpose-register/45538667) <br />
Techdifference: [_Difference Between Registers and Memory_](https://techdifferences.com/difference-between-register-and-memory.html) <br />

### Flags
C-Jump: [_EFLAGS Bit Labels_](http://www.c-jump.com/CIS77/ASM/Instructions/I77_0070_eflags_bits.htm) and [_EFLAGS Individual Bit Flags_](http://www.c-jump.com/CIS77/ASM/Instructions/I77_0070_eflags_bits.htm) <br />
University of Alaska Fairbanks: [_CS 301 Lecture: x86 "Flag" Bits_](https://www.cs.uaf.edu/2009/fall/cs301/lecture/12_07_flags.html) <br />
osdev.org: [_CPU Registers x86_](https://wiki.osdev.org/CPU_Registers_x86) <br />
Wikipedia: [_FLAGS register_](https://en.wikipedia.org/wiki/FLAGS_register) <br />
