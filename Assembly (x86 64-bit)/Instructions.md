# Instructions in x86 Assembly
Instructions, also called [_opcodes_](https://www.sciencedirect.com/topics/engineering/operation-code) (operation codes), are the instructions that the CPU understands.
The registers contain the data and the opcodes perform the manipulations on said data. When you need to do something that the CPU itself can't (like printing to the screen),
you have to make a [system call](https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_17_syscall.html). Most of the stuff here is taken from Yale's Computer Science department's
[_x86 Assembly Guide_](https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html). All credits to them.

This is a reference for instructions, but is not comprehensive because [there are _so_ many opcodes](https://www.felixcloutier.com/x86/).

## Data Movement Instructions

### mov
Copies data from the source (first operand) to the destination (second operand). <br /> If both are registers, then the must be of the same size and 
if the source and destination are the same, then the operation acts as [_nop_](https://en.wikipedia.org/wiki/NOP_(code)#:~:text=In%20computer%20science%2C%20a%20NOP,protocol%20command%20that%20does%20nothing.) (no operation).

### push

### pop

### lea

## Arithmetic Instructions

### add

### sub

### inc

### dec

### imul

## idiv

## Logical Instructions

### and

### or

### not

## Control Flow

### Unconditional Jump, _jmp_

### Conditional Jumps
Conditional jumps jump _if_ a condition is true.

| opcode | jump if |
| ------ | ------- |
| je | jump if equal |
| jne | jump if not equal |
| jz | jump if zero |
| jnz | jump if not zero |
| js | jump if signed (negative) |
| jl | jump if less than |
| jg | just if greater than |
| jle | jump if less than or equal to |
| jge | jump if greater than or equal to |
| jnle | jump if not less than or equal to |
| jnge | jump if not greater than or equal to |
| jc | jump if [carry](https://en.wikipedia.org/wiki/Carry_flag) |
| jnc | jump if [not carry](https://en.wikipedia.org/wiki/Carry_flag) |
> These are only a few conditional jumps. See [here](https://www.tutorialspoint.com/assembly_programming/assembly_conditions.htm) for more.

### cmp

### call

### ret

## Bit Operations

### neg

### xor

### shl

### shr
