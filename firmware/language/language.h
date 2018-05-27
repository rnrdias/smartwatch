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
        char *alarms;
        char *calendar;
        char *calendarEvents;
        char *settings;
        char *stopwatch;
        char *status;
        char *menu;
        char *settingsDateHour;
        char *sunday;
        char *monday;
        char *tuesday;
        char *wednesday;
        char *thursday;
        char *friday;
        char *saturday;
        char *switchedOn;
        char initSunday;
        char initmonday;
        char inittuesday;
        char initwednesday;
        char initthursday;
        char initfriday;
        char initsaturday;
        char initSwitchedOn;
    } Language;

    Language *lang;

    char *Lang_load(char **end);
    char *Lang_loadCharacter(char *end);
    extern const Language pt_br;


#ifdef __cplusplus
}
#endif

#endif /* LANGUAGE_H */

