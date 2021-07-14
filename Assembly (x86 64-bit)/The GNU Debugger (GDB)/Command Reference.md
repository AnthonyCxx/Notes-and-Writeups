# Command Reference for GDB
You can use _ctrl_ + _l_ to clear the terminal. You're welcome. <br /> 

Here's a more complete reference: [GDBReference: Commands](https://visualgdb.com/gdbreference/commands/)

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
The [_x_ command](https://visualgdb.com/gdbreference/commands/x) can be used to "display the memory contents at a given address using the specified format". Here,
`x/s 0x2004` gets the memory stored at 0x2004 (which is the text "Hello, World!". The output for the _x_ command can be formatted via `x/<format>` using 
[output formats](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_54.html). Formats include hex, binary, decimal, octal, etc.

| Specifier | Format |
| --------- | ------ |
| t | binary |
| o | octal |
| d | decimal |
| u | unsigned decimal | 
| x | hexadecimal |
| f | float |
| c | char |
| s | string (text) |
| a | memory address |
| i | instruction |

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

### info registers
_info registers_ (shortcut: _i r_) can be used to get the value of one or all of the registers.

```nasm
Breakpoint 2, __printf (format=0x8002004 "Hello, world!") at printf.c:28
28      printf.c: No such file or directory.
(gdb) info registers
rax            0x0                 0
rbx            0x8001170           134222192
rcx            0x8001170           134222192
rdx            0x7ffffffee458      140737488282712
rsi            0x7ffffffee448      140737488282696
rdi            0x8002004           134225924
rbp            0x7ffffffee350      0x7ffffffee350
rsp            0x7ffffffee348      0x7ffffffee348
r8             0x0                 0
r9             0x7fffff7c1d50      140737479712080
r10            0xb                 11
r11            0x2                 2
r12            0x8001060           134221920
r13            0x7ffffffee440      140737488282688
r14            0x0                 0
r15            0x0                 0
rip            0x7fffff604e10      0x7fffff604e10 <__printf>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb)
```
> The value of the registers at the breakpoint before the function _printf()_ in a "Hello, World!" C program.

## Running Programs and Controlling their Flow

### run
_run_ (shortcut: _r_) runs the program, stopping at any breakpoints

### continue
_continue_ (shortcut: _c_) resumes normal execution after reaching a breakpoint.

### step
_step_ (shortcut: _s_) executes the current line. If the line is a function, it stops at the first line of the function.

### next
_next_ (shortcut: _n_) executes the current line. If the line is a function, it executes the whole function.

## Breakpoints
The _break_ command (shortcut: _b_) puts a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint) in the program, stopping the flow of execution until resumed maually.
Breakpoints allow you to pause and monitor the state of the program. Use _info breakpoints_ (shortcut: _i b_) to list all breakpoints and their information.

### break
_break_ (shortcut: _b_) puts a breakpoint at the specified line number or function.

### enable/disable
_enable_ and _disable_ allow you to enable or disable breakpoints using `enable/disable breakpoint <breakpoint_number>`.

### delete
_delete_ (shortcut: _d_) deletes the specific breakpoint. If no breakpoint is given, it will prompt you to delete all breakpoints (y/n).

## Sources
VisualGDB Reference: [_Commands_](https://visualgdb.com/gdbreference/commands/) <br />
