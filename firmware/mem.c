/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "mem.h"

extern char mem[MEM_MAX];

void Mem_loop(void) {
    Beep->frequency = 2000;
    Alarms->hour = 0;
    Alarms->minute = 0;
    Alarms[1].hour = 25;
}

void Mem_initialize(void) {
    for (int i = 0; i < MEM_MAX; i++) {
        mem[i] = 0;
    }
}