/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 11:12
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif


#include "../screen/screen.h"
#include "../upp/upp.h"
#include "../fonts/fonts.h"
#include "../std.h"
#include "../drivers/lcd.h"
#include "../drivers/keyboard.h"
#include "../../hardware.h"
#include "../drivers/time_ms.h" 
#include "../drivers/real_time_clock.h"
#include "../drivers/beep.h"
#include "../mem.h"
    
    
    char lcdBuffer[504];
    void Std_extend(void (*functionPtr)(char), const char *str, va_list *arg_ptr);


    void App_INT_buttonUp(void);
    void APP_INT_buttonDown(void);
    void APP_INT_timerMS(void);

#ifdef __cplusplus
}
#endif 

#endif