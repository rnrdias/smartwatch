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

#include "time_ms.h"

void TMS_initialize(void) {
    TMS = 0;
}

void TMS_interrupt(void) {
    static unsigned char acc = 0;
    if (++acc >= TMS_INT_SEC)
        acc = 0;
    TMS = (acc * 100) / TMS_INT_SEC;
}