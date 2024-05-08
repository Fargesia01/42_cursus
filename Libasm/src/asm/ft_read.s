SECTION .text
global ft_read

; rdi = file descriptor
; rsi = buffer
; rdx = count

ft_read:
    mov rax, 0
    syscall
    test rax, rax
    js .error
    ret

.error:
    mov rax, -1
    ret
