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
#include "../../kernel/std.h"
#include "../../kernel/upp/upp.h"
#include "../../kernel/util.h"

#define STATUS_BAR_HEAD 0x06,0x01,0x00,0x01,

    typedef struct _StatusBar_paramFormat {
        const UPP_BitmapFormat *icon;
        const char *title;
        void (*function)(void);
    } StatusBar_paramFormat;

    typedef struct _StatusBar_registerFormat {
        Util_list item;
        const StatusBar_paramFormat *data;
    } StatusBar_registerFormat;
    
    void StatusBar_register(StatusBar_registerFormat *r);
    void StatusBar_unregister(StatusBar_registerFormat *r);
    void StatusBar_initialize();
    void StatusBar_check(void (*functionPtr)(const StatusBar_paramFormat *s, void *parameter), void *parameter);
    unsigned char StatusBar_size(void);
#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

