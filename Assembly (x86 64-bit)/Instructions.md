# Instructions in x86 Assembly
Instructions, also called [_opcodes_](https://www.sciencedirect.com/topics/engineering/operation-code) (operation codes), are the instructions that the CPU understands.
The registers contain the data and the opcodes perform the manipulations on said data. When you need to do something that the CPU itself can't (like printing to the screen),
you have to make a [system call](https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_17_syscall.html). Most of the stuff here is taken from Yale's Computer Science department's
[_x86 Assembly Guide_](https://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html). All credits to them.

This is a reference for instructions, but is not comprehensive because [there are _so_ many opcodes](https://www.felixcloutier.com/x86/). <br />
Another note: I organized these by my own standards. For example, _lea_ is technically an arithmetic instruction since it doesn't read RAM.

## Data Movement Instructions

### mov
Copies data from the source (first operand) to the destination (second operand).
If both are registers, then the must be of the same size and if the source and destination are the same, then the operation acts as [_nop_](https://en.wikipedia.org/wiki/NOP_(code)#:~:text=In%20computer%20science%2C%20a%20NOP,protocol%20command%20that%20does%20nothing.) (no operation).

### push
Pushes the value of a register onto the stack.

```nasm
push eax
```

### pop
Pop a value from the stack, removing it and storing it in the given register.

```nasm
pop eax
```

## Arithmetic Instructions
_reg_ stands for 'register' and _value_ just means any mathematical value like the number 5, 27, et cetra.

### add
_add_ is used for unsigned and signed additive operations. <br />
Check the _overflow_ (OF) flag for a signed carry and the _carry_ (CF) flag for an unsigned carry.

```nasm
; Add rax and rbx, storing the result in rax
mov     rax, 3
mov     rbx, 4
add     rax, rbx
```
> [_CF (Carry) and OF (Overflow) Flag_](https://stackoverflow.com/questions/791991/about-assembly-cfcarry-and-ofoverflow-flag) <br />

### sub
_sub_ substracts the second operand from the first and stores the result in the first. <br />
Check the _overflow_ (OF) flag for a signed borrow and the _carry_ (CF) flag for an unsigned borrow.

```nasm
; Subtract rax and rbx, storing the result in rax
mov     rax, 7
mov     rbx, 2
sub     rax, rbx
```


### mul/imul
_mul_ multiplies the given register/value by the _rax_ register and stores the result in it. <br />

When working with signed (potentially negative) numbers, use _imul_ instead of _mul_.
```nasm
; Multiply rax and rbx, storing the result in rax
mov     rax, 3
mov     rbx, 3
mul     rbx    
```
> _mul_ implcitily takes rax as the first parameter.

## div/idiv
_div_ divides the given register/value by the _rax_ register and stores the result in it. <br />

When working with signed (potentially negative) numbers, use _idiv_ instead of _div_.
```nasm
; Divide rax and rbx, storing the result in rax
mov     rax, 3
mov     rbx, 1
div     rbx         
```
> _div_ implcitily takes rax as the first parameter. <br />
>
> If you are getting a floating-point exception when doing divison, [see here](https://stackoverflow.com/questions/9793060/getting-floating-point-exception-while-trying-to-use-div-in-assembly).

### inc/dec
_inc_ adds one to a value, _dec_ subtracts one. <br />

Be careful, because _inc_ does not set the _overflow_ (OF) flag if it overflows and _dec_ will not set the _carry_ (CF) flag if it carries.

```nasm
; Increment rax by one
mov     rax, 5
inc     rax
        
; Decrement rax by one
mov     rax, 10
dec     rax
```

### neg
_neg_ negates the value of a register (makes it negative if positive and positive if negative).

```nasm
; Negate the value in rax
neg rax
```

## Logical Instructions
Read about [how logical instructions work in assembly](https://www.tutorialspoint.com/assembly_programming/assembly_logical_instructions.htm) before using them. They work entirely
in binary.

### and

### or

### not

### xor

You can quickly zero a register by using _xor_ on the same register like `xor rax, rax`.

### nand

### nor

### xnor
Reversing the result of a _xor_ operation yields whether or not the numbers were equal. <br />
Writing `xnor eax, ecx` is a condensed `xor eax, ecx ; not eax`.

## Control Flow

### Unconditional Jump, _jmp_
_jmp_ 'jumps' to a [label](https://docs.oracle.com/cd/E19120-01/open.solaris/817-5477/esqaq/index.html), moving the flow of execution to the labeled block of code <br />
The _main_ function is an example of an identifier in assembly.

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
_cmp_ compares two registers by subtraction. If the result is zero, then they were the same.
Although the _cmp_ method performs subtraction, it does not actually alter either of the registers since it does not store the result — it just sets the flags.

The result of a simple comparison like `cmp eax, ecx` could then be used by a conditional jump like _je_ (jump if equal).

### call/ret
_call_ is used to initiate a [subroutine](https://www.uet.edu.pk/pp/ee/~mtahir/EE371/EE371/Experiment_5.pdf). The important part about subroutines is that
you can return the flow of execution to where you initially called the subroutine at with _call_ by using the _ret_ (return) instruction.

## Shifting Bits

### shl
Shift left

### shr
Shift right
