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

#ifndef NOTEPAD_H
#define NOTEPAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "screen.h"
#include "../drivers/keyboard.h"
#include "../std.h"
#include "../util.h"

    typedef struct {
        //char *title;
        char *data;
        unsigned char *scroll;
    } Sc_notepadParam;

    extern Screen_window Sc_notepad;



#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

