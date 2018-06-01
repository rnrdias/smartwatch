/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 11:06
 */

#include "settings.h"

void Std_out(char val) {
    UPP_loadTextChar(val);
}

void Std_extend(void (*functionPtr)(char),const char *str, va_list *arg_ptr) {
    UPP_Std_Extends(functionPtr, str, arg_ptr);
    Screen_Std_Extends(functionPtr, str, arg_ptr);
}
