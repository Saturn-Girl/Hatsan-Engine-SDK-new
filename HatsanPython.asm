[BITS 64]


extern Log
extern Python
extern CheckValue

section .data
    LOG dq 1
    index dq 32

section .text:
    global _start
    global HatsanPlayer

_start:
    mov rdi, [LOG]
    mov rsi, [index]

    push rdi
    push rsi

    add rdi,rsi

    call HatsanPlayer

HatsanPlayer:
    call Log

    mov rax, 24
    mov rdi, 1

    add rax,rdi
    mov rdi, [LOG]

    push rax
    push rdi

    mov rcx, 42
    call CheckValue
    call Python

    
