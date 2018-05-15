/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

typedef struct {
    Screen_numberEditFormat hour;
    Screen_numberEditFormat minute;
    //Screen_numberEditFormat second;
    Screen_numberEditFormat day;
    Screen_numberEditFormat month;
    Screen_numberEditFormat year;
} SC_settingsDateHourParam;

void Sc_settingsDateHourStart(Screen_window *this) {
    this->title = Lang_load(&lang->settingsDateHour);
    SC_settingsDateHourParam *p = Util_memPush(sizeof (SC_settingsDateHourParam));
    p->hour.numInc = 1;
    p->hour.numMax = 23;
    p->hour.numMin = 0;
    p->hour.numVar = (long *) &RTC_date.hour;
    p->hour.editRun = 0;
    p->hour.sucess = 0;
    p->hour.type = Screen_numberEditUnsignedChar;

    p->minute.numInc = 1;
    p->minute.numMax = 59;
    p->minute.numMin = 0;
    p->minute.numVar = (long *) &RTC_date.minute;
    p->minute.editRun = 0;
    p->minute.sucess = 0;
    p->minute.type = Screen_numberEditUnsignedChar;

    p->day.numInc = 1;
    p->day.numMax = 31;
    p->day.numMin = 1;
    p->day.numVar = (long *) &RTC_date.day;
    p->day.editRun = 0;
    p->day.sucess = 0;
    p->day.type = Screen_numberEditUnsignedChar;

    p->month.numInc = 1;
    p->month.numMax = 12;
    p->month.numMin = 1;
    p->month.numVar = (long *) &RTC_date.month;
    p->month.editRun = 0;
    p->month.sucess = 0;
    p->month.type = Screen_numberEditUnsignedChar;

    p->year.numInc = 1;
    p->year.numMax = 2500;
    p->year.numMin = 1900;
    p->year.numVar = (long *) &RTC_date.year;
    p->year.editRun = 0;
    p->year.sucess = 0;
    p->year.type = Screen_numberEditUnsignedInt;

    this->parameters = p;
}

void Sc_settingsDateHourBody(Screen_window *this) {
    SC_settingsDateHourParam *p = this->parameters;
    if (Keyboard_keyEsc() && !Screen_hasEditNumRun()) {
        Screen_windowClose();
    }
    Std_printf("%y%x%x%x%x%x", &p->hour, &p->minute, &p->day, &p->month, &p->year);
    Std_printf("  %w%t%1d%t:%t%1d%t\r\n", &Font_numeric_16, p->hour.editRun, p->hour.numView, 0, p->minute.editRun, p->minute.numView, 0);
    Std_printf("%w\n  %t%1d%t-%t%1d%t-%t%3d%t", &Font_alfanum_8, p->day.editRun, p->day.numView, 0, p->month.editRun, p->month.numView, 0, p->year.editRun, p->year.numView, 0);


}

void Sc_settingsDateHourEnd(Screen_window *this) {
    Util_memTop(this->title);
}
Screen_window Sc_settingsDateHour = {0, Sc_settingsDateHourBody, Sc_settingsDateHourStart, Sc_settingsDateHourEnd};