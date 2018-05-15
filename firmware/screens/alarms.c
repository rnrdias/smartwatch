/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_alarmsClick(Screen_listItem *this) {
    Screen_windowOpen(&Sc_alarmsSettings);
}

void Sc_alarmsStart(Screen_window *this) {
    Screen_listItem *itens;
    this->title = Lang_load(&lang->alarms);

    itens = Util_memPush(5 * sizeof (Screen_listItem));
    itens[0].description = "00:00 Desl.";
    itens[0].click = &Sc_alarmsClick;
    itens[0].parameter = 0;

    itens[1].description = "00:00 Desl.";
    itens[1].click = &Sc_alarmsClick;
    itens[1].parameter = 0;

    itens[2].description = "00:00 Desl.";
    itens[2].click = &Sc_alarmsClick;
    itens[2].parameter = 0;

    itens[3].description = "00:00 Desl.";
    itens[3].click = &Sc_alarmsClick;
    itens[3].parameter = 0;

    itens[4].description = "00:00 Desl.";
    itens[4].click = &Sc_alarmsClick;
    itens[4].parameter = 0;

    Screen_list *list = Util_memPush(sizeof (Screen_list));
    list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);

    this->parameters = list;
}

void Sc_alarmsBody(Screen_window *this) {
    //Std_printf("%1d:%1d DSTQQSS\r\n",1,0);
    Screen_listSelectLoad(this->parameters);
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
    if (Keyboard_keyEnter()) {

    }
}

void Sc_alarmsEnd(Screen_window *this) {
    Util_memTop(this->title);
}

Screen_window Sc_alarms = {0, Sc_alarmsBody, Sc_alarmsStart, Sc_alarmsEnd};