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
    return RTC_weekdayCalc(RTC_date.day, RTC_date.month, RTC_date.year);
}

void RTC_dateValid(RTC_DateFormat *date) {
    if (date->second >= 60) {
        date->second = 0;
        date->minute++;
    }
    if (date->minute >= 60) {
        date->minute = 0;
        date->hour++;
    }
    if (date->hour >= 24) {
        date->hour = 0;
        date->day++;
    }
    if (date->day > RTC_monthDay[date->month - 1]+(date->year % 4 == 0 && date->month == 2) ? 1 : 0) {
        date->day = 1;
        date->month++;
    }
    if (date->month >= 13) {
        date->month = 1;
        date->year++;
    }
    if (date->day == 0)
        date->day = 1;
    if (date->month == 0)
        date->month = 1;
}

void RTC_loop() {
    RTC_dateValid(&RTC_date);
}

void RTC_initialize() {
    RTC_date.hour = 0;
    RTC_date.minute = 0;
    RTC_date.second = 0;
    RTC_date.day = 1;
    RTC_date.month = 1;
    RTC_date.year = 1900;
}
