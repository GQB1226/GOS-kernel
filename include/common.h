/*************************************************************************
	> File Name: common.h
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
	> Created Time: 2016年04月23日 星期六 10时04分13秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include "types.h"
void outb(uint16_t port,uint8_t value);
uint8_t rb(uint16_t port);
uint16_t rw(uint16_t port);


#endif
