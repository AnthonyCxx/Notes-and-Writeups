; This program is designed to teach how input works in x86_64 assembly.
; If you do not know how input works, visit 'HelloWorld.asm'

section .data
        ; Prompt to enter the person's name
        prompt db "Enter your name: ",0    ; prompt
        promptLen equ $-prompt-1           ; length of the prompt (discluding the final '\0')

        ; Text to greet the user
        greeting db "Good morning, ",0     ; greeting
        greetingLen equ $-greeting-1       ; length of greeting (discluding the final '\0')

section .bss
        name resb 26  ; Reserve 26 bytes (characters) for the name

section .text
        global main

main:
        ; Prompt the user for their name
        call _prompt

        ; Get the user's name from the keyboard
        call _getName

        ; Print the greeting 'Good morning, '
        call _greet

        ; print the user's name after the beginning of the greeting
        call _printName

        ; sys_exit (ID:60)
        mov     rax, 60
        mov     rdi, 0
        syscall


; Subroutine '_prompt' prompts the user for their name
_prompt:
        ; sys_write (ID:1)
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, prompt
        mov     rdx, promptLen
        syscall
        ret


; Subroutine '_getName' reads the user's name (up to 26 characters) from stdin (standard input)
_getName:
        ; sys_read (ID:0)
        mov     rax, 0          ; Syscall ID 0 is 'sys_read', which reads input from the console
        mov     rdi, 0          ; Use file descriptor 0: stdin (standard input)
        mov     rsi, name       ; Move the reserved array of characters for the user's name into the source index
        mov     rdx, 26         ; Move the amount of characters to read (26) into the data register
        syscall                 ; Make the call, reading from the console
        ret                     ; Return execution to where '_getName' was called from


; Subroutine '_greet' prints the first part of the greeting (ending before the person's name)
_greet:
        ; sys_write (ID:1)
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, greeting
        mov     rdx, greetingLen
        syscall
        ret


; Subroutine '_printName' finishes printing the greeting by
_printName:
        ; sys_write (ID:1)
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, name
        mov     rdx, 26
        syscall
        ret
