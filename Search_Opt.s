global SearchByValue
extern strcmp

section .text

SearchByValue:
       push r13
       push r12
       push r15
       push rbx
       mov     rcx, 1000
       mov     r13, rdi
  .Around:
         mov     r12, QWORD  [r13+8]
         mov     r15, QWORD  [r13]
         xor     ebx, ebx
      .Inside:
             cmp     rbx, r12
             ja     .AroundNext
             mov     rdi, QWORD  [r15]
             test    rdi, rdi
             je      .InsideNext
             call    strcmp
             test    eax, eax
             je      .Found
      .InsideNext:
             inc     rbx
             add     r15, 16
             jmp .Inside
  .AroundNext:
         add     r13, 40
         dec     rcx
         test    ecx, ecx
         jne     .Around
         xor     rax, rax
.EXX:
         pop rbx
         pop r15
         pop r12
         pop r13
         ret
.Found:
       mov     rax, 1
       jmp .EXX
