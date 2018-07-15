/*
 * smartwatch.c
 *
 * Created: 10/05/2018 16:49:05
 *  Author: RNR
 */

#include "language.h"

CONST char pt_br_alarms[] = "Alarmes";
CONST char pt_br_settingsDateHour[] = "Ajuste dt/hr";
CONST char pt_br_calendar[] = "Calendario";
CONST char pt_br_calendarEvents[] = "Calend. eventos";
CONST char pt_br_settings[] = "Configuracoes";
CONST char pt_br_stopwatch[] = "Cronometro";
CONST char pt_br_status[] = "Status";
CONST char pt_br_menu[] = "Menu";
//seq
CONST char pt_br_sunday[] = "Dom";
CONST char pt_br_monday[] = "Seg";
CONST char pt_br_tuesday[] = "Ter";
CONST char pt_br_wednesday[] = "Qua";
CONST char pt_br_thursday[] = "Qui";
CONST char pt_br_friday[] = "Sex";
CONST char pt_br_saturday[] = "Sab";
CONST char pt_br_switchedOn[] = "Lig";
//seq fim
CONST char pt_br_alarm[] = "Alarme";
CONST char pt_br_sleep[] = "Soneca";

CONST Language _pt_br = {
    _LC(pt_br_alarms),
    _LC(pt_br_calendar),
    _LC(pt_br_calendarEvents),
    _LC(pt_br_settings),
    _LC(pt_br_stopwatch),
    _LC(pt_br_status),
    _LC(pt_br_menu),
    _LC(pt_br_settingsDateHour),
    _LC(pt_br_sunday),
    _LC(pt_br_monday),
    _LC(pt_br_tuesday),
    _LC(pt_br_wednesday),
    _LC(pt_br_thursday),
    _LC(pt_br_friday),
    _LC(pt_br_saturday),
    _LC(pt_br_switchedOn),
    'D',
    'S',
    'T',
    'Q',
    'Q',
    'S',
    'S',
    'L',
    _LC(pt_br_alarm),
    _LC(pt_br_sleep)
};

//CONST Language * const pt_br = (const Language *) _LC((void *)&_pt_br);