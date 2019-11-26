/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_menuClick(Screen_listItem *this) {
    Screen_windowLoad scLoad;
    scLoad.windows = this->parameter;
    scLoad.parameters = 0;
    Screen_windowOpen(&scLoad);
}

void Sc_menuStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->menu);

    Mem_alloc(this->parameters, sizeof (Screen_list));

    Screen_list *list = this->parameters;
    //list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);
}

void Sc_menuLoop(Screen_windowLoad *this) {
    Screen_listSelectLoad(this->parameters);
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_menuEnd(Screen_windowLoad *this) {
    Mem_free(this->parameters);
}

void Sc_menuResume(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;

    Mem_alloc(list->itens, 5 * sizeof (Screen_listItem));

    Screen_listItem *itens = list->itens;
    itens[0].description = (char*) RVCW(&lang->alarms);
    itens[0].click = &Sc_menuClick;
    itens[0].parameter = &Sc_alarms;

    itens[1].description = (char*) RVCW(&lang->calendar);
    itens[1].click = &Sc_menuClick;
    itens[1].parameter = &Sc_calendar;

    itens[2].description = (char*) RVCW(&lang->settings);
    itens[2].click = &Sc_menuClick;
    itens[2].parameter = &Sc_settings;

    itens[3].description = (char*) RVCW(&lang->stopwatch);
    itens[3].click = &Sc_menuClick;
    itens[3].parameter = &Sc_stopwatch;

    itens[4].description = (char*) RVCW(&lang->status);
    itens[4].click = &Sc_menuClick;
    itens[4].parameter = &Sc_status;

    list->itens = itens;
}

void Sc_menuPause(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;
    Mem_free(list->itens);
}
Screen_window Sc_menu = {0, Sc_menuLoop, Sc_menuStart, Sc_menuEnd, Sc_menuResume, Sc_menuPause};