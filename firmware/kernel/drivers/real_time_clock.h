/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 8 de Maio de 2018, 11:24
 */

#ifndef REAL_TIME_CLOCK_H
#define REAL_TIME_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

    extern unsigned char RTC_monthDay[];

    unsigned char RTC_hour, RTC_minute, RTC_second, RTC_day, RTC_month;
    unsigned int RTC_year;

    unsigned char RTC_weekdayCalc(unsigned char day, unsigned char month, unsigned int year);
    unsigned char RTC_getWeekday();

    void RTC_initialize();
    void RTC_loop();





#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

