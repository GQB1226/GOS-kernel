/*************************************************************************
	> File Name: console.h
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
	> Created Time: 2016年04月23日 星期六 10时12分20秒
 ************************************************************************/

#ifndef _CONSOLE_H
#define _CONSOLE_H
#include "types.h"

typedef
enum real_color{
    rc_black=0,
    rc_blue=1,
    rc_green=2,
    rc_cyan=3,
    rc_red=4,
    rc_magenta=5,
    rc_brown =6,
    rc_light_grey =7,
    rc_dark_grey =8,
    rc_light_blue=9,
    rc_light_green=10,
    rc_light_cyan=11,
    rc_light_red=12,
    rc_light_magent=13,
    rc_yellow=14,
    rc_white=15
} real_color_t;
void console_clear();
void console_putc_color(int8_t c,real_color_t back,real_color_t fore);

void console_w(int8_t *c);
void console_w_color(int8_t *c,real_color_t back,real_color_t fore);

void console_w_hex(uint32_t n,real_color_t back,real_color_t fore);
void console_w_dec(uint32_t n,real_color_t back,real_color_t fore);

#endif
