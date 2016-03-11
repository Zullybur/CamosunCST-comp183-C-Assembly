            segment     .data
MAX_CHARS:  equ 9                                   ; max chars allowed for string
NEWLINE:    equ 10                                  ; newline char
NULL:       equ 0                                   ; null entry
prompt      db "Enter the string",NEWLINE,NULL      ; prompt for input
PROMPT_LEN: equ $ - prompt - 1                      ; length of prompt
errorStr    db "String was truncated",NEWLINE,NULL  ; error string
ERR_LEN:    equ $ - errorStr - 1                    ; length of error

            segment     .bss
string      resb    9

            segment     .text
extern      getchar, putchar
global      main
main:
            mov edx, PROMPT_LEN                     ; prompt length
            mov ecx, prompt                         ; prompt
            mov ebx, 1                              ; stdout
            mov eax, 4                              ; sys_write
            int 0x80                                ; call kernel
            xor rbx, rbx                            ; set counter to 0
input:
            call getchar                            ; rax = getchar()
            cmp rax, NEWLINE                        ; check for end of terminal input
            je continue
            cmp rax, -1                             ; check for end of file
            je continue
            cmp rbx, MAX_CHARS                      ; check to see if max length reached
            je error
            mov [string + rbx], rax                 ; string[rbx] = getchar()
            inc rbx                                 ; rbx++
            jmp input                               ; goto input
error:
            mov edx, ERR_LEN                        ; prompt length
            mov ecx, errorStr                       ; prompt
            mov ebx, 1                              ; stdout
            mov eax, 4                              ; sys_write
            int 0x80                                ; call kernel
continue:
            mov r15, string                         ; r15 = a pointer to string
print:
            mov dil, [r15]                          ; rdi = next char
            cmp dil, NULL                           ; check for end of string
            je done
            call putchar                            ; output character
            inc r15
            jmp print
done:
            mov dil, NEWLINE                        ; move console to next line
            call putchar
            xor rax, rax                            ; set return status to 0
            ret