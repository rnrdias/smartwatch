/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stopwatch.h"

//___________________ICON______________________________

CONST UPP_BitmapFormat SB_stopwatchIcon = {
    0x06,
    0x01,
    0x00,
    0x01,
    {
        0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00
    }
};

CONST char SB_stopwatchTitle[] = "Stopwatch";
CONST StatusBar_paramFormat SB_stopwatch = {
    _LC(&SB_stopwatchIcon),
    _LC(&SB_stopwatchTitle),
    0,
    0,
};

const StatusBar_paramFormat *SB_stopwatchLoop() {
    if (App_stopwatchTime.enable)
        return _LC(&SB_stopwatch);
    else
        return 0;
}

StatusBar_registerFormat SB_stopwatchRegister = {
    SB_stopwatchLoop,
    0
};

//___________________________function control________________________________

void App_stopwatch_addHistory(void) {
    unsigned char index;
    if (--App_stopwatchTime.timeHistory.index >= APP_STOPWATCH_MAX_HISTORY)
        App_stopwatchTime.timeHistory.index = 4;
    index = App_stopwatchTime.timeHistory.index % APP_STOPWATCH_MAX_HISTORY;

    App_stopwatchTime.timeHistory.time[index].millesimal = App_stopwatchTime.timeCurrent.millesimal;
    App_stopwatchTime.timeHistory.time[index].second = App_stopwatchTime.timeCurrent.second;

}

App_stopwatchTimeBaseFormat *App_stopwatch_getHistory(unsigned char index) {
    unsigned char i = (App_stopwatchTime.timeHistory.index + index) % APP_STOPWATCH_MAX_HISTORY;
    return &App_stopwatchTime.timeHistory.time[i];
}

void App_stopwatch_timerClear(void) {
    App_stopwatchTime.timeCurrent.millesimal = 0;
    App_stopwatchTime.timeCurrent.second = 0;
    App_stopwatchTime.timeHistory.index = 0;
    for (unsigned char i = 0; i < APP_STOPWATCH_MAX_HISTORY; i++) {
        App_stopwatchTime.timeHistory.time[i].millesimal = 0;
        App_stopwatchTime.timeHistory.time[i].second = 0;
    }
    App_stopwatchTimeCore.auxMillesimal = 0;
}

//______________________Interrupt inicialize______________

void App_stopwatch_intTimerMS(void) {
    if (App_stopwatchTime.enable) {
        App_stopwatchTimeCore.auxMillesimal++;
        App_stopwatchTime.timeCurrent.millesimal = (App_stopwatchTimeCore.auxMillesimal * 100) / 128;
        if (App_stopwatchTimeCore.auxMillesimal > 127) {
            App_stopwatchTimeCore.auxMillesimal = 0;
            App_stopwatchTime.timeCurrent.second++;
        }
    }
}

void App_stopwatch_intButtonUp(void) {
    if (App_stopwatchTime.enableControl) {
        if (App_stopwatchTime.enable) {
            App_stopwatchTime.enable = 0;
        } else {
            App_stopwatchTime.enable = 1;
        }
    }
}

void App_stopwatch_intButtonDown(void) {
    if (App_stopwatchTime.enable) {
        App_stopwatch_addHistory();
    } else {
        App_stopwatch_timerClear();
    }
}

INT_eventData App_stopwatchIntTimerMSEventData = {App_stopwatch_intTimerMS};
Util_eventHandle App_stopwatchIntTimerMSEventHandle = {&App_stopwatchIntTimerMSEventData};


INT_eventData App_stopwatchIntButtonUpEventData = {App_stopwatch_intButtonUp};
Util_eventHandle App_stopwatchIntButtonUpEventHandle = {&App_stopwatchIntButtonUpEventData};

INT_eventData App_stopwatchIntButtonDownEventData = {App_stopwatch_intButtonDown};
Util_eventHandle App_stopwatchIntButtonDownEventHandle = {&App_stopwatchIntButtonDownEventData};

//___________________________APP__________________________

void App_stopwatch_loop(void) {
    if (App_stopwatchTime.enableControl) {
        INT_register(&App_stopwatchIntButtonUpEventHandle, INT_BUTTON_UP);
        INT_register(&App_stopwatchIntButtonDownEventHandle, INT_BUTTON_DOWN);
    } else {
        INT_unregister(&App_stopwatchIntButtonUpEventHandle, INT_BUTTON_UP);
        INT_unregister(&App_stopwatchIntButtonDownEventHandle, INT_BUTTON_DOWN);
    }
}

void App_stopwatch_initialize(void) {
    StatusBar_register(&SB_stopwatchRegister);
    INT_register(&App_stopwatchIntTimerMSEventHandle, INT_TIMER_MS);
}