# Assembling x86 Source Code with NASM and ld
```Bash
nasm -f elf64 hello.asm # assemble the program  
ld -s -o hello hello.o # link the object file nasm produced into an executable file  
./hello # hello is an executable file
```
> 'ld -s' [strips  the object file](https://www.computerhope.com/unix/strip.htm).
