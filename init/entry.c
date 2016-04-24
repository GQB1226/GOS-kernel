/*************************************************************************
	> File Name: entry.c
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
	> Created Time: 2016年04月23日 星期六 09时24分56秒
 ************************************************************************/
#include "console.h"
int kern_entry()
{
    console_clear();
    console_w_color("Hello, GOS!\n",rc_black,rc_green);
    return 0;
}


/*#include"types.h"

int kern_entry()
{
    uint8_t *input = (uint8_t *)0xB8000;
    uint8_t color = (0<<4) | (15 &0x0F);

    *input++ ='H';*input++ =color;
    *input++ ='e';*input++ =color;
    *input++ ='l';*input++ =color;
    *input++ ='l';*input++ =color;
    *input++ ='o';*input++ =color;
    *input++ =',';*input++ =color;
    *input++ =' ';*input++ =color;
    *input++ ='G';*input++ =color;
    *input++ ='O';*input++ =color;
    *input++ ='S';*input++ =color;
    return 0;
}*/
