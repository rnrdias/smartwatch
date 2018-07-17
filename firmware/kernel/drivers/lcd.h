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

#ifndef LCD_H
#define LCD_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned char contrast;
        unsigned char powerdown;
    } LCD_param;

    LCD_param LCD;

    void LCD_initialize(void);
    void LCD_sendBuffer(char *buffer);
    void LCD_loop(void);

#ifdef __cplusplus
}
#endif

#endif /* LCD_H */

