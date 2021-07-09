# A Reference for x86 Assembly (64-bit)
Assembly is a platform-dependent, low-level programming language, which is directly converted into machine code by an assembler such as [NASM](https://en.wikipedia.org/wiki/Netwide_Assembler) or [GAS](https://en.wikipedia.org/wiki/GNU_Assembler). Assembly works directly with the memory and registers of a machine
and is very similar in style to [machine code](https://whatis.techtarget.com/definition/machine-code-machine-language), and so is sometimes referred to as 
"symbolic machine code". Assembly makes use of [system calls](https://en.wikipedia.org/wiki/System_call), or 'syscalls', to directly request actions from the [kernel](https://www.engineersgarage.com/kernel-programming/). The exact call is determined by the syscall ID, which goes in the rax register. The other registers will contain 
supporting information for the syscall (arguments).

## Books Used
[_Modern X86 Assembly Language Programming, 2nd Edition_](https://www.amazon.com/Modern-X86-Assembly-Language-Programming/dp/1484240626/ref=sr_1_3?__mk_es_US=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=Modern+X86+Assembly+Language+Programming&qid=1625776593&sr=8-3) by Daniel Kusswurm <br />
[_Beginning x64 Assembly Programming: From Novice to AVX Professional_](https://www.amazon.com/Beginning-x64-Assembly-Programming-Professional-ebook/dp/B07ZVKM3CC/ref=sr_1_1_sspa?dchild=1&keywords=Beginning+x86+Assembly&qid=1625776678&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExOFcwRTA3RUI5NDVFJmVuY3J5cHRlZElkPUEwNDg5NzkwM0JLNUg2UkxDQU9JTyZlbmNyeXB0ZWRBZElkPUEwMDY5NDM4MVkwS1NKMFhTM0s4RCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) by Jo Van Hoey
