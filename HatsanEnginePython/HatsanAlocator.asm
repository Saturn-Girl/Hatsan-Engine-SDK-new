[BITS 64]

section .data
    index dq 32
    data dq 24

section .text
    global _start

_start:
    mov rax,[index]
    mov rcx,[data]

    push rax
    push rcx
