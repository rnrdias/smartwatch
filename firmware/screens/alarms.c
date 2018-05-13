/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_alarmsStart(Screen_window *this){
    this->title = Lang_load(&lang->alarms);
}

void Sc_alarmsBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_alarmsEnd(Screen_window *this){
    Util_memPop(this->title);
}

Screen_window Sc_alarms = {0, Sc_alarmsBody, Sc_alarmsStart, Sc_alarmsEnd};