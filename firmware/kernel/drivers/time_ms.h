/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time_ms.h
 * Author: rnr
 *
 * Created on 7 de Julho de 2018, 23:05
 */

#ifndef TIME_MS_H
#define TIME_MS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "interruption.h"
#define TMS_INT_SEC 128
    unsigned char TMS;
    void TMS_initialize(void);
    void TMS_loop(void);
    void TMS_initialize_interruption(void);
    void TMS_interrupt(void);

    /*typedef struct{
        unsigned long int time;
    }TMS_timeFormat;*/
    
    typedef unsigned int TMS_timeFormat;
    void TMS_loadTime(TMS_timeFormat *time);
    unsigned char TMS_checkTime(TMS_timeFormat *time);
#ifdef __cplusplus
}
#endif

#endif /* TIME_MS_H */

