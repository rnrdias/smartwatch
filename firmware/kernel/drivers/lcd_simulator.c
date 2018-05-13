/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "lcd_simulator.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
        printf("\n");
    }

    //printf("%d%d%d%d\n\n", BA, BB, BC, BD);
}

void LCD_inicialize(void) {
    gotoxy(0, 0);
}