/*
 * lcd_nokia_5110.c
 *
 * Created: 09/05/2018 22:07:38
 *  Author: RNR
 */

#include "../settings.h"

void LCD_pinSClk(char val) {
    if (val)
        PORTD |= (1 << PIND6);
    else
        PORTD &= ~(1 << PIND6);
}

void LCD_pinSDad(char val) {
    if (val)
        PORTD |= (1 << PIND7);
    else
        PORTD &= ~(1 << PIND7);
}

void LCD_pinSDnC(char val) {
    if (val)
        PORTB |= (1 << PINB0);
    else
        PORTB &= ~(1 << PINB0);
}

void LCD_pinSnRest(char val) {
    if (val)
        PORTB &= ~(1 << PINB1);
    else
        PORTB |= (1 << PINB1);
}