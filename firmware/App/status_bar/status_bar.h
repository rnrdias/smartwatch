/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 8 de Maio de 2018, 11:24
 */

#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../kernel/upp/upp.h"

#define STATUS_BAR_HEAD 6,1,0,1

    typedef struct _StatusBar_paramFormat {
        const UPP_BitmapFormat *icon;
        const char *title;
        const char *description;
        const char *function;
    } StatusBar_paramFormat;

    typedef struct _StatusBar_registerFormat {
        const StatusBar_paramFormat *(*functionRegister)(void);
        struct _StatusBar_registerFormat *p;
    } StatusBar_registerFormat;

    void StatusBar_register(StatusBar_registerFormat *r);
    void StatusBar_initialize();
    void StatusBar_print();
    void StatusBar_check(void (*functionPtr)(const StatusBar_paramFormat *s));

#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

