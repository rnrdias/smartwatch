/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   energy_management.h
 * Author: rnr
 *
 * Created on 17 de Julho de 2018, 14:37
 */

#ifndef ENERGY_MANAGEMENT_H
#define ENERGY_MANAGEMENT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "drivers/keyboard.h"
#include "drivers/cpu_control.h"

    typedef struct {
        unsigned int timeStandbay;
    } EM_format;
    EM_format EM;
    
    void EM_standbayLoop(void);
    void EM_standbayInitialize(void);

#ifdef __cplusplus
}
#endif

#endif /* ENERGY_MANAGEMENT_H */

