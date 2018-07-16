/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../app/status_bar/status_bar.h"

void Sc_statusPrintItem(Screen_listItem *this) {
    StatusBar_paramFormat *s = this->parameter;
    Std_printf("%m%#%w%c %w%s%m\r\n", this->isSelect, &Font_alfanum_8, ' ', (char*) RVCW(&s->icon), 0, &Font_alfanum_8, (char*) RVCW(&s->title), 0);
}

void Sc_statusPrint(const StatusBar_paramFormat *s, void *parameter) {
    Screen_listItem *itens = parameter;
    while (itens->parameter)itens++;
    itens->parameter = (StatusBar_paramFormat *) s;
    itens->description = 0;
    itens->click = (void (*)(struct Screen_listItem_t *))RVCW(&s->function);
    itens->itemPrint = Sc_statusPrintItem;
    itens->itemPrintSize = 1;
}

void Sc_statusStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->status);
    Mem_alloc(this->parameters, sizeof (Screen_list));

    Screen_list *list = this->parameters;
    //list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 0;
    list->index = 0;
    list->scrollIndex = 0;
}

void Sc_statusEnd(Screen_windowLoad *this) {
    Mem_free(this->parameters);
}

void Sc_statusResume(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;
    list->sizeList = StatusBar_size();
    if (list->sizeList == 0)
        return;
    Mem_alloc(list->itens, list->sizeList * sizeof (Screen_listItem));
    for (unsigned char i = 0; i < list->sizeList; i++)
        list->itens[i].parameter = 0;
    StatusBar_check(Sc_statusPrint, list->itens);
}

void Sc_statusPause(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;
    Mem_free(list->itens);
}

void Sc_statusReload(Screen_windowLoad *this) {
    Sc_statusPause(this);
    Sc_statusResume(this);
}

void Sc_statusLoop(Screen_windowLoad *this) {
    Screen_list *list = this->parameters;
    Screen_listSelectLoad(list);
    Screen_listSelectPrint();
    if (list->sizeList != StatusBar_size()) {
        Sc_statusReload(this);
    }
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}


Screen_window Sc_status = {0, Sc_statusLoop, Sc_statusStart, Sc_statusEnd, Sc_statusResume, Sc_statusPause};