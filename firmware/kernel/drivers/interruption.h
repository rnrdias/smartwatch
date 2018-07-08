/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interruption.h
 * Author: rnr
 *
 * Created on 8 de Julho de 2018, 15:40
 */

#ifndef INTERRUPTION_H
#define INTERRUPTION_H

#ifdef __cplusplus
extern "C" {
#endif

    void INT_initialize(void);

    void INT_buttonC(void);
    void INT_buttonD(void);

    //void INT_usartRX(void);
    //void INT_usartTX(void);

    void INT_timerMS(void);

#ifdef __cplusplus
}
#endif

#endif /* INTERRUPTION_H */

