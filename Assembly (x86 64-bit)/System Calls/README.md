# System Calls in x86 Assembly
A system call (syscall) is a request to the [kernel](https://www.engineersgarage.com/kernel-programming/) to perform an action. When you make a syscall, the type of 
request is determined by the numeric ID in the rax register and the other registers are used as the parameters for the syscall. See the chart below for all the 
parameters necessary to call _sys\_write_.

### Syscall for _sys\_write_
| Arugment Type | Proper Register | Argument Description |
| ------------- | --------------- | -------------------- |
| Syscall ID      |         rax        |  1 (the syscall ID no.) |
| File descriptor |         rdi        |  0, 1, or 2 (standard input, output, and error streams respectively) |
| Buffer          |         rsi        |  Location of string to write | 
| Count           |         rdx        |  Length of string |

## References for Linux Syscalls
Filippo.io: [_Searchable Linux Syscall Table for x86 and x86_64P_](https://filippo.io/linux-syscall-table/) <br />
blog.rchapman.org: [_LINUX SYSTEM CALL TABLE FOR X86 64_](http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/) <br />

## Sources
University of Alaska Fairbanks: [_Direct Operating System Access via Syscalls_](https://www.cs.uaf.edu/2017/fall/cs301/lecture/11_17_syscall.html) <br />
PackageCloud blog: [The Definitive guide to Linux System Calls](https://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/) <br />
Seneca College: [_x86-64 Register and Instruction Quick Start_](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) <br />
