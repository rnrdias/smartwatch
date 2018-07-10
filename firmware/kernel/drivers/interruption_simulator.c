/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "interruption_simulator.h"

Util_eventHandle *INT_rootTimeMs;
Util_eventHandle *INT_rootButtonUp;
Util_eventHandle *INT_rootButtonDown;

void INT_register(Util_eventHandle *e, unsigned char i) {
    switch (i) {
        case INT_TIMER_MS:
            Util_registerEventHandler(&INT_rootTimeMs, e);
            break;
        case INT_BUTTON_UP:
            Util_registerEventHandler(&INT_rootButtonUp, e);
            break;
        case INT_BUTTON_DOWN:
            Util_registerEventHandler(&INT_rootButtonDown, e);
            break;
    }
}

void INT_unregister(Util_eventHandle *e, unsigned char i) {
    switch (i) {
        case INT_TIMER_MS:
            Util_unregisterEventHandler(&INT_rootTimeMs, e);
            break;
        case INT_BUTTON_UP:
            Util_unregisterEventHandler(&INT_rootButtonUp, e);
            break;
        case INT_BUTTON_DOWN:
            Util_unregisterEventHandler(&INT_rootButtonDown, e);
            break;
    }
}

void INT_processEventHandle(Util_eventHandle *e) {
    Util_eventHandle *aux = e;
    while (aux) {
        ((INT_eventData*) (aux->data))->function();
        aux = aux->next;
    }
}

void INT_coreTimerMS() {
    INT_timerMS();
    INT_processEventHandle(INT_rootTimeMs);
}

void INT_coreButtonUp() {
    INT_buttonUp();
    INT_processEventHandle(INT_rootButtonUp);
}

void INT_coreButtonDown() {
    INT_buttonDown();
    INT_processEventHandle(INT_rootButtonDown);
}

void INT_initialize(void) {
    INT_rootTimeMs = 0;
    INT_rootButtonUp = 0;
    INT_rootButtonDown = 0;
}