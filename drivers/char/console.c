/*************************************************************************
	> File Name: console.c
	> Author: GQB1226
	> Mail: gqb1226@gmail.com
	> Created Time: 2016年04月23日 星期六 10时35分38秒
    >屏幕的一些操作
 ************************************************************************/
 #include "common.h"
 #include "console.h"

 static uint16_t *video_memory =(uint16_t *)0xB8000;

 //光标坐标
 static uint8_t cursor_x=0;
 static uint8_t cursor_y=0;

 static void move_cursor()
 {
    uint16_t  cursor_location = cursor_y *80 +cursor_x;//x*80
    //以下基本是固定的
    outb(0x3D4,14);
    outb(0x3D5,cursor_location>>8);//高8位
    outb(0x3D4,15);
    outb(0x3D5,cursor_location);//低８位
 }


void console_clear()
{
    uint8_t attribute_byte =(0<<4)|(15& 0x0F);
    uint16_t blank = 0x20 | (attribute_byte << 8);

    int i;
    for(i=0;i<80*25;i++){
        video_memory[i]=blank;
    }
    cursor_x=0;
    cursor_y=0;
    move_cursor();
}
static void scroll()//屏幕滚动
{
    uint8_t attribute_byte =(0<<4)|(15&0x0F);
    uint16_t blank =0x20 |(attribute_byte <<8);
    if(cursor_y>=25){
        //这里显示器是80*25
        int i;
        for(i=0;i<24*80;i++){
            video_memory[i]=video_memory[i+80];
        }
        for(i=24*80;i<25*80;i++){
            video_memory[i]=blank;
        }
        cursor_y=24;
    }
}
void console_putc_color(int8_t c ,real_color_t back, real_color_t fore)
{
    uint8_t back_color =(uint8_t)back;
    uint8_t fore_color =(uint8_t)fore;

    uint8_t attribute_byte =(back_color<<4)|(fore_color&0x0F);
    uint16_t atttribute =attribute_byte <<8;

    if(c==0x08 && cursor_x){
        cursor_x--;//0x08是退格
    }
    else if (c==0x09){
        cursor_x=(cursor_x+8) &~ (8-1);//0x09是TAB
    }
    else if(c=='\r'){
        cursor_x=0;
    }
    else if(c=='\n'){
        cursor_x=0;
        cursor_y++;
    }
    else if(c>= ' '){
        video_memory[cursor_y*80 +cursor_x]=c|atttribute;
        cursor_x++;
    }
    if(cursor_x>=80){
        cursor_x=0;
        cursor_y++;
    }
    scroll();
    move_cursor();
}
void console_w(int8_t *c)
{
    while(*c){
        console_putc_color(*c++,rc_black,rc_white);
    }
}
void console_w_color(int8_t *c,real_color_t back,real_color_t fore)
{
    while(*c){
        console_putc_color(*c++,back,fore);
    }
}
