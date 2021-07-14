# Command Reference for GDB
You can use _ctrl_ + _l_ to clear the terminal. You're welcome.

## Basic Commands

### quit
Entering _quit_ (shortcut: _q_) exits GDB. _ctrl_ + _C_ does not work.

### help
_help_ (shortcut: _h_) prints the commands related to a topic (breakpoints, data, aliases, etc.) along with a short summary of each command.
If you do not provide a topic, it will list the topics.

### info
The _info_ command (shortcut: _i_) provides information about gdb, the current program, and the platform (os, macros, GDB settings).

## Analyzing a Program

### disassemble
The _disassemble_ command (shortcut: _disas_) disassembles the machine code back into assembly code so you can read it. <br /> Run `disassemble <function>/address>` to 
disassemble a section of the machine code. You should start debugging by running <br /> `disassemble main` to get an idea of the core of the program.

```nasm
(gdb) disas main
Dump of assembler code for function main:
   0x0000000000001149 <+0>:     endbr64
   0x000000000000114d <+4>:     push   %rbp
   0x000000000000114e <+5>:     mov    %rsp,%rbp
   0x0000000000001151 <+8>:     lea    0xeac(%rip),%rdi        # 0x2004
   0x0000000000001158 <+15>:    mov    $0x0,%eax
   0x000000000000115d <+20>:    callq  0x1050 <printf@plt>
   0x0000000000001162 <+25>:    mov    $0x0,%eax
   0x0000000000001167 <+30>:    pop    %rbp
   0x0000000000001168 <+31>:    retq
End of assembler dump.
```
> A dump of a "Hello, World!" C program

### x
The [_x_ command](https://visualgdb.com/gdbreference/commands/x) can be used to "display the memory contents at a given address using the specified format". 

```nasm
(gdb) disas main
Dump of assembler code for function main:
   0x0000000000001149 <+0>:     endbr64
   0x000000000000114d <+4>:     push   %rbp
   0x000000000000114e <+5>:     mov    %rsp,%rbp
   0x0000000000001151 <+8>:     lea    0xeac(%rip),%rdi        # 0x2004
   0x0000000000001158 <+15>:    mov    $0x0,%eax
   0x000000000000115d <+20>:    callq  0x1050 <printf@plt>
   0x0000000000001162 <+25>:    mov    $0x0,%eax
   0x0000000000001167 <+30>:    pop    %rbp
   0x0000000000001168 <+31>:    retq
End of assembler dump.
(gdb) x/s 0x2004
0x2004: "Hello, world!"
```
> A dump of a "Hello, World!" C program

## Breakpoints
The _break_ command (shortcut: _b_) puts a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint) in the program, stopping the flow of execution until resumed maually.
Breakpoints allow you to pause and monitor the state of the program.

### run
_run_ (shortcut: _r_) runs the program, stopping at any breakpoints

### break
_break_ (shortcut: _b_) puts a breakpoint at the specified line number or function. _info break_ will list all breakpoints.

### delete
_delete_ (shortcut: _d_) deletes the specific breakpoint. If no breakpoint is given, it will prompt you to delete all breakpoints (y/n).
