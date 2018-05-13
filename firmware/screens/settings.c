/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_settingsStart(Screen_window *this) {
    this->title = Lang_load(&lang->settings);
}

void Sc_settingsBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_settingsEnd(Screen_window *this) {
    Util_memTop(this->title);
}

Screen_window Sc_settings = {0, Sc_settingsBody, Sc_settingsStart, Sc_settingsEnd};