/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   start.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 12:01
 */

#ifndef START_H
#define START_H

#ifdef __cplusplus
extern "C" {
#endif

#include "settings/settings.h"
#include "drivers/real_time_clock.h"
#include "drivers/beep_simulator.h"
#include "drivers/time_ms.h"

    void Start_initialize();

    void Start_loop();


#ifdef __cplusplus
}
#endif

#endif /* START_H */

