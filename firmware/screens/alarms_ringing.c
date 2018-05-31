/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "screens.h"
#include "../App/alarms.h"

typedef struct {
    Beep_paramFormat beep;
    char index;
} Sc_alarmsRingingParam;

void Sc_alarmsRingingStart(Screen_window *this) {
    this->title = Lang_load(&lang->alarms);
    Sc_alarmsRingingParam *p = Util_memPush(sizeof (Sc_alarmsRingingParam));
    p->index = (char) this->parameters;
    p->beep.frequency = 2000;
    p->beep.frequencyDelay = 200;
    p->beep.masterRepeat = 2;
    p->beep.masterRepeatDelay = 500;
    p->beep.repeat = 250;
    p->beep.repeatDelay = 250;
    this->parameters = p;
    //Beep_param = this->parameters;
}

void Sc_alarmsRingingLoop(Screen_window *this) {
    Sc_alarmsRingingParam *p = this->parameters;
    if (p->index != 0) {
        char *str = Lang_load(&lang->alarm);
        Std_printf("%s:%d\r\n%1d:%1d", str, p->index, Alarms[p->index - 1].hour, Alarms[p->index - 1].minute);
        Util_memTop(str);
    } else {
        char *str = Lang_load(&lang->sleep);
        Std_printf("%s", str);
        Util_memTop(str);
    }

    Beep_param = &p->beep;
    if (Keyboard_keyEsc()) {
        Alarms_sleep.enable = 10;
        Alarms_sleep.time = 1;
        Screen_windowClose();
    }

    if (Keyboard_keyEnter()) {
        Screen_windowClose();
    }
}

void Sc_alarmsRingingEnd(Screen_window *this) {
    Beep_paramFormat *p = this->parameters;
    p->repeat = 1;
    Util_memTop(this->title);
}
Screen_window Sc_alarmsRinging = {0, Sc_alarmsRingingLoop, Sc_alarmsRingingStart, Sc_alarmsRingingEnd, 0, 0};
