/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time_ms.h
 * Author: rnr
 *
 * Created on 7 de Julho de 2018, 23:05
 */

#ifndef TIME_MS_H
#define TIME_MS_H

#ifdef __cplusplus
extern "C" {
#endif
    unsigned char TMS_ms;
    void TMS_initialize(void);
    void TMS_process(void);
    void TMS_loop(void);
    

#ifdef __cplusplus
}
#endif

#endif /* TIME_MS_H */

