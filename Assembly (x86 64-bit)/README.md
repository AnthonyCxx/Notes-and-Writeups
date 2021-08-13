# A Reference for x86 Assembly (64-bit, Linux)
Assembly is a platform-dependent, low-level programming language, which is directly converted into [machine code](https://whatis.techtarget.com/definition/machine-code-machine-language) by an [assembler](https://searchdatacenter.techtarget.com/definition/assembler) such as [NASM](https://en.wikipedia.org/wiki/Netwide_Assembler) or [GAS](https://en.wikipedia.org/wiki/GNU_Assembler). Assembly works directly with the memory and registers of a machine
and is very similar in style to machine code, and so is sometimes referred to as 
"symbolic machine code". Assembly makes use of [system calls](https://en.wikipedia.org/wiki/System_call) (syscalls) to directly request actions from the [kernel](https://www.engineersgarage.com/kernel-programming/). The exact call is determined by the syscall ID, which goes in the rax register. The other registers will contain 
supporting information for the syscall (arguments). <br />

I'm learning as I go and just using this as a form of documenting what I've learned. This is not meant to be an authority of any kind nor is it meant to be comprehensive.
Finally, since I am programming on Linux, I use [AT&T syntax](http://www.sig9.com/articles/att-syntax) and not Intel.

## Contents
- [Anatomy of an Assembly Program](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Anatomy%20of%20an%20Assembly%20Program.md)
- [Registers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Registers.md)
- [Instructions](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Assembly%20(x86%2064-bit)/Instructions.md) (opcodes)
- [System Call Index](https://github.com/EthanC2/Notes-and-Writeups/tree/main/Assembly%20(x86%2064-bit)/System%20Calls)

## Books Used
[_Modern x86 Assembly Language Programming, 2nd Edition_](https://www.amazon.com/Modern-X86-Assembly-Language-Programming/dp/1484240626/ref=sr_1_3?__mk_es_US=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=Modern+X86+Assembly+Language+Programming&qid=1625776593&sr=8-3) by Daniel Kusswurm <br />
[_Beginning x64 Assembly Programming: From Novice to AVX Professional_](https://www.amazon.com/Beginning-x64-Assembly-Programming-Professional-ebook/dp/B07ZVKM3CC/ref=sr_1_1_sspa?dchild=1&keywords=Beginning+x86+Assembly&qid=1625776678&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExOFcwRTA3RUI5NDVFJmVuY3J5cHRlZElkPUEwNDg5NzkwM0JLNUg2UkxDQU9JTyZlbmNyeXB0ZWRBZElkPUEwMDY5NDM4MVkwS1NKMFhTM0s4RCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) by Jo Van Hoey <br />
[_X86 Assembly Language and C Fundamentals 1st Edition_](amazon.com/X86-Assembly-Language-C-Fundamentals/dp/1466568240) by Joseph Cavanaugh <br />
[_Oracle: x86 Assembly Language Reference Manual_](https://docs.oracle.com/cd/E19620-01/805-4693/805-4693.pdf) by... Oracle? <br />

## Other Resources
[NASM (Assembly) Tutorial by Ray](https://cs.lmu.edu/~ray/notes/nasmtutorial/) <br />
[Modern x64 Assembly Series](https://www.youtube.com/watch?v=rxsBghsrvpI&list=PLKK11Ligqitg9MOX3-0tFT1Rmh3uJp7kA) by Creel <br />

## Recommended Videos
[_Comparing C to machine language_](https://www.youtube.com/watch?v=yOyaJXpAYZQ) by Ben Eater
