/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mem.h
 * Author: RNR
 *
 * Created on 15 de Maio de 2018, 21:12
 */

#ifndef MEM_H
#define MEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "kernel/drivers/beep_simulator.h"
#include "App/alarms.h"

#define MEM_MAX 256
    extern char mem[MEM_MAX];

    void Mem_initialize(void);
    void Mem_loop(void);



#define Beep ((Beep_paramFormat *)(mem))
#define Alarms ((Alarms_paramFormat *)(Beep+sizeof(Beep)))
#define Prox (char *)(Alarms+sizeof(Alarms)*ALARMS_MAX)

#ifdef __cplusplus
}
#endif

#endif /* MEM_H */

