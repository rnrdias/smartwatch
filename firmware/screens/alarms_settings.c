/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../App/alarms.h"

typedef struct {
    Screen_numberEditFormat hour;
    Screen_numberEditFormat minute;

    Screen_numberEditFormat sun;
    Screen_numberEditFormat mon;
    Screen_numberEditFormat tue;
    Screen_numberEditFormat wed;
    Screen_numberEditFormat thu;
    Screen_numberEditFormat fri;
    Screen_numberEditFormat sat;
    Screen_numberEditFormat on;

    char aux;
    char weekday[8];
    Alarms_paramFormat *alarm;
} SC_alarmsSettingsParam;

char tmp;

void Sc_alarmsSettingsStart(Screen_window *this) {
    this->title = Lang_load(&lang->alarms);
    Alarms_paramFormat *alarm = this->parameters;
    SC_alarmsSettingsParam *p = Util_memPush(sizeof (SC_alarmsSettingsParam));
    Screen_numberEditFormat *aux = (Screen_numberEditFormat *) p;
    aux += 2;
    p->alarm = alarm;
    p->aux = 0;

    p->hour.numInc = 1;
    p->hour.numMax = 23;
    p->hour.numMin = 0;
    p->hour.numVar = (long *) &alarm->hour;
    p->hour.editRun = 0;
    p->hour.sucess = 0;
    p->hour.type = Screen_numberEditUnsignedChar;

    p->minute.numInc = 1;
    p->minute.numMax = 59;
    p->minute.numMin = 0;
    p->minute.numVar = (long *) &alarm->minute;
    p->minute.editRun = 0;
    p->minute.sucess = 0;
    p->minute.type = Screen_numberEditUnsignedChar;

    for (char i = 0; i < 8; i++) {
        aux->numInc = 1;
        aux->numMax = 1;
        aux->numMin = 0;
        p->weekday[i] = (alarm->weekday & (1 << i)) != 0;
        aux->numVar = (long *) &p->weekday[i];
        aux->editRun = 0;
        aux->sucess = 0;
        aux->type = Screen_numberEditUnsignedChar;
        aux++;
    }

    this->parameters = p;
}

void Sc_alarmsSettingsBody(Screen_window *this) {
    SC_alarmsSettingsParam *p = this->parameters;
    Screen_numberEditFormat *aux = &p->hour;
    if (Screen_hasEditNumRun()) {
        p->aux = 1;
    } else {
        if (Keyboard_keyEsc()) {
            Screen_windowClose();
        }
        if (p->aux) {
            char weekday = 0;
            for (char i = 0; i < 8; i++) {
                weekday |= ((p->weekday[i]) << i);
            }
            p->alarm->weekday = weekday;
            p->aux = 0;
        }
    }

    Std_printf("  %w%t%1d%t:%t%1d%t\r\n", &Font_numeric_16, p->hour.editRun, (int) p->hour.numView, 0, p->minute.editRun, (int) p->minute.numView, 0);
    Std_printf("%w ", &Font_alfanum_6);
    Std_printf("%y");
    for (char i = 0; i < 10; i++) {
        Std_printf("%x", aux);
        if (i >= 2) {
            char *weekday = Lang_load(&lang->sunday + i - 2);
            Std_printf("%t%m%s%m%t ", aux->editRun, (int) aux->numView, weekday, 0, 0);
            Util_memTop(weekday);
            if (i == 6)
                Std_printf("     ");
        }
        aux++;
    }
}

void Sc_alarmsSettingsEnd(Screen_window *this) {
    Util_memTop(this->title);
}
Screen_window Sc_alarmsSettings = {0, Sc_alarmsSettingsBody, Sc_alarmsSettingsStart, Sc_alarmsSettingsEnd};