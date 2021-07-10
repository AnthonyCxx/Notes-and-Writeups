;  **** BEGINNING OF PROGRAM ****
;
;     INSTRUCTIONS FOR ASSEMBLING:
;     nasm -f elf64 hello.asm 
;     gcc -o hello hello.o
;     ./hello          
;

; .data  :  where all data is defined before compilation (known values)
section .data
        text db "Hello, World!",0      ; 'text' defines a byte (db) that points to the first character ('H') of the string. 
                                       ; The '0' is the null-terminating char ('\0') in ASCII

; .bss   :  where all data is allocated for future use (unknown values)
section .bss
; Empty section, used for uninitialized variables
       
; .text  :  where the code will go
section .text
        global main

                               ; '_start' tells the linker where to start. Think of it like the main functions
main:                          ; label 'main' : an identifier which can be placed at the beginning of a statement as an instruction operand
        mov     rax, 1         ; move 1 (the num. ID of sys_write) into the rax register
        mov     rdi, 1         ; move 1 (the arg. ID of standard output) into the rdi 
        mov     rsi, text      ; reference the text (put 'text' from '.data' into the register source index register
        mov     rdx, 13        ; 13 is the size of "Hello, World!"(don't count null terminating char). Needed because 'text' only points to the first char.
        syscall                ; sys_write(1, text, 13)  -- (stdout, text, 13 characters)

        mov     rax, 60        ; move 60 (the num. ID of sys_exit) into the rax register
        mov     rdi, 0         ; move exit code 0 (EXIT_SUCCESS) into the rdi register
        syscall                ; sys_exit(0)  -- (exit code)

;  **** END OF PROGRAM ****

;//////////////////////////////

; Notes on registers:
; Registers are a part of the processor that temporarily hold memory.
; In the x86_64 architecture, registers can hold up to 64 bits (8 bytes).
;
; This means that each register can hold the values:
;
; Unsigned:  0 - 18,446,744,073,709,551,616
; Signed:   -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807

; Register types:
; ==============
; name: max stroage
; rax : 64-bit
; eax : 32-bit
; ax  : 16-bit
; al  :  8-bit

; 8-bit | 16-bit | 32-bit | 64-bit
;   al  |   ax   |   eax  |  rax
;   bl  |   bx   |   ebx  |  rbx
;   cl  |   cx   |   ecx  |  rcx
;   dl  |   dx   |   edx  |  rdx
;  sil  |   si   |   esi  |  rsi
;  dil  |   di   |   edi  |  rdi
;  bpl  |   bp   |   ebp  |  rbp
;  spl  |   sp   |   esp  |  rsp
;  r8b  |   r8w  |   r8d  |   r8
;  r9b  |   r9w  |   r9d  |   r9
; r10b  |  r10w  |  r10d  |  r10
; r11b  |  r11w  |  r11d  |  r11
; r12b  |  r12w  |  r12d  |  r12
; r13b  |  r13w  |  r13d  |  r13
; r14b  |  r14w  |  r14d  |  r14
; r15b  |  r15w  |  r15d  |  r15

;////////////////////////////////

; Syscall (System Calls):
; - Syscalls invoke a service from the kernal
; - Syscalls differ by operating systems since they have different kernels
; - Syscalls have a numeric ID associated with them, which identifies the call
; - Syscalls take arguments (list of inputs)

; Syscall : sys_write (ID: 1)
; ===========================
; Arugment Type   |  Proper Register   | Argument Description
; -----------------------------------------------------------
; Syscall ID      |         rax        |  1 (the syscall ID no.)
; File descriptor |         rdi        |  0, 1, or 2 (standard input, output, and error streams respectively)
; Buffer          |         rsi        |  Location of string to write
; Count           |         rdx        |  Length of string

; Syscall : sys_exit (ID: 60)
; ===========================
; Argument Type  |  Proper Register  | Argument Description
; ---------------------------------------------------------
; Syscall ID      |        rax        | 60 (the syscall ID no.)
; Exit Code       |        rdi        | 0 or 1 (EXIT_SUCCESS or EXIT_FAILURE respectively)
