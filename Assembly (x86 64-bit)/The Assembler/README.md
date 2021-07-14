# Assembling x86 Source Code with NASM and GCC
```Bash
nasm -f elf64 hello.asm    
gcc -o hello hello.o 
./hello 
```

or 

```shell
nasm -f elf64 -g alive.asm -l alive.lst 
gcc -o alive alive.o -no-pie
```
