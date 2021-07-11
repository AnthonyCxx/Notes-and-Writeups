# Command Reference for GDB

### q(uit)
Entering _q_ (short for _quit_) exits GDB. _ctrl_ + _C_ does not work.

### disassemble
The _disas_ (short for _disassemble_) command disassembles the machine code back into assembly code so you can read it. Run `disases <function>/address>` to 
disassemble a section of the machine code. You should start debugging by running _disassemble main_ to get an idea of the core of the program.
