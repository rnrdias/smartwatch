/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "notepad.h"

void Sc_notepadStart(Screen_window *this) {
    Sc_notepadParam *p = this->parameters;
    p->scroll = Util_memPush(sizeof (unsigned int));
    *p->scroll = 0;
    Screen_StartScroll(p->scroll);
}

void Sc_notepadBody(Screen_window *this) {
    Sc_notepadParam *p = this->parameters;
    Std_printf("%o%s", *p->scroll, p->data);

    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_notepadEnd(Screen_window *this) {
    Sc_notepadParam *p = this->parameters;
    Util_memTop(p->scroll);
}
Screen_window Sc_notepad = {0, Sc_notepadBody, Sc_notepadStart, Sc_notepadEnd};