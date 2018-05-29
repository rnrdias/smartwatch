/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "alarms.h"
Alarms_paramFormat Alarms[ALARMS_MAX];

void Alarms_ringing(char index) {
    Screen_windowOpen(&Sc_alarmsRinging);
}

void Alarms_loop(void) {
    static char antMinute;

    if (antMinute != RTC_date.minute) {
        antMinute = RTC_date.minute;
        for (unsigned char i = 0; i < ALARMS_MAX; i++) {
            if (Alarms[i].hour > 23) {
                Alarms[i].hour = 0;
            }
            if (Alarms[i].minute > 59) {
                Alarms[i].minute = 0;
            }
            if (
                    Alarms[i].on
                    && (Alarms[i].weekday & (1 << RTC_getWeekday()) || Alarms[i].weekday == 0x80)
                    && Alarms[i].hour == RTC_date.hour
                    && Alarms[i].minute == RTC_date.minute) {
                if (Alarms[i].aux == 0) {
                    Alarms_ringing(i + 1);
                    Alarms[i].aux = 1;
                    if (Alarms[i].weekday == 0x80) {
                        Alarms[i].on = 0;
                    }
                }
            } else {
                Alarms[i].aux = 0;
            }
        }


        if (AlarmsSleep.time > 0) {
            if (AlarmsSleep.time-- == 1) {
                Alarms_ringing(0);
            }
        }
    }
}
Alarms_paramSleep AlarmsSleep;

void Alarms_initialize(void) {
    for (unsigned char i = 0; i < ALARMS_MAX; i++) {
        Alarms[i].hour = 0;
        Alarms[i].minute = 0;
        Alarms[i].weekday = 0;
        Alarms[i].aux = 0;
    }
    AlarmsSleep.time = 0;

    //test
    Alarms[0].hour = 0;
    Alarms[0].minute = 1;
    Alarms[0].weekday = 0x80;
    Alarms[0].mon = 1;

    Alarms[1].hour = 8;
    Alarms[1].minute = 05;
    Alarms[1].on = 1;
    Alarms[1].mon = 1;
    Alarms[1].tue = 1;
    Alarms[1].sat = 1;
    Alarms[1].sun = 1;

    Alarms[2].hour = 12;
    Alarms[2].minute = 00;
    Alarms[2].on = 1;
    Alarms[2].mon = 1;
    Alarms[2].tue = 1;
    Alarms[2].wed = 1;
    Alarms[2].thu = 1;
    Alarms[2].fri = 1;

}