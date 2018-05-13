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

#ifndef LCD_SIMULATOR_H
#define LCD_SIMULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <conio.h>
#include <windows.h>
    
void LCD_inicialize(void);  
void LCD_sendBuffer(char *buffer);


#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

