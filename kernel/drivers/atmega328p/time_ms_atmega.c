/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time_ms.c
 * Author: rnr
 *
 * Created on 7 de Julho de 2018, 23:05
 */
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>

#include "../time_ms.h"
TMS_timeFormat TMS_cont;

void TMS_loadTime(TMS_timeFormat *time) {
    *time = *time + TMS_cont;
}

unsigned char TMS_checkTime(TMS_timeFormat *time) {
    if (*time > TMS_cont && (*time - TMS_cont) < 60000) {
        return 0;
    } else if (((signed long int) TMS_cont - *time) < 60000) {
        *time = TMS_cont;
        return 1;
    } else {
        return 0;
    }
}

void TMS_initialize_interruption(void) {
    TIMSK2 = 1;
    TMS = 0;
}

void TMS_initialize(void) {
    TMS = 0;
    TCCR2B = 1;
    TCNT2 = 255;
    TIFR2 = 0;
    ASSR = 0x20;
}

unsigned char TMS_interrupt(void) {
    static unsigned char acc = 0;
    static unsigned char TMS_pre = 0;

    if (++acc >= TMS_INT_SEC)
        acc = 0;
    TMS = (acc * 100) / TMS_INT_SEC;

    if (TMS != TMS_pre) {
        TMS_cont++;
        TMS_pre = TMS;
        return 1;
    }
    return 0;
}

void TMS_loop(void) {

}