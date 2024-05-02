SECTION .text
global ft_strlen

ft_strlen:
    xor rax, rax

loop:
   cmp byte [rdi + rax], 0 ; check if we reached the end of the string 
    je end
    inc rax
    jmp loop

end:
    ret
