/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "alarms.h"
Alarms_paramFormat Alarms[ALARMS_MAX];
Alarms_sleepParamFormat Alarms_sleep;



//___________________ICON______________________________

CONST UPP_BitmapFormat SB_icon = {
    0x06,
    0x01,
    0x00,
    0x01,
    {
        0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x00
    }
};

StatusBar_paramFormat SB = {
    &SB_icon,
    0,
    0,
    0,
};

StatusBar_paramFormat *SB_iconLoop() {
    if (Alarms_sleep.enable)
        return &SB;
    else
        return 0;
}

StatusBar_registerFormat SB_register = {
    SB_iconLoop,
    0
};



//_____________________APP__________________________

void Alarms_ringing(char index) {
    //Sc_alarmsRinging.parameters = index;
    //Screen_windowOpen(&Sc_alarmsRinging);
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

    }

    if (Alarms_sleep.enable) {
        if (Alarms_sleep.time) {
            Alarms_sleep.currentMinute = RTC_date.minute + Alarms_sleep.time;
            Alarms_sleep.currentHour = RTC_date.hour;

            if (Alarms_sleep.currentMinute >= 60) {
                Alarms_sleep.currentMinute -= 60;
                Alarms_sleep.currentHour++;
            }
            if (Alarms_sleep.currentHour >= 24) {
                Alarms_sleep.currentHour = 0;
            }
            Alarms_sleep.time = 0;
        }

        if (Alarms_sleep.currentHour == RTC_date.hour && Alarms_sleep.currentMinute == RTC_date.minute) {
            Alarms_sleep.enable = 0;
            Alarms_ringing(0);
        }
    }
}

void Alarms_initialize(void) {
    for (unsigned char i = 0; i < ALARMS_MAX; i++) {
        Alarms[i].hour = 0;
        Alarms[i].minute = 0;
        Alarms[i].weekday = 0;
        Alarms[i].aux = 0;
    }
    Alarms_sleep.currentHour = 0;
    Alarms_sleep.currentMinute = 0;
    Alarms_sleep.enable = 0;
    Alarms_sleep.time = 10;

    StatusBar_register(&SB_register);


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



