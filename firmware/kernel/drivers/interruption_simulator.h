/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interruption.h
 * Author: rnr
 *
 * Created on 8 de Julho de 2018, 15:40
 */

#ifndef INTERRUPTION_H
#define INTERRUPTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../util.h"
#define INT_TIMER_MS 1
#define INT_BUTTON_UP 2
#define INT_BUTTON_DOWN 3

    typedef struct {
        void (*function)(void);
    } INT_eventData;

    extern void INT_timerMS(void);
    extern void INT_buttonUp(void);
    extern void INT_buttonDown(void);

    void INT_initialize(void);
    void INT_register(Util_eventHandle *e, unsigned char i);
    void INT_unregister(Util_eventHandle *e, unsigned char i);
#ifdef __cplusplus
}
#endif

#endif /* INTERRUPTION_H */

