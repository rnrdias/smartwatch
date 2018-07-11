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

#include "time_ms_simulator.h"

void TMS_initialize(void) {
    TMS_ACC = 0;
}

void TMS_loop(void) {
    //TMS_ms = (INT_ACC * 100) / 128;
    if (++TMS_ACC > 127)
        TMS_ACC = 0;
    Int_coreTimerMS();
}