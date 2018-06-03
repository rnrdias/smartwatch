/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

typedef struct {
    char *title;
    //char day;
    char month;
    int year;
    unsigned char scroll;
} Sc_calendarParam;

void Sc_calendarStart(Screen_windowLoad *this) {
    //this->title = Lang_load(&lang->calendar);
    Sc_calendarParam *p = Util_memPush(sizeof (Sc_calendarParam));
    p->title = (char*) RVCW(_LC(&lang->calendar));
    //p->day = RTC_date.day;
    p->month = RTC_date.month;
    p->year = RTC_date.year;
    p->scroll = 0;
    Screen_StartScroll(&p->scroll);
    this->parameters = p;
}

CONST char Sc_calendarScreen[] = "%w%r%s: %d/%d\r\n%wD S T Q Q S S\r\n%w";
Screen_windowLoad SC_calendarScLoad = {0, 0};
void Sc_calendarLoop(Screen_windowLoad *this) {
    //Util_memTop(this->parameters);
    Sc_calendarParam *p = this->parameters;
    Screen_StartScroll(&p->scroll);

    Std_printf(_LC(Sc_calendarScreen), &Font_alfanum_6, p->title, p->month, p->year, &Font_alfanum_8, &Font_alfanum_6);

    Std_printf("%o", p->scroll);
    for (char i = RTC_weekdayCalc(1, p->month, p->year); i > 0; i--) {
        Std_printf("   ");
    }
    for (int i = 1; i <= RTC_monthDay[p->month - 1]; i++) {
        if (i >= 10)
            Std_printf("%m%d%m ", 0, i, 0);
        else
            Std_printf("%m%d %m ", 0, i, 0);
    }


    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
    if (Keyboard_keyEnter()) {
        SC_calendarScLoad.windows = &Sc_calendarEvents;
        SC_calendarScLoad.parameters = p;
        Screen_windowOpen(&SC_calendarScLoad);
    }

    if (Keyboard_keyDown() && !UPP_scrollHasNext()) {
        p->month++;
        if (p->month > 12) {
            p->month = 1;
            p->year++;
        }
        p->scroll = 0;
    }

    if (Keyboard_keyUp() && !p->scroll) {
        p->month--;
        if (p->month == 0) {
            p->month = 12;
            p->year--;
        }
    }
    //RTC_dateValid(&p->date);
}

void Sc_calendarEnd(Screen_windowLoad *this) {
    Util_memTop(this->parameters);
}

Screen_window Sc_calendar = {0, Sc_calendarLoop, Sc_calendarStart, Sc_calendarEnd, 0, 0};