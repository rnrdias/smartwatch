/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "screens.h"
#include "../App/alarms.h"

Screen_windowLoad Sc_alarmsScLoad = {0, 0};

void Sc_alarmsClick(Screen_listItem *this) {
    Sc_alarmsScLoad.parameters = this->parameter;
    Sc_alarmsScLoad.windows = &Sc_alarmsSettings;
    Screen_windowOpen(&Sc_alarmsScLoad);
    //Sc_alarmsSettings.parameters = this->parameter;
    //Screen_windowOpen(&Sc_alarmsSettings);
}

void Sc_alarmsStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->alarms);

    Mem_alloc(this->parameters, sizeof (Screen_list));

    Screen_list *list = this->parameters;
    list->quantPrint = 5;
    list->sizeList = 5;
    list->index = 0;
    list->scrollIndex = 0;

    Screen_listSelectLoad(list);

}

void Sc_alarmsLoop(Screen_windowLoad *this) {
    Screen_listSelectLoad(this->parameters);
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
    if (Keyboard_keyEnter()) {

    }
}

void Sc_alarmsEnd(Screen_windowLoad *this) {
    Mem_free(this->parameters);
}

void Sc_alarmsResume(Screen_windowLoad *this) {
    Screen_list *l = this->parameters;

    Mem_alloc(l->itens, ALARMS_MAX * sizeof (Screen_listItem));

    Screen_listItem *itens = l->itens;
    for (unsigned char i = 0; i < ALARMS_MAX; i++) {
        char week[9];
        for (char j = 0; j < 8; j++) {
            if (Alarms[i].weekday & (1 << j))
                week[j] = RVCB(&lang->initSunday + j);
            else
                week[j] = '_';
        }
        week[8] = '\0';
        Mem_alloc(itens[i].description, 15 * sizeof (char));
        Std_sprintf(itens[i].description, "%1d:%1d %s", Alarms[i].hour, Alarms[i].minute, week);
        itens[i].click = &Sc_alarmsClick;
        itens[i].parameter = &Alarms[i];
    }


}

void Sc_alarmsPause(Screen_windowLoad *this) {
    Screen_list *l = this->parameters;
    for (unsigned char i = 0; i < ALARMS_MAX; i++) {
        Mem_free(l->itens[i].description);
    }
    Mem_free(l->itens);
}

Screen_window Sc_alarms = {0, Sc_alarmsLoop, Sc_alarmsStart, Sc_alarmsEnd, Sc_alarmsResume, Sc_alarmsPause};