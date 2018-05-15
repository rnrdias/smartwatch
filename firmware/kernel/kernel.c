/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "kernel.h"
#include "drivers/real_time_clock.h"

void Start_loop(void) {
    Keyboard_loop();
    Screen_loop();
    Hardware_loop();
    RTC_loop();
    RTC_date.second++;
}

void Start_inicialize(void) {
    Hardware_initialize();
    UPP_initialize();
    Std_initialize();
    Screen_initialize();
    LCD_inicialize();
    Std_extends = Std_extend;
    UPP_fontDefault = &Font_alfanum_8;
    RTC_initialize();
}


