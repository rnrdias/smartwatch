/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "../lcd.h"
#include "../../util.h"

#define lcdResetPuse() LCD_pinSnRest(1);LCD_pinSnRest(0)
#define lcdComand() LCD_pinSDnC(0)
#define lcdDad() LCD_pinSDnC(1)

void LCD_pinSClk(char val);
void LCD_pinSDad(char val);
void LCD_pinSDnC(char val);
void LCD_pinSnRest(char val);

void lcdEnvia(unsigned char dado) {
    for (char i = 0; i < 8; i++) {
        LCD_pinSClk(0);
        LCD_pinSDad(dado >> 7);
        dado <<= 1;
        LCD_pinSClk(1);
    }
}

void LCD_setContrast(unsigned char value) {
    if (value >= 100)
        value = 100;
    unsigned char contrast = ((70 - 50) * value) / 100 + 50;
    lcdComand();
    lcdEnvia(0x21);
    lcdEnvia(0x80 | contrast);
    lcdEnvia(0x20);
}

void LCD_setPowerdown(unsigned char value) {
    lcdComand();
    if (value)
        lcdEnvia(0x24);
    else {
        lcdEnvia(0x20);
    }
}

void LCD_loop(void) {
    static unsigned char brightness, powerdown;

    if (brightness != LCD.contrast) {
        LCD_setContrast(LCD.contrast);
        brightness = LCD.contrast;
    }

    if (powerdown != LCD.powerdown) {
        LCD_setPowerdown(LCD.powerdown);
        powerdown = LCD.powerdown;
    }
}


CONST unsigned char lcdControleInicio[] = {
    0x21, 0xc6, 0x02, 0x13, 0x20, 0x0c
};

void LCD_initialize() {
    //condicao inicial
    LCD_pinSClk(1);
    LCD_pinSDad(1);
    LCD_pinSDnC(1);
    LCD_pinSnRest(1);

    //inicializando
    lcdResetPuse();
    lcdComand();

    for (unsigned char i = 0; i < 6; i++) {
        lcdEnvia(RCB(&lcdControleInicio[i]));
    }

    LCD.contrast = 50;
    LCD.powerdown = 0;
}

void LCD_sendBuffer(char *buffer) {
    unsigned int index = 0;

    lcdComand();
    lcdEnvia(0x40);
    lcdEnvia(0x80);

    lcdDad();
    while (index++ < (84 * 6))
        lcdEnvia(*buffer++);

}
