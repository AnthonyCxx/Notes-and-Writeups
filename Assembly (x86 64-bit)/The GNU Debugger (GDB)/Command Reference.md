# Command Reference for GDB

### q(uit)
Entering _quit_ (shortcut: _q_) exits GDB. _ctrl_ + _C_ does not work.

### disassemble
The _disassemble_ (shortcut: _disas_) command disassembles the machine code back into assembly code so you can read it. <br /> Run `disassemble <function>/address>` to 
disassemble a section of the machine code. You should start debugging by running `disassemble main` to get an idea of the core of the program.

## Breakpoints
The _break_ (shortcut: _b_) puts a [breakpoint](https://en.wikipedia.org/wiki/Breakpoint) in the program, stopping the flow of execution until resumed maually.
Breakpoints allow you to pause and monitor the state of the program
