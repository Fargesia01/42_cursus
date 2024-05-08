global ft_strdup

extern malloc, ft_strlen, ft_strcpy

; rdi = char *src

ft_strdup:
    call ft_strlen      ; rax = strlen(src)
    add rax, 1          ; rax = strlen(src) + 1
    push rdi            ; save src
    mov rdi, rax        ; rdi = strlen(src)
    call malloc         ; rax = malloc(strlen(src))
    test rax, rax       ; if (rax == NULL)
    jz .error_malloc    ; return NULL
    mov rdi, rax        ; rdi = malloc(strlen(src))
    pop rsi             ; rsi = src
    call ft_strcpy      ; strcpy(rdi, rsi)
    ret                 ; return rdi

.error_malloc:
    ret
