SECTION .text
global ft_strcmp

; Rdi = s1, rsi = s2
; Rax = return value

ft_strcmp:
    xor rax, rax
    xor rcx, rcx
    jmp loop

increment:
    inc rcx

loop:
    mov al, byte [rdi + rcx]
    cmp al, byte [rsi + rcx]
    jg greater
    jl lower
    cmp byte [rdi + rcx], 0
    jnz increment
    jmp return

greater:
    sub al, byte [rsi + rcx]
    ret

lower:
    mov al, byte [rsi + rcx]
    sub al, byte [rdi + rcx]
    neg rax
    ret

return:
    mov al, 0
    ret
