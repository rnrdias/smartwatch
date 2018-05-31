/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

typedef struct {
    char *title;
    char month;
    int year;
    unsigned char scroll;
} Sc_calendarParam;


typedef struct {
    Screen_list list;
    Sc_calendarParam *calendar;
} Sc_calendarEventsParam;

typedef struct {
    Screen_numberEditFormat month;
    Screen_numberEditFormat year;
} Sc_calendarEventsNumParam;

void Sc_calendarEventsClick(Screen_listItem *this) {
    Screen_windowOpen(this->parameter);
}

void Sc_calendarEventsPrintItemDate(Screen_listItem *this) {
    Sc_calendarEventsNumParam *n = this->parameter;
    
    if (this->isSelect) {
        Std_printf("%y%x%x", &n->month, &n->year);
    }
    Std_printf("%m%#Def. Data\r\n %#%t%1d%t:%t%3d%t %m\r\n", this->isSelect, &Font_alfanum_8, ' ', &Font_alfanum_8, ' ', n->month.editRun, n->month.numView, 0, n->year.editRun, n->year.numView, 0, 0);
}

void Sc_calendarEventsStart(Screen_window *this) {
    Sc_calendarEventsParam *p;
    this->title = Lang_load(&lang->calendarEvents);
    p = Util_memPush(sizeof (Sc_calendarEventsParam));
    p->calendar = this->parameters;

    //list->itens = itens;
    p->list.quantPrint = 5;
    p->list.sizeList = 5;
    p->list.index = 0;
    p->list.scrollIndex = 0;

    Screen_listSelectLoad(&p->list);
    this->parameters = p;
}

void Sc_calendarEventsLoop(Screen_window *this) {
    Screen_listSelectPrint();
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_calendarEventsEnd(Screen_window *this) {
    Util_memTop(this->title);
}

void Sc_calendarEventsResume(Screen_window *this) {
    Sc_calendarEventsParam *p = this->parameters;
    Screen_listItem *itens = Util_memPush(5 * sizeof (Screen_listItem));
    Sc_calendarEventsNumParam *n = Util_memPush(sizeof (Sc_calendarEventsNumParam));

    itens[0].description = 0;
    itens[0].click = 0;
    itens[0].parameter = n;
    itens[0].itemPrint = Sc_calendarEventsPrintItemDate;
    itens[0].itemPrintSize = 2;


    itens[1].description = Lang_load(&lang->calendar);
    itens[1].click = &Sc_calendarEventsClick;
    itens[1].parameter = &Sc_status;

    itens[2].description = Lang_load(&lang->settings);
    itens[2].click = &Sc_calendarEventsClick;
    itens[2].parameter = &Sc_status;

    itens[3].description = Lang_load(&lang->stopwatch);
    itens[3].click = &Sc_calendarEventsClick;
    itens[3].parameter = &Sc_status;

    itens[4].description = Lang_load(&lang->status);
    itens[4].click = &Sc_calendarEventsClick;
    itens[4].parameter = &Sc_status;

    p->list.itens = itens;


    n->month.numInc = 1;
    n->month.numMax = 12;
    n->month.numMin = 1;
    n->month.numVar = (long *) &p->calendar->month;
    n->month.editRun = 0;
    n->month.sucess = 0;
    n->month.type = Screen_numberEditUnsignedChar;

    n->year.numInc = 1;
    n->year.numMax = 2500;
    n->year.numMin = 1900;
    n->year.numVar = (long *) &p->calendar->year;
    n->year.editRun = 0;
    n->year.sucess = 0;
    n->year.type = Screen_numberEditUnsignedInt;

}

void Sc_calendarEventsPause(Screen_window *this) {
    Sc_calendarEventsParam *p = this->parameters;
    Util_memTop(p->list.itens);
}


Screen_window Sc_calendarEvents = {0, Sc_calendarEventsLoop, Sc_calendarEventsStart, Sc_calendarEventsEnd, Sc_calendarEventsResume, Sc_calendarEventsPause};