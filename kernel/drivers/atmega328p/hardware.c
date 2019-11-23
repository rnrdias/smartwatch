/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../hardware.h"
#include <avr/io.h>

void Hardware_loop(void) {
    
}

void Hardware_initialize(void) {
    DDRB = 0x03;
    DDRD = 0xc0;
    PORTD = 0xff;
    PORTC = 0xff;
    PORTB = 0xff;
}