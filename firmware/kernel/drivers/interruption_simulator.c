/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "interruption_simulator.h"

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
    Int_timerMS();
    Int_processEventHandle(Int_rootTimeMs);
}

void Int_coreButtonUp() {
    Int_buttonUp();
    Int_processEventHandle(Int_rootButtonUp);
}

void Int_coreButtonDown() {
    Int_buttonDown();
    Int_processEventHandle(Int_rootButtonDown);
}

void Int_initialize(void) {
    Int_rootTimeMs = 0;
    Int_rootButtonUp = 0;
    Int_rootButtonDown = 0;
}