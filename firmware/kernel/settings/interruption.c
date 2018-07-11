/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "settings.h"

void Int_timerMS() {
    static unsigned char tmpAntAcc = 0;
    if (tmpAntAcc > TMS_ACC) {
        RTC_secondIncr();
    }
    tmpAntAcc = TMS_ACC;
}

void Int_buttonUp(void) {

}

void Int_buttonDown(void) {

}