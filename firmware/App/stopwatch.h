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

#define App_stopwatchMax 5

    typedef struct {
        unsigned char enable;
        RTC_DateFormat date;
    } App_stopwatchTimeCoreFormat;

    typedef struct {
        unsigned char minute;
        unsigned char second;
        unsigned char millesimal;
    } App_stopwatchTimeBaseFormat;

    typedef struct {
        unsigned char index;
        App_stopwatchTimeBaseFormat time[App_stopwatchMax];
    } App_stopwatchTimeHistoryFormat;

    App_stopwatchTimeCoreFormat App_stopwatchTimeCore;
    App_stopwatchTimeHistoryFormat App_stopwatchTimeHistory;


    void App_stopwatch_loop(void);
    void App_stopwatch_initialize(void);

#ifdef __cplusplus
}
#endif

#endif /* STOP_WATCH_H */

