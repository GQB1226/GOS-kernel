/*************************************************************************
	> File Name: string.c
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
    > 自己定义的几个内核字符串处理函数
	> Created Time: 2016年04月24日 星期日 10时42分07秒
 ************************************************************************/
#include "string.h"

inline void *memcpy(void *dest, const void *src,uint32_t len)
{
    if(dest==NULL || src==NULL){
        return NULL;
    }
    uint8_t *tmpD=(uint8_t *)dest;
    uint8_t *tmpS=(uint8_t *)src;
    for(;len!=0;len--){
        *tmpD++ = *tmpS++;
    }
    return tmpD;
}
inline void memset(void *dest, uint8_t val, uint32_t len)
{
    uint8_t *dst=(uint8_t *)dest;
    for(;len!=0;len--){
        *dst++=val;
    }
}
inline void bzero(void *dest,uint32_t len)
{
    memset(dest,0,len);
}
inline uint32_t strlen(const uint8_t *str)
{
    uint32_t tmp=0;
    while(*str++!='\0'){
        tmp++;
    }
    return tmp;
}
inline uint32_t strcmp(const uint8_t *str1,const uint8_t *str2)
{
    while((*str1==*str2)&&*str1&&str2)
    {
        str1++;
        str2++;
    }
    return *str1-*str2;
}
inline uint8_t *strcp(uint8_t *dest, const uint8_t *src)
{
    uint8_t *tmp=dest;
    if(src==NULL)
        return 0;
    while(*src){
        *dest++=*src++;
    }
    *dest='\0';
    return tmp;
}

inline uint8_t *strcat(uint8_t *dest,const uint8_t *src)
{
    uint8_t *tmp=dest;
    while(*dest++);
    while(*dest++=*src++);
    return tmp;
}

