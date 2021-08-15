; Simple program to show how to do basic arithmetic in assembly
; Credit to Kupala and his video 'x86_64 Linux Assembly #5 - Math Operations and the Stack'
section .data
        digit db 0,10

section .bss
; Empty! No uninitialized variables

section .text
        global main

main:
        ; add(ition)
        mov     rax, 3
        mov     rbx, 4
        add     rax, rbx
        call    _printRAXDigit

        ; sub(traction)
        mov     rax, 7
        mov     rbx, 2
        sub     rax, rbx
        call _printRAXDigit

        ; mul(tiplication)
        mov     rax, 3
        mov     rbx, 3
        mul     rbx
        call _printRAXDigit

        ; div(ision) -- for some reason this is throwing a floating-point exception?
        mov     rax, 3
        mov     rbx, 1
        div     rbx
        call _printRAXDigit

        ; inc(rement)
        mov     rax, 5
        inc     rax
        call _printRAXDigit

        ; dec(rement)
        mov     rax, 10
        dec     rax
        call _printRAXDigit

        ; Exit the program
        mov     rax, 60
        mov     rdi, 0
        syscall


; Print a single digit 0-9
_printRAXDigit:
        ; Prepare the number to be printed
        add     rax, 48
        mov     [digit], al

        ; Print the number
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, digit
        mov     rdx, 2
        syscall
        ret
