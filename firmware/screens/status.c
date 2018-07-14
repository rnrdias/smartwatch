/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../app/status_bar/status_bar.h"

void Sc_statusStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->status);
}

void Sc_statusPrint(const StatusBar_paramFormat *s) {
    Std_printf("%w%c %w%s\r\n", (char*) RVCW(&s->icon), 0, &Font_alfanum_8, (char*) RVCW(&s->title));
}

void Sc_statusLoop(Screen_windowLoad *this) {
    StatusBar_check(Sc_statusPrint);
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_statusEnd(Screen_windowLoad *this) {

}

Screen_window Sc_status = {0, Sc_statusLoop, Sc_statusStart, Sc_statusEnd, 0, 0};