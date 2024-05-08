SECTION .text
global ft_strcpy

; Dst = rdi, src = rsi
; return = rax

ft_strcpy:
    xor rbx, rbx
    xor rcx, rcx
    cmp rsi, 0
    jz return
    jmp copy

increment:
    inc rbx

copy:
    mov cl, byte [rsi + rbx]
    mov byte [rdi + rbx], cl
    cmp cl, 0
    jnz increment
    
return:
    mov rax, rdi
    ret
