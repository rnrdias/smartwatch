/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "screens.h"
#include "../app/alarms.h"

typedef struct {
    Beep_paramFormat beep;
    char index;
} Sc_alarmsRingingParam;

void Sc_alarmsRingingStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->alarms);
    char index = this->parameters;

    Mem_alloc(this->parameters, sizeof (Sc_alarmsRingingParam));

    Sc_alarmsRingingParam *p = this->parameters;
    p->index = index;
    p->beep.frequency = 2000;
    p->beep.frequencyDelay = 20;
    p->beep.repeat = 2;
    p->beep.repeatDelay = 25;
    p->beep.masterRepeat = 1;
    p->beep.masterRepeatDelay = 100;
}

void Sc_alarmsRingingLoop(Screen_windowLoad *this) {
    Sc_alarmsRingingParam *p = this->parameters;
    if (p->index != 0) {
        char *str = RVCW(&lang->alarm);
        Std_printf("%s:%d\r\n%1d:%1d", str, p->index, Alarms[p->index - 1].hour, Alarms[p->index - 1].minute);
    } else {
        char *str = RVCW(&lang->sleep);
        Std_printf("%s", str);
    }

    Beep_param = &p->beep;
    if (Keyboard_keyEsc()) {
        App_alarmsSleepEnable(1);
        Screen_windowClose();
    }

    if (Keyboard_keyEnter()) {
        Screen_windowClose();
    }
}

void Sc_alarmsRingingEnd(Screen_windowLoad *this) {
    Beep_paramFormat *p = this->parameters;
    p->repeat = 1;
    Mem_free(p);
}
Screen_window Sc_alarmsRinging = {0, Sc_alarmsRingingLoop, Sc_alarmsRingingStart, Sc_alarmsRingingEnd, 0, 0};
