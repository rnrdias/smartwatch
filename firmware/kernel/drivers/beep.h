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
        unsigned int frequency; //frequencia 
        unsigned int frequencyDelay; //frequencia duração
        unsigned char repeat; //numero de repetiçoes
        unsigned int repeatDelay; //repetições duração
        unsigned char masterRepeat; //numero de repetiçoes master
        unsigned int masterRepeatDelay; //repetições duração master
    } Beep_paramFormat;

    Beep_paramFormat *Beep_param;
    
    void Beep_initialize(void);
    void Beep_loop(void);




#ifdef __cplusplus
}
#endif

#endif /* BIPE_SIMULATOR_H */

