/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 11:01
 */
#include "settings.h"
//char toggle;

char Util_toggleSeg() {
    return TMS >= 50;
}
#define CONSTMAX ((long long int)1<<(sizeof(char *)*8-2))

char RVCB(const void *var) {
    if ((long long int) var & CONSTMAX) {
        var = (long long int) var & CONSTMAX - 1;
    }
    return *(char *) var;
}
//risco de gerar erros inesperados

void *RVCW(const void *var) {
    if ((long long int) var & CONSTMAX) {
        var = (long long int) var & CONSTMAX - 1;
    }
    return *(long long int *) var;
}


#define _CONST // define const variable