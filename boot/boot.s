;boot.s
;以下定义是根据Multiboot 规范而定义
MBOOT_HEADER_MAGIC      equ     0x1BADB002

MBOOT_PAGE_ALIGN        equ     1<<0

MBOOT_MEM_INFO          equ     1<<1

MBOOT_HEADER_FLAGS      equ     MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO

MBOOT_CHECKSUM          equ     -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[BITS 32]
section .text

dd MBOOT_HEADER_MAGIC       ;0
dd MBOOT_HEADER_FLAGS       ;4
dd MBOOT_CHECKSUM           ;8

[GLOBAL start]              ;此处提供的声明供链接器使用
[GLOBAL glb_mboot_ptr]
[EXTERN kern_entry]         ;内核c　代码入口函数

start:
    cli

    mov esp, STACK_TOP
    mov ebp, 0
    and esp, 0FFFFFFF0H
    mov [glb_mboot_ptr], ebx
    call kern_entry

stop:
    hlt
    jmp stop


section .bss
stack:
    resb 32768
glb_mboot_ptr:
    resb 4

STACK_TOP               equ     $-stack-1
