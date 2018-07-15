/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../app/status_bar/status_bar.h"

CONST char dsHour[] = "%w%1d:%1d%w\n%1d\r\n";
CONST char dsDate[] = "%s %1d-%1d-%3d";

void Sc_mainLoop(Screen_windowLoad *this) {
    char *weekday = (char *) (&lang->sunday + RTC_getWeekday());
    weekday = (char *) RVCW(weekday);
    Std_printf("%r");
    StatusBar_print();
    UPP_setCursorXY(5, 1);
    Std_printf(_LC(dsHour), &Font_numeric_16, RTC_date.hour, RTC_date.minute, &Font_alfanum_8, RTC_date.second);
    Std_printf(_LC(dsDate), weekday, RTC_date.day, RTC_date.month, RTC_date.year);
    Std_printf("%s", "info");


    if (Keyboard_keyEnter()) {
        Screen_windowLoad scLoad;
        scLoad.parameters = 0;
        scLoad.windows = &Sc_menu;
        Screen_windowOpen(&scLoad);
    }

    if (Keyboard_keyEsc()) {
        Screen_windowLoad scLoad;
        scLoad.parameters = 0;
        scLoad.windows = &Sc_status;
        Screen_windowOpen(&scLoad);
    }
}
Screen_window Sc_main = {0, Sc_mainLoop, 0, 0, 0, 0};