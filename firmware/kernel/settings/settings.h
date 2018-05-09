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
#include "../upp/fonte.h"
#include "../std.h"
#include "../drivers/lcd_simulator.h"
#include "../drivers/keyboard.h"
#include "../../hardware.h"
    
  
char lcdBuffer[504];
void Std_extend(void (*functionPtr)(char), char *str, va_list *arg_ptr);

#ifdef __cplusplus
}
#endif 

#endif