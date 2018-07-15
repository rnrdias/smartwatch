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
#include "../kernel/mem.h"
#include "../kernel/drivers/time_ms.h"
#include "../kernel/drivers/real_time_clock.h"
#include "../kernel/screen/screen.h"
#include "../kernel/fonts/fonts.h"
#include "../kernel/drivers/keyboard.h"
#include "../kernel/std.h"
#include "../language/language.h"
#include "../kernel/drivers/beep.h"

    extern Screen_window Sc_main;
    extern Screen_window Sc_status;
    extern Screen_window Sc_menu;
    extern Screen_window Sc_alarms;
    extern Screen_window Sc_calendar;
    extern Screen_window Sc_settings;
    extern Screen_window Sc_stopwatch;
    extern Screen_window Sc_calendarEvents;
    extern Screen_window Sc_alarmsSettings;
    extern Screen_window Sc_settingsDateHour;
    extern Screen_window Sc_alarmsRinging;


#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

