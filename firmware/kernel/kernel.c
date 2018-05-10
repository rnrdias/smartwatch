/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "kernel.h"

void Start_loop(void) {
    Keyboard_loop();
    Screen_loop();
    Hardware_loop();
}

void Start_inicialize(void) {
    Hardware_initialize();
    UPP_initialize();
    Std_initialize();
    Screen_initialize();
    LCD_Inicialize();
    Std_extends = Std_extend;
    UPP_fontDefault = &Font_alfanum_8;
}


