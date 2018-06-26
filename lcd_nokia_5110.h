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

#ifndef SETTINGS_H
#define SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

    
void LCD_Inicialize();   
void LCD_SendBuffer(char *buffer);


#ifdef __cplusplus
}
#endif

#endif /* SCREENMAIN_H */

