/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_stopwatchStart(Screen_window *this) {
    this->title = Lang_load(&lang->stopwatch);
}

void Sc_stopwatchBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_stopwatchEnd(Screen_window *this) {
    Util_memTop(this->title);
}
Screen_window Sc_stopwatch = {0, Sc_stopwatchBody, Sc_stopwatchStart, Sc_stopwatchEnd};