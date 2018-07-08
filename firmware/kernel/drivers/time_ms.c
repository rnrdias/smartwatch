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

}

void TMS_loop(void) {
    if (++TMS_ms > 100) {
        TMS_ms = 0;
        TMS_process();
    }
}