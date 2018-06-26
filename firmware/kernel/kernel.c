/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "kernel.h"

Beep_paramFormat param = {2000, 250, 1, 0, 1, 0};

void Start_loop(void) {
    Keyboard_loop();
    Hardware_loop();
    Beep_loop();
    RTC_date.second++;
    RTC_loop();
    Screen_loop();
    if (Keyboard_keyDown() || Keyboard_getKeyEnter() || Keyboard_getKeyEsc() || Keyboard_getKeyUp()) {
        Beep_param = &param;
        param.repeat = 1;
    }
}

void Start_initialize(void) {
    Hardware_initialize();
    LCD_initialize();
    UPP_initialize();
    Std_initialize();
    Screen_initialize();
    Std_extends = Std_extend;
    UPP_fontDefault = &Font_alfanum_8;
    RTC_initialize();
    Beep_initialize();
}


