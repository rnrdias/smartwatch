/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "real_time_clock.h"
unsigned char RTC_monthDay[] = {
    31, //JaN
    28, //Fer
    31, //Mar
    30, //Abr
    31, //Mai
    30, //Jun
    31, //Jul
    31, //Ago
    30, //Set
    31, //Out
    30, //Nov
    31, //Dez
};

unsigned char RTC_weekdayCalc(unsigned char day, unsigned char month, unsigned int year) {
    unsigned char i = month;
    unsigned int daysSum = 0;
    while (--i) {
        daysSum += RTC_monthDay[i - 1];
    }
    return ((year / 4) + day + daysSum + year + 5) % 7;
}

unsigned char RTC_getWeekday() {
    return RTC_weekdayCalc(RTC_day, RTC_month, RTC_year);
}

void RTC_loop() {
    if (RTC_second >= 60) {
        RTC_second = 0;
        RTC_minute++;
    }
    if (RTC_minute >= 60) {
        RTC_minute = 0;
        RTC_hour++;
    }
    if (RTC_hour >= 24) {
        RTC_hour = 0;
        RTC_day++;
    }
    if (RTC_day > RTC_monthDay[RTC_month - 1]+(RTC_year % 4 == 0 && RTC_month == 2) ? 1 : 0) {
        RTC_day = 1;
        RTC_month++;
    }
    if (RTC_month >= 13) {
        RTC_month = 1;
        RTC_year++;
    }
    if (RTC_day == 0)
        RTC_day = 1;
    if (RTC_month == 0)
        RTC_month = 1;
}

void RTC_initialize() {
    RTC_hour = 0;
    RTC_minute = 0;
    RTC_second = 0;

    RTC_day = 1;
    RTC_month = 1;
    RTC_year = 1900;
}
