/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_alarmsSettingsStart(Screen_window *this) {
        this->title = Lang_load(&lang->status);
}

void Sc_alarmsSettingsBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_alarmsSettingsEnd(Screen_window *this) {
    Util_memTop(this->title);
}
Screen_window Sc_alarmsSettings = {0, Sc_alarmsSettingsBody, Sc_alarmsSettingsStart, Sc_alarmsSettingsEnd};