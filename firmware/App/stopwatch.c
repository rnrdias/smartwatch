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
    if (1)
        return _LC(&SB_stopwatch);
    else
        return 0;
}

StatusBar_registerFormat SB_stopwatchRegister = {
    SB_stopwatchLoop,
    0
};


//___________________________APP_____________________

void App_stopwatch_loop(void) {

}

void App_stopwatch_initialize(void) {
    StatusBar_register(&SB_stopwatchRegister);

    for (unsigned char i = 0; i < App_stopwatchMax; i++) {
        App_stopwatchTimeHistory.time[i].millesimal = 0;
        App_stopwatchTimeHistory.time[i].minute = 0;
        App_stopwatchTimeHistory.time[i].second = 0;
    }
}