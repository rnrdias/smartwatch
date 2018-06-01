/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alarms.h
 * Author: RNR
 *
 * Created on 15 de Maio de 2018, 21:39
 */

#ifndef ALARMS_H
#define ALARMS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "../kernel/drivers/real_time_clock.h"
#include "../screens/screens.h"
#include "status_bar/status_bar.h"

#define ALARMS_MAX 5

    typedef union {

        struct {
            unsigned char hour;
            unsigned char minute;
            unsigned char weekday; //L S S Q Q T S D
            unsigned char aux;
        };

        struct {
            unsigned : 8;
            unsigned : 8;
            unsigned sun : 1;
            unsigned mon : 1;
            unsigned tue : 1;
            unsigned wed : 1;
            unsigned thu : 1;
            unsigned fri : 1;
            unsigned sat : 1;
            unsigned on : 1;
        };
    } Alarms_paramFormat;
    
    
    typedef struct{
        unsigned char currentHour;
        unsigned char currentMinute;
        unsigned char time;
        unsigned char enable;
    }Alarms_sleepParamFormat;
    
    extern Alarms_paramFormat Alarms[ALARMS_MAX];
    extern Alarms_sleepParamFormat Alarms_sleep;
    
    void Alarms_ringing(char index);

    void Alarms_initialize(void);
    void Alarms_loop(void);

    //void Alarms_sleep(void);


#ifdef __cplusplus
}
#endif

#endif /* ALARMS_H */

