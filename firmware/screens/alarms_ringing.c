/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "screens.h"

void Sc_alarmsRingingStart(Screen_window *this) {
    this->title = Lang_load(&lang->status);
    Beep_paramFormat *p = Util_memPush(sizeof (Beep_paramFormat));
    p->frequency = 2000;
    p->frequencyDelay = 200;
    p->masterRepeat = 2;
    p->masterRepeatDelay = 500;
    p->repeat = 250;
    p->repeatDelay = 250;
    this->parameters = p;
    Beep_param = this->parameters;
}

void Sc_alarmsRingingLoop(Screen_window *this) {
    Beep_param = this->parameters;

    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_alarmsRingingEnd(Screen_window *this) {
    Beep_paramFormat *p = this->parameters;
    p->repeat = 1;
    Util_memTop(this->title);
}
Screen_window Sc_alarmsRinging = {0, Sc_alarmsRingingLoop, Sc_alarmsRingingStart, Sc_alarmsRingingEnd, 0, 0};
