section .data
    hello db 'Hello, World!', 0  ; The string to print, null-terminated

section .text
    extern  GetStdHandle, WriteFile, ExitProcess
    global  main

main:
    ; Get the handle for standard output (stdout)
    sub     rsp, 28h             ; Allocate space for shadow store (32 bytes)
    mov     ecx, -11             ; STD_OUTPUT_HANDLE
    call    GetStdHandle
    mov     r12, rax             ; Save handle to r12

    ; Write the string to stdout
    mov     rcx, r12             ; Handle
    lea     rdx, [hello]         ; Buffer
    mov     r8d, 13              ; Number of bytes to write (length of "Hello, World!")
    lea     r9, [rsp+20h]        ; Address of variable to receive number of bytes written
    call    WriteFile

    ; Exit the program
    xor     ecx, ecx             ; Exit code 0
    call    ExitProcess
