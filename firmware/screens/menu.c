/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

void Sc_menuClick(Screen_listItem *this) {
    Screen_windowOpen(this->parameter);
}

void Sc_menuStart(Screen_window *this) {
    Screen_listItem *itens = Util_memPush(5 * sizeof (Screen_listItem));

    itens[0].description = Lang_load(&lang->alarms);
    itens[0].click = &Sc_menuClick;
    itens[0].parameter = &Sc_alarms;

    itens[1].description = Lang_load(&lang->calendar);
    itens[1].click = &Sc_menuClick;
    itens[1].parameter = &Sc_calendar;

    itens[2].description = Lang_load(&lang->settings);
    itens[2].click = &Sc_menuClick;
    itens[2].parameter = &Sc_settings;

    itens[3].description = Lang_load(&lang->stopwatch);
    itens[3].click = &Sc_menuClick;
    itens[3].parameter = &Sc_stopwatch;

    itens[4].description = Lang_load(&lang->status);
    itens[4].click = &Sc_menuClick;
    itens[4].parameter = &Sc_status;


    /*itens[0].description = "Alarmes";
    itens[0].click = &Sc_menuClick;
    itens[0].parameter = &Sc_alarms;

    itens[1].description = "Calendario";
    itens[1].click = &Sc_menuClick;
    itens[1].parameter = &Sc_calendar;

    itens[2].description = "Configuracoes";
    itens[2].click = &Sc_menuClick;
    itens[2].parameter = &Sc_settings;

    itens[3].description = "Cronometro";
    itens[3].click = &Sc_menuClick;
    itens[3].parameter = &Sc_stopwatch;

    itens[4].description = "Status";
    itens[4].click = &Sc_menuClick;
    itens[4].parameter = &Sc_status;*/


    Screen_list *list = Util_memPush(sizeof (Screen_list));
    //Screen_list list = {itens, 8, 4, 0, 0};
    list->itens = itens;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);

    this->parameters = list;
}

void Sc_menuBody(Screen_window *this) {
    //Std_printf("%rmenu");
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_menuEnd(Screen_window *this) {
    Screen_listItem *itens;
    Screen_list *list;
    list = (this->parameters);
    itens = list->itens;

    Util_memTop(itens);
}
Screen_window Sc_menu = {"menu", Sc_menuBody, Sc_menuStart, Sc_menuEnd};