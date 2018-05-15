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
    return RTC_date.second % 2;
}