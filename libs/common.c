/*************************************************************************
	> File Name: common.c
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
	> Created Time: 2016年04月23日 星期六 09时58分17秒
    > define some function to r/w port
 ************************************************************************/
#include "common.h"
//wB
inline void outb(uint16_t port, uint8_t value)
{
    asm volatile("outb %1, %0": : "dN"(port),"a"(value));
}
//rB
inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1,%0": "=a"(ret):"dN"(port));
    return ret;
}
inline uint16_t inw(uint16_t port)
{
    uint16_t ret;
    asm volatile("inw %1,%0": "=a"(ret):"dN"(port));
    return ret;
}
