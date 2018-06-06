/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   language.h
 * Author: RNR
 *
 * Created on 11 de Maio de 2018, 21:38
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../kernel/screen/screen.h"
#include "../kernel/fonts/fonts.h"
#include "../kernel/util.h"

    typedef struct {
        const char *alarms;
        const char *calendar;
        const char *calendarEvents;
        const char *settings;
        const char *stopwatch;
        const char *status;
        const char *menu;
        const char *settingsDateHour;
        const char *sunday;
        const char *monday;
        const char *tuesday;
        const char *wednesday;
        const char *thursday;
        const char *friday;
        const char *saturday;
        const char *switchedOn;
        const char initSunday;
        const char initmonday;
        const char inittuesday;
        const char initwednesday;
        const char initthursday;
        const char initfriday;
        const char initsaturday;
        const char initSwitchedOn;
        const char *alarm;
        const char *sleep;
    } Language;

    const Language *lang;

    char *Lang_load(const char * const* end);
    char *Lang_loadCharacter(char *end);
    extern const Language *pt_br;



#ifdef __cplusplus
}
#endif

#endif /* LANGUAGE_H */

