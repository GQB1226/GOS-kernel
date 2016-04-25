/*************************************************************************
	> File Name: gdt.c
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
        > gdt实现
	> Created Time: 2016年04月25日 星期一 13时32分34秒
 ************************************************************************/
#include "gdt.h"
#include "string.h"

#define GDT_LENGTH 5

gdt gdt_t[GDT_LENGTH];
gdtr gdtr_t;

static void gdt_set_gate(int32_t num, uint32_t base,uint32_t limit,uint8_t access, uint8_t gran);
extern uint32_t stack;//内核栈地址

void init_gdt()
{
    gdtr_t.limit=sizeof(gdt)*GDT_LENGTH-1;
    gdtr_t.base= (uint32_t)&gdt_t;

    gdt_set_gate(0,0,0,0,0);
    gdt_set_gate(1,0,0xFFFFFFFF,0x9A,0xCF);
    gdt_set_gate(2,0,0xFFFFFFFF,0x92,0xCF);
    gdt_set_gate(3,0,0xFFFFFFFF,0xFA,0xCF);
    gdt_set_gate(4,0,0xFFFFFFFF,0xF2,0xCF);
    gdt_flush((uint32_t)&gdtr_t);

}

static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt_t[num].base_low     = (base & 0xFFFF);
    gdt_t[num].base_mid  = (base >> 16) & 0xFF;
    gdt_t[num].base_high    = (base >> 24) & 0xFF;

    gdt_t[num].limit_low    = (limit & 0xFFFF);
    gdt_t[num].granularity  = (limit >> 16) & 0x0F;

    gdt_t[num].granularity |= gran & 0xF0;
    gdt_t[num].access       = access;

}
