/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../lcd.h"

#include <stdio.h>
//#include <conio.h>
//#include <windows.h>

void gotoxy(int x, int y) {
    //to windows
    /*  COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);*/

    //to linux
    printf("%c[%d;%df", 0x1B, y, x);
}

#define displayWidth() 84
#define displayHeight() 6

void LCD_sendBuffer(char *buffer) {
    //unsigned int i = UPP_getDisplayHeight() * UPP_getDisplayWidth() * 8;
    unsigned int y = displayHeight();
    unsigned int x = displayWidth();
    unsigned int bit = 0;
    unsigned int col = 0;

    //printf("\e[H\e[2J");
    //system("cls");
    gotoxy(0, 0);


    while (y) {
        do {
            //imprimindo bit
            if (buffer[(displayWidth() - x)+(displayHeight() - y) * displayWidth()]&(1 << bit))
                printf("00");
            else
                printf("  ");
        } while (--x);
        x = displayWidth();
        if (++bit >= 8) {
            bit = 0;
            y--;
        }
        printf("\r\n");
    }

    //printf("%d%d%d%d\n\n", BA, BB, BC, BD);
}


void LCD_setContrast(unsigned char value) {
    
}

void LCD_loop(void) {
    static unsigned char brightness;

    if (brightness != LCD.contrast) {
        LCD_setContrast(LCD.contrast);
        brightness = LCD.contrast;
    }
}

void LCD_initialize(void) {
    LCD.contrast = 60;
    gotoxy(0, 0);
}