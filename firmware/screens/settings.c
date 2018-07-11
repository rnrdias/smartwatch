/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

Screen_windowLoad Sc_settingsScLoad = {0, 0};

void Sc_settingsClick(Screen_listItem *this) {
    Sc_settingsScLoad.windows = this->parameter;
    Screen_windowOpen(&Sc_settingsScLoad);
}

void Sc_settingsStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->settings);
    
    Mem_alloc(this->parameters,sizeof (Screen_list));
    
    Screen_list *list = this->parameters;
    //list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 1;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);
}

void Sc_settingsLoop(Screen_windowLoad *this) {
    Screen_listSelectLoad(this->parameters);
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_settingsEnd(Screen_windowLoad *this) {
    Mem_free(this->parameters);
}

void Sc_settingsResume(Screen_windowLoad *this) {
    Screen_listItem *itens;
    Screen_list *list = this->parameters;
    
    Mem_alloc(list->itens, 1 * sizeof (Screen_listItem));
    itens = list->itens;

    itens[0].description = (char*) RVCW(&lang->settingsDateHour);
    itens[0].click = &Sc_settingsClick;
    itens[0].parameter = &Sc_settingsDateHour;

    /* itens[1].description = "C2";
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
     itens[4].parameter = &Sc_status;*/

    
}

void Sc_settingsPause(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;
    Mem_free(list->itens);
}
Screen_window Sc_settings = {0, Sc_settingsLoop, Sc_settingsStart, Sc_settingsEnd, Sc_settingsResume, Sc_settingsPause};