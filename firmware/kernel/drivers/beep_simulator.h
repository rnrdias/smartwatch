/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bipe_simulator.h
 * Author: RNR
 *
 * Created on 15 de Maio de 2018, 16:29
 */

#ifndef BEEP_SIMULATOR_H
#define BEEP_SIMULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned int frequency;
        unsigned int frequencyDelay;
        unsigned char repeat;
        unsigned int repeatDelay;
        unsigned char masterRepeat;
        unsigned int masterRepeatDelay;
    } Beep_paramFormat;

    Beep_paramFormat *Beep_param;
    void Beep_initialize(void);
    void Beep_loop(void);




#ifdef __cplusplus
}
#endif

#endif /* BIPE_SIMULATOR_H */

