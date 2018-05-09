/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   screenMain.h
 * Author: RNR
 *
 * Created on 9 de Maio de 2018, 11:00
 */

#include "settings.h"
char BA, BB, BC, BD;

char Screen_getKeyUp() {
    return BC;
}

char Screen_getKeyDown() {
    return BD;
}

char Screen_getKeyEntre() {
    return BA;
}

char Screen_getKeyEsc() {
    return BB;
}

char Screen_getScrollStop() {
    return UPP_scrollHasNext();
}

void Screen_windowLoadHead(char *title) {
    Std_printf("%r%w%#%s\r\n%w", &UPP_FontAlfanum_6, &UPP_FontAlfanum_8, '_', title, &UPP_FontAlfanum_8);
}

void Screen_listSelectOutPrint(Screen_listItem *item) {
    Std_printf("%m%#%s%m\r\n", item->isSelect, &UPP_FontAlfanum_8, ' ', item->description, 0);
}
