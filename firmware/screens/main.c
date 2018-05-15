/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_mainBody(Screen_window *this) {
    char *weekday = Lang_load(&lang->sunday + RTC_getWeekday());

    Std_printf("%r\n");
    UPP_setCursorXY(5, 1);
    Std_printf("%w%1d:%1d%w\n%1d\r\n", &Font_numeric_16, RTC_date.hour, RTC_date.minute, &Font_alfanum_8, RTC_date.second);
    Std_printf("%s %1d-%1d-%3d", weekday, RTC_date.day, RTC_date.month, RTC_date.year);
    Std_printf("%s", "info");
    Util_memTop(weekday);

    if (Keyboard_keyEnter()) {
        Screen_windowOpen(&Sc_menu);
    }

    if (Keyboard_keyEsc()) {
        Screen_windowOpen(&Sc_status);
    }
}
Screen_window Sc_main = {0, Sc_mainBody, 0, 0};