section .data
        text db "Hello, world!",10

section .bss
; Empty!

; // DRIVER CODE //
section .text
        global main

main:
        ; MAIN FUNCTION
        call _helloWorld

        ; sys_exit (ID:60)
        mov     rax, 60     ;
        mov     rdi, 0      ; exit with status code 0 (OK)
        syscall

; Subroutine that prints 'Hello, world!'
_helloWorld:
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, text
        mov     rdx, 14
        syscall
        ret
