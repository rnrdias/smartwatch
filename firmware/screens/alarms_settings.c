/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"
#include "../app/alarms.h"

typedef struct {
    Screen_numberEditFormat hour;
    Screen_numberEditFormat minute;

    Screen_numberEditFormat sun;
    Screen_numberEditFormat mon;
    Screen_numberEditFormat tue;
    Screen_numberEditFormat wed;
    Screen_numberEditFormat thu;
    Screen_numberEditFormat fri;
    Screen_numberEditFormat sat;
    Screen_numberEditFormat on;

    char aux;
    char weekday[8];
} SC_alarmsSettingsParamNumEdit;

typedef struct {
    SC_alarmsSettingsParamNumEdit *numbs;
    App_alarms_paramFormat *alarm;
} SC_alarmsSettingsParam;

void Sc_alarmsSettingsStart(Screen_windowLoad *this) {
    App_alarms_paramFormat *alarm = this->parameters;

    Mem_alloc(this->parameters, sizeof (SC_alarmsSettingsParam));

    SC_alarmsSettingsParam *p = this->parameters;
    this->windows->title = (char*) RVCW(&lang->alarms);
    p->alarm = alarm;
}

//CONST char Sc_alarmsSettingsScreen[] = "  %w%t%1d%t:%t%1d%t\r\n";

void Sc_alarmsSettingsLoop(Screen_windowLoad *this) {
    SC_alarmsSettingsParam *p = this->parameters;
    SC_alarmsSettingsParamNumEdit *n = p->numbs;
    Screen_numberEditFormat *aux = &p->numbs->hour;
    if (Screen_hasEditNumRun()) {
        n->aux = 1;
    } else {
        if (Keyboard_keyEsc()) {
            Screen_windowClose();
        }
        if (n->aux) {
            char weekday = 0;
            for (char i = 0; i < 8; i++) {
                weekday |= ((n->weekday[i]) << i);
            }
            p->alarm->weekday = weekday;
            n->aux = 0;
        }
    }
    //load variables
    Std_printf("%y");
    for (char i = 0; i < 10; i++) {
        Std_printf("%x", aux++);
    }
    //print screen
    Std_printf("  %w%t%1d%t:%t%1d%t\r\n", &Font_numeric_16, n->hour.editRun, (int) n->hour.numView, 0, n->minute.editRun, (int) n->minute.numView, 0);
    Std_printf("%w ", &Font_alfanum_6);
    aux = &p->numbs->sun;
    for (char i = 0; i < 8; i++) {
        char *weekday = (char*) RVCW(&lang->sunday + i);
        Std_printf("%t%m%s%m%t ", aux->editRun, (int) aux->numView, weekday, 0, 0);
        if (i == 4)
            Std_printf("     ");
        aux++;
    }
}

void Sc_alarmsSettingsEnd(Screen_windowLoad *this) {
    Mem_free(this->parameters);
}

void Sc_alarmsSettingsResume(Screen_windowLoad *this) {
    SC_alarmsSettingsParam *p = this->parameters;

    Mem_alloc(p->numbs, sizeof (SC_alarmsSettingsParamNumEdit));
    SC_alarmsSettingsParamNumEdit *n = p->numbs;
    Screen_numberEditFormat *aux = (Screen_numberEditFormat *) n;
    aux += 2;

    n->aux = 0;

    n->hour.numInc = 1;
    n->hour.numMax = 23;
    n->hour.numMin = 0;
    n->hour.numVar = (long *) &p->alarm->hour;
    n->hour.editRun = 0;
    n->hour.sucess = 0;
    n->hour.type = Screen_numberEditUnsignedChar;

    n->minute.numInc = 1;
    n->minute.numMax = 59;
    n->minute.numMin = 0;
    n->minute.numVar = (long *) &p->alarm->minute;
    n->minute.editRun = 0;
    n->minute.sucess = 0;
    n->minute.type = Screen_numberEditUnsignedChar;

    for (char i = 0; i < 8; i++) {
        aux->numInc = 1;
        aux->numMax = 1;
        aux->numMin = 0;
        n->weekday[i] = (p->alarm->weekday & (1 << i)) != 0;
        aux->numVar = (long *) &n->weekday[i];
        aux->editRun = 0;
        aux->sucess = 0;
        aux->type = Screen_numberEditUnsignedChar;
        aux++;
    }
}

void Sc_alarmsSettingsPause(Screen_windowLoad *this) {
    SC_alarmsSettingsParam *p = this->parameters;
    Mem_free(p->numbs);
}


Screen_window Sc_alarmsSettings = {0, Sc_alarmsSettingsLoop, Sc_alarmsSettingsStart, Sc_alarmsSettingsEnd, Sc_alarmsSettingsResume, Sc_alarmsSettingsPause};