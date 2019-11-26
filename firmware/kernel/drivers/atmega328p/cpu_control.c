/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <avr/sleep.h>
#include "../cpu_control.h"

void CPU_standby(void) {

    sleep_cpu();
}

void CPU_initialize() {
    SMCR = 0x07;
    MCUCR = (1 << BODS) | (1 << BODSE);
    PRR = (1 << PRTWI) | (0 << PRTIM0) | (1 << PRTIM1) | (1 << PRSPI);
}