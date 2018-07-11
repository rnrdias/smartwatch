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
        Util_list item;
        void (*function)(void);
    } Int_event;

    extern void Int_timerMS(void);
    extern void Int_buttonUp(void);
    extern void Int_buttonDown(void);

    void Int_initialize(void);
    void Int_register(Int_event *e, unsigned char i);
    void Int_unregister(Int_event *e, unsigned char i);
#ifdef __cplusplus
}
#endif

#endif /* INTERRUPTION_H */

