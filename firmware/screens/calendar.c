/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_calendarStart(Screen_window *this) {
    this->title = Lang_load(&lang->calendar);
    this->parameters = Util_memPush(1);
}

void Sc_calendarBody(Screen_window *this) {
    Util_memTop(this->parameters);

    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
    if (Keyboard_keyEnter()) {
#define msg "ola mundo!!ola mundo!!ola mundo!!ola mundo!!ola mundo!!ola mundo!!ola mundo!!ola mundo!!ola mundo!!"
        Sc_notepadParam *parm = Util_memPush(sizeof (Sc_notepadParam));
        parm->data = Util_memPush(sizeof ( msg));
        Std_sprintf(parm->data, msg);

        Sc_notepad.title = Lang_load(&lang->alarms);
        Sc_notepad.parameters = parm;
        Screen_windowOpen(&Sc_notepad);
    }
}

void Sc_calendarEnd(Screen_window *this) {
    Util_memTop(this->title);
}

Screen_window Sc_calendar = {0, Sc_calendarBody, Sc_calendarStart, Sc_calendarEnd};