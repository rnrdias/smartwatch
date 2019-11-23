/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <avr/power.h>
#include "../beep.h"
#include "../interruption.h"


Beep_paramFormat Beep_core;

char beep_onNoff = 0;

void Beep_on() {
    if (!beep_onNoff) {
        beep_onNoff = 1;
        SMCR = 0x01; // //CPU Sleep
        TCCR0A = 0x33;
        TCCR0B = 0x0b;

        OCR0A = 12500 / (Beep_core.frequency / 10);
        OCR0B = OCR0A / 2;
        DDRD |= (1 << PD5);
    }
}

void Beep_off() {
    if (beep_onNoff) {
        beep_onNoff = 0;
        SMCR = 0x07; //CPU Sleep
        DDRD &= ~(1 << PD5);
        PORTD &= ~(1 << PD5);
    }
}

void Beep_intTimerMS() {
    if (Beep_param) {
        if (Beep_core.masterRepeat == 255) {
            Beep_core = *Beep_param;
        }

        if (Beep_core.masterRepeat) {
            if (Beep_core.repeat) {
                if (Beep_core.frequencyDelay) {
                    Beep_core.frequencyDelay--;
                    Beep_on();
                } else if (Beep_core.repeatDelay) {
                    Beep_core.repeatDelay--;
                    Beep_off();
                } else {
                    Beep_core.repeat--;
                    Beep_core.frequencyDelay = Beep_param->frequencyDelay;
                    Beep_core.repeatDelay = Beep_param->repeatDelay;
                }
            } else if (Beep_core.masterRepeatDelay) {
                Beep_core.masterRepeatDelay--;
                Beep_off();
            } else {
                Beep_core.masterRepeat--;
                Beep_core.repeat = Beep_param->repeat;
                Beep_core.masterRepeatDelay = Beep_param->masterRepeatDelay;
            }
        } else {
            Beep_param = 0;
        }
    } else {
        Beep_core.masterRepeat = 255;
        Beep_off();
    }
}

Int_event Beep_IntEventTimerMS = {0, Beep_intTimerMS};

void Beep_loop(void) {

}

void Beep_initialize(void) {
    Beep_param = 0;
    Int_register(&Beep_IntEventTimerMS, INT_TIMER_MS);
}