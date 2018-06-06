/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_statusStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->status);
}

void Sc_statusLoop(Screen_windowLoad *this) {
    if (Keyboard_keyEsc()) {
        
        Screen_windowClose();
    }
}

void Sc_statusEnd(Screen_windowLoad *this) {

}

Screen_window Sc_status = {0, Sc_statusLoop, Sc_statusStart, Sc_statusEnd, 0, 0};