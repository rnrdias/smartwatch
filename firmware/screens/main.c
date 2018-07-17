/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../app/status_bar/status_bar.h"
#include "../kernel/drivers/lcd.h"

CONST char dsHour[] = "%w%1d:%1d%w\n\n%1d\r\n";
CONST char dsDate[] = "%s %1d-%1d-%3d";

void Sc_mainPrintIcon(const StatusBar_paramFormat *s, void *parameter) {
    Std_printf("%w%c", (char*) RVCW(&s->icon), 0);
    *(void **) parameter = (StatusBar_paramFormat *) s;
}

void Sc_mainLoop(Screen_windowLoad *this) {
    StatusBar_paramFormat *SB_last = 0;
    static TMS_timeFormat t;
    static StatusBar_paramFormat *SB_lastPre = 0;

    char *weekday = (char *) (&lang->sunday + RTC_getWeekday());
    weekday = (char *) RVCW(weekday);
    Std_printf("%r");
    StatusBar_check(Sc_mainPrintIcon, &SB_last);
    UPP_setCursorXY(1, 1);
    Std_printf(_LC(dsHour), &Font_numeric_24, RTC_date.hour, RTC_date.minute, &Font_alfanum_8, RTC_date.second);
    Std_printf(_LC(dsDate), weekday, RTC_date.day, RTC_date.month, RTC_date.year);

    if (SB_last != SB_lastPre) {
        t = 3000;
        TMS_loadTime(&t);
        SB_lastPre = SB_last;
    } else if (SB_last && !TMS_checkTime(&t)) {
        Std_printf("%w%c%w%s", RVCW(&SB_last->icon), 0, &Font_alfanum_8, (char*) RVCW(&SB_last->title));
    }

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