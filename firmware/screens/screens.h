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

#ifndef SCREENS_H
#define SCREENS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../kernel/drivers/real_time_clock.h"
#include "../kernel/screen/screen.h"
#include "../kernel/screen/notepad.h"
#include "../kernel/fonts/fonts.h"
#include "../kernel/drivers/keyboard.h"
#include "../kernel/std.h"
#include "../language/language.h"
#include "../kernel/drivers/beep_simulator.h"

    extern Screen_window Sc_main;
    extern Screen_window Sc_status;
    /*Screen_window Sc_menu;
    Screen_window Sc_alarms;
    Screen_window Sc_calendar;
    Screen_window Sc_settings;
    Screen_window Sc_stopwatch;
    Screen_window Sc_calendarEvents;
    Screen_window Sc_alarmsSettings;
    Screen_window Sc_settingsDateHour;
    Screen_window Sc_alarmsRinging;*/


#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

