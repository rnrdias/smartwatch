/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 11:02
 */

#include "settings.h"

int UPP_getDisplayWidth() {
    return 84;
}

int UPP_getDisplayHeight() {
    return 6;
}

//char lcdBuffer[504];
void UPP_buffer(char valor, int index) {
    lcdBuffer[index] = valor;
}