/*************************************************************************
	> File Name: string.h
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
    > 自己定义的内核字符串函数
	> Created Time: 2016年04月24日 星期日 10时36分50秒
 ************************************************************************/

#ifndef _STRING_H
#define _STRING_H
#include "types.h"
void *memcpy(void *dest, const void  *src, uint32_t len);
void memset(void *dest, uint8_t val, uint32_t len);
void bzero(void *dest,uint32_t len);
uint32_t strcmp(const uint8_t *str1, const uint8_t *str2);
uint8_t *strcp(uint8_t *dest,const uint8_t *src);
uint8_t *strcat(uint8_t *dest,const uint8_t *src);
uint32_t strlen(const uint8_t *src);


#endif

