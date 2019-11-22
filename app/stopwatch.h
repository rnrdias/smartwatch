/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stop_watch.h
 * Author: rnr
 *
 * Created on 7 de Julho de 2018, 23:30
 */

#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "status_bar/status_bar.h"
#include "../kernel/drivers/real_time_clock.h"
#include "../kernel/drivers/interruption.h"
#include "../kernel/drivers/time_ms.h"

#define APP_STOPWATCH_MAX_HISTORY 5

    typedef struct {
        unsigned long int second;
        unsigned char millesimal;
    } App_stopwatchTimeBaseFormat;

    typedef struct {
        unsigned char index;
        App_stopwatchTimeBaseFormat time[APP_STOPWATCH_MAX_HISTORY];
    } App_stopwatchTimeHistoryFormat;

    typedef struct {
        unsigned char enable;
        unsigned char enableControl;
        unsigned char isPause;
        App_stopwatchTimeBaseFormat timeCurrent;
        App_stopwatchTimeHistoryFormat timeHistory;
    } App_stopwatchTimeFormat;

    App_stopwatchTimeFormat App_stopwatchTime;

    void App_stopwatch_addHistory(void);
    App_stopwatchTimeBaseFormat *App_stopwatch_getHistory(unsigned char index);

    void App_stopwatch_loop(void);
    void App_stopwatch_initialize(void);

#ifdef __cplusplus
}
#endif

#endif /* STOP_WATCH_H */

