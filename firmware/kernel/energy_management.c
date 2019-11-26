/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "energy_management.h"

void EM_standbayLoop() {
    static unsigned char button;

    while (EM.timeStandbay && button == (Keyboard_getKeyDown() +
            (Keyboard_getKeyUp() << 1) +
            (Keyboard_getKeyEnter() << 2) +
            (Keyboard_getKeyEsc() << 3))) {
        CPU_standby();
        EM.timeStandbay--;
    }

    button = Keyboard_getKeyDown() +
            (Keyboard_getKeyUp() << 1) +
            (Keyboard_getKeyEnter() << 2) +
            (Keyboard_getKeyEsc() << 3);
}

void EM_standbayInitialize() {
    EM.timeStandbay = 0;
}