/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../interruption.h"
#include "../time_ms.h"
#include <avr/interrupt.h>

Util_list *Int_rootTimeMs;
Util_list *Int_rootButtonUp;
Util_list *Int_rootButtonDown;

void Int_register(Int_event *e, unsigned char i) {
    switch (i) {
        case INT_TIMER_MS:
            Util_listAdd(&Int_rootTimeMs, &e->item);
            break;
        case INT_BUTTON_UP:
            Util_listAdd(&Int_rootButtonUp, &e->item);
            break;
        case INT_BUTTON_DOWN:
            Util_listAdd(&Int_rootButtonDown, &e->item);
            break;
    }
}

void Int_unregister(Int_event *e, unsigned char i) {
    switch (i) {
        case INT_TIMER_MS:
            Util_listRemove(&Int_rootTimeMs, &e->item);
            break;
        case INT_BUTTON_UP:
            Util_listRemove(&Int_rootButtonUp, &e->item);
            break;
        case INT_BUTTON_DOWN:
            Util_listRemove(&Int_rootButtonDown, &e->item);
            break;
    }
}

void Int_processEventHandle(Util_list *e) {
    Int_event *aux = (Int_event *) e;
    while (aux) {
        if (aux->function)
            aux->function();
        aux = (Int_event *) aux->item.next;
    }
}

void Int_coreTimerMS() {
    if (TMS_interrupt()) {
        Int_timerMS();
        Int_processEventHandle(Int_rootTimeMs);
    }
}

void Int_coreButtonUp() {
    Int_buttonUp();
    Int_processEventHandle(Int_rootButtonUp);
}

void Int_coreButtonDown() {
    Int_buttonDown();
    Int_processEventHandle(Int_rootButtonDown);
}

ISR(TIMER2_OVF_vect) {
    Int_coreTimerMS();
}

ISR(INT0_vect) {
    Int_coreButtonUp();
}

ISR(INT1_vect) {
    Int_coreButtonDown();
}

void Int_initialize(void) {
    TMS_initialize_interruption();
    //intExt1 e intExt2
    EICRA = 0x0a;
    EIMSK = 0x03;

    Int_rootTimeMs = 0;
    Int_rootButtonUp = 0;
    Int_rootButtonDown = 0;
    sei(); //Global interrupção
}