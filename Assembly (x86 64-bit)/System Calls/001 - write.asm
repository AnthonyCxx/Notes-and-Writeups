section .data
    text db "Hello, world!",0    ; Define a single-byte char pointer to 'H' (null-terminated str)
                                 ; 'text' length: 13

section .bss
; empty!

section .text
        global main
        
main:
        ; sys_write (ID: 1)
        mov     rax, 1          ; Move the ID of sys_write (1) into rax
        mov     rdi, 1          ; Write to stream 1 (stdout, the screen)
        mov     rsi, text       ; Use the 'text' pointer as the source of the text
        mov     rdx, 13         ; The amount of characters to read
        syscall                 ; Make the syscall


        ; sys_exit (ID: 60)
        mov     rax, 60         ; Move the ID of sys_exit (60) into rax
        mov     rdi, 0          ; The ID of EXIT_SUCCESS (0)
        syscall                 ; Make the syscall
