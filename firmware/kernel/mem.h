/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mem.h
 * Author: rnr
 *
 * Created on 11 de Julho de 2018, 14:46
 */

#ifndef MEM_H
#define MEM_H

#ifdef __cplusplus
extern "C" {
#endif
#include "util.h"


#define Mem_alloc(var,size) _Mem_alloc((void*)&var,size)
#define Mem_free(var) _Mem_free((void*)&var)

    unsigned int Mem_getSizeAlloc(void);
    void _Mem_alloc(void **var, unsigned int size);
    void _Mem_free(void **var);
    void Mem_restructure(void);
    void Mem_initialize(void);
    void Mem_loop(void);
#ifdef __cplusplus
}
#endif

#endif /* MEM_H */

