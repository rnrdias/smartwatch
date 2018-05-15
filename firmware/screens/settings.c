/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_settingsClick(Screen_listItem *this) {
    Screen_windowOpen(this->parameter);
}

void Sc_settingsStart(Screen_window *this) {
    Screen_listItem *itens;
    this->title = Lang_load(&lang->settings);
    itens = Util_memPush(5 * sizeof (Screen_listItem));

    itens[0].description = Lang_load(&lang->settingsDateHour);
    itens[0].click = &Sc_settingsClick;
    itens[0].parameter = &Sc_settingsDateHour;

    itens[1].description = "C2";
    itens[1].click = &Sc_settingsClick;
    itens[1].parameter = &Sc_calendar;

    itens[2].description = "C3";
    itens[2].click = &Sc_settingsClick;
    itens[2].parameter = &Sc_settings;

    itens[3].description = "C4";
    itens[3].click = &Sc_settingsClick;
    itens[3].parameter = &Sc_stopwatch;

    itens[4].description = "C5";
    itens[4].click = &Sc_settingsClick;
    itens[4].parameter = &Sc_status;

    Screen_list *list = Util_memPush(sizeof (Screen_list));
    list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);

    this->parameters = list;
}

void Sc_settingsBody(Screen_window *this) {
    Screen_listSelectLoad(this->parameters);
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_settingsEnd(Screen_window *this) {
    Util_memTop(this->title);
}

Screen_window Sc_settings = {0, Sc_settingsBody, Sc_settingsStart, Sc_settingsEnd};