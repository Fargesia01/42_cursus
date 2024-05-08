SECTION .text
global ft_write

; rdi = file descriptor
; rsi = buffer
; rdx = count

ft_write:
    mov rax, 1
    syscall
    test rax, rax
    js .error
    ret

.error:
    mov rax, -1
    ret
