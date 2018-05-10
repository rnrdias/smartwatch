/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_settingsBody(Screen_window *this) {
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

Screen_window Sc_settings = {"Configuracoes", Sc_settingsBody, 0, 0};