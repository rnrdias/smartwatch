/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "screens.h"
#include "../App/alarms.h"

void Sc_alarmsClick(Screen_listItem *this) {
    Sc_alarmsSettings.parameters = this->parameter;
    Screen_windowOpen(&Sc_alarmsSettings);
}

void Sc_alarmsStart(Screen_window *this) {
    //Screen_listItem *itens;
    this->title = Lang_load(&lang->alarms);

    Screen_list *list = Util_memPush(sizeof (Screen_list));
    list->itens = 0;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);

    this->parameters = list;
}

void Sc_alarmsLoop(Screen_window *this) {
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

void Sc_alarmsResume(Screen_window *this) {
    Screen_listItem *itens;
    itens = Util_memPush(ALARMS_MAX * sizeof (Screen_listItem));

    for (unsigned char i = 0; i < ALARMS_MAX; i++) {
        char *str = Util_memPush(15 * sizeof (char));
        char *week = Util_memPush(9 * sizeof (char));
        for (char j = 0; j < 8; j++) {
            if (Alarms[i].weekday & (1 << j))
                week[j] = RCB(&lang->initSunday + j);
            else
                week[j] = '_';
        }
        week[8] = '\0';
        Std_sprintf(str, "%1d:%1d %s", Alarms[i].hour, Alarms[i].minute, week);
        itens[i].description = str;
        itens[i].click = &Sc_alarmsClick;
        itens[i].parameter = &Alarms[i];
    }

    Screen_list *l = this->parameters;
    l->itens = itens;
}

void Sc_alarmsPause(Screen_window *this) {
    Screen_list *l = this->parameters;
    Util_memTop(l->itens);
}

Screen_window Sc_alarms = {0, Sc_alarmsLoop, Sc_alarmsStart, Sc_alarmsEnd, Sc_alarmsResume, Sc_alarmsPause};