; How to print a single digit, credit to Kupala's 'x86_64 Linux Assembly #5 - Math Operations and the Stack'

section .data
        number db 0,10

section .bss

section .text
        global main

main:
        ; Setup for printing the number
        mov     rax, 3              ; Move the number '3' into the rax register so it can be printed
        add     rax, 48             ; Add 48 to the given number (48 is the '0' character in ASCII)
        mov     [number], al        ; Move the lowest byte of 'rax' (al) into the pointer to 'number'

        ; Print the number (sys_write -- ID:1)
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, number
        mov     rdx, 2        ; The amount of characters in the number ('5' + newline char, '10')
        syscall

        ; sys_exit (ID:60)
        mov     rax, 60
        mov     rdi, 0
        syscall
