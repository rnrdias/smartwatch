/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stopwatch.h"
#include "../screens/screens.h"
//___________________ICON______________________________

void SB_stopwatchFunction(void) {
    Screen_windowLoad scLoad;
    scLoad.parameters = 0;
    scLoad.windows = &Sc_stopwatch;
    Screen_windowOpen(&scLoad);
}

CONST UPP_BitmapFormat SB_stopwatchIcon = {
    STATUS_BAR_HEAD
    {0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00}
};

CONST char SB_stopwatchTitle[] = "Stopwatch";
CONST StatusBar_paramFormat SB_stopwatch = {
    _LC(&SB_stopwatchIcon),
    _LC(&SB_stopwatchTitle),
    SB_stopwatchFunction,
};

StatusBar_registerFormat SB_stopwatchRegister = {
    0,
    _LC(&SB_stopwatch)
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
    App_stopwatchTime.isPause = 0;
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
        App_stopwatchTime.timeCurrent.millesimal = (App_stopwatchTimeCore.auxMillesimal * 100) / TMS_INT_SEC;
        if (App_stopwatchTimeCore.auxMillesimal >= TMS_INT_SEC) {
            App_stopwatchTimeCore.auxMillesimal = 0;
            App_stopwatchTime.timeCurrent.second++;
        }
    }
}

void App_stopwatch_intButtonUp(void) {
    if (App_stopwatchTime.enableControl) {
        if (App_stopwatchTime.enable) {
            App_stopwatchTime.enable = 0;
            StatusBar_unregister(&SB_stopwatchRegister);
            App_stopwatchTime.isPause = 1;
        } else {
            App_stopwatchTime.enable = 1;
            StatusBar_register(&SB_stopwatchRegister);
            App_stopwatchTime.isPause = 0;
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

Int_event App_stopwatchIntEventTimerMS = {0, App_stopwatch_intTimerMS};

Int_event App_stopwatchIntEventButtonUp = {0, App_stopwatch_intButtonUp};

Int_event App_stopwatchIntEventButtonDown = {0, App_stopwatch_intButtonDown};

//___________________________APP__________________________

void App_stopwatch_loop(void) {
    if (App_stopwatchTime.enableControl) {
        Int_register(&App_stopwatchIntEventButtonUp, INT_BUTTON_UP);
        Int_register(&App_stopwatchIntEventButtonDown, INT_BUTTON_DOWN);
    } else {
        Int_unregister(&App_stopwatchIntEventButtonUp, INT_BUTTON_UP);
        Int_unregister(&App_stopwatchIntEventButtonDown, INT_BUTTON_DOWN);
    }
}

void App_stopwatch_initialize(void) {
    Int_register(&App_stopwatchIntEventTimerMS, INT_TIMER_MS);
    App_stopwatch_timerClear();
}