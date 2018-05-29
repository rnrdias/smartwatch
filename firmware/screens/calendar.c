/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

typedef struct {
    char *title;
    RTC_DateFormat date;
    unsigned char scroll;
} Sc_calendarParam;

void Sc_calendarStart(Screen_window *this) {
    //this->title = Lang_load(&lang->calendar);
    Sc_calendarParam *p = Util_memPush(sizeof (Sc_calendarParam));
    p->title = Lang_load(&lang->calendar);
    p->date.day = RTC_date.day;
    p->date.month = RTC_date.month;
    p->date.year = RTC_date.year;
    Screen_StartScroll(&p->scroll);
    this->parameters = p;
}

void Sc_calendarLoop(Screen_window *this) {
    //Util_memTop(this->parameters);
    Sc_calendarParam *p = this->parameters;
    Screen_StartScroll(&p->scroll);

    Std_printf("%w%r%s: %d/%d\r\n%wD S T Q Q S S\r\n%w", &Font_alfanum_6, p->title, p->date.month, p->date.year, &Font_alfanum_8, &Font_alfanum_6);

    Std_printf("%o", p->scroll);
    for (char i = RTC_weekdayCalc(1, p->date.month, p->date.year); i > 0; i--) {
        Std_printf("   ");
    }
    for (int i = 1; i <= RTC_monthDay[p->date.month - 1]; i++) {
        if (i >= 10)
            Std_printf("%m%d%m ", 0, i, 0);
        else
            Std_printf("%m%d %m ", 1, i, 0);
    }


    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
    if (Keyboard_keyEnter()) {
        Screen_windowOpen(&Sc_calendarEvents);
    }

    if (Keyboard_keyDown() && !UPP_scrollHasNext()) {
        p->date.month++;
        p->scroll = 0;
    }

    if (Keyboard_keyUp() && !p->scroll) {
        p->date.month--;
        if (p->date.month == 0) {
            p->date.month = 12;
            p->date.year--;
        }
    }
    RTC_dateValid(&p->date);
}

void Sc_calendarEnd(Screen_window *this) {
    Util_memTop(this->parameters);
}

Screen_window Sc_calendar = {0, Sc_calendarLoop, Sc_calendarStart, Sc_calendarEnd, 0, 0};