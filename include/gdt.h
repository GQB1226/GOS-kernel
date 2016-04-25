/*************************************************************************
	> File Name: gdt.h
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
    > GDT 
	> Created Time: 2016年04月25日 星期一 13时24分17秒
 ************************************************************************/

#ifndef _GDT_H
#define _GDT_H

#include "types.h"

typedef struct gdt{
    uint16_t limit_low;//段限界
    uint16_t base_low;//段基址　15~0
    uint8_t base_mid;//段基址　23~16
    uint8_t access;//属性等
    uint8_t granularity;//其他标志
    uint8_t base_high;//段基址　31~24
}__attribute__((packed)) gdt;

typedef struct gdtr{
    uint16_t limit;//GDT 限长
    uint32_t base;//32bit base 
}__attribute__((packed)) gdtr;

void init_gdt();
extern void gdt_flush(uint32_t);

#endif
