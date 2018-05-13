/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fonte.h
 * Author: RNR
 *
 * Created on 2 de Maio de 2018, 20:24
 */

#ifndef FONTE_H
#define FONTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../util.h"
#include "../upp/upp.h"
    /*
     * Fonte alfanumerico tamanho 6
     */
    CONST extern UPP_BitmapFormat Font_alfanum_6;

    /*
     * Fonte alfanumerico tamanho 8
     */
    CONST extern UPP_BitmapFormat Font_alfanum_8;

    /*
     * Fonte numerica tamanho 16
     */
    CONST extern UPP_BitmapFormat Font_numeric_16;

    /*
     * Fonte numerica tamanho 24
     */
    CONST extern UPP_BitmapFormat Font_numeric_24;
#ifdef __cplusplus
}
#endif

#endif /* FONTE_H */

