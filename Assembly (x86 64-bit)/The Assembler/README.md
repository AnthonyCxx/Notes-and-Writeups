# Assembling x86 Source Code with NASM and GCC

```shell
nasm -f elf64 -g hello.asm 
gcc --o hello hello.o  -no-pie
```
