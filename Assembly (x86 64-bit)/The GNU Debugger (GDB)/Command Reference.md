# Command Reference for GDB
You can use _ctrl_ + _l_ to clear the terminal. You're welcome.

### quit
Entering _quit_ (shortcut: _q_) exits GDB. _ctrl_ + _C_ does not work.

### help
_help_ (shortcut: _h_) prints the commands related to a topic (breakpoints, data, aliases, etc.) along with a short summary of each command.
If you do not provide a topic, it will list the topics.

### info
The _info_ command (shortcut: _i_) provides information about gdb, the current program, and the platform (os, macros, GDB settings).

### disassemble
The _disassemble_ command (shortcut: _disas_) disassembles the machine code back into assembly code so you can read it. <br /> Run `disassemble <function>/address>` to 
disassemble a section of the machine code. You should start debugging by running <br /> `disassemble main` to get an idea of the core of the program.

## Breakpoints
The _break_ command (shortcut: _b_) puts a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint) in the program, stopping the flow of execution until resumed maually.
Breakpoints allow you to pause and monitor the state of the program.

### run
_run_ (shortcut: _r_) runs the program, stopping at any breakpoints

### delete
_delete_ (shortcut: _d_) deletes the specific breakpoint. If no breakpoint is given, it will prompt you to delete all breakpoints (y/n).
