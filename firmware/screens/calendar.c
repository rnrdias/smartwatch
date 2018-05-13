/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_calendarStart(Screen_window *this) {
    this->title = Lang_load(&lang->calendar);
}

void Sc_calendarBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_calendarEnd(Screen_window *this) {
    Util_memPop(this->title);
}

Screen_window Sc_calendar = {0, Sc_calendarBody, Sc_calendarStart, Sc_calendarEnd};