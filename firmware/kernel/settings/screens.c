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

char Screen_getKeyUp() {
    return Keyboard_keyUp();
}

char Screen_getKeyDown() {
    return Keyboard_keyDown();
}

char Screen_getKeyEntre() {
    return Keyboard_keyEnter();
}

char Screen_getKeyEsc() {
    return Keyboard_keyEsc();
}

char Screen_getScrollStop() {
    return UPP_scrollHasNext();
}

void Screen_windowLoadHead(const char *title) {
    Std_printf("%r%w%#%s %d\r\n%w", &Font_alfanum_6, &Font_alfanum_8, '_', title, Util_memGetSizeAloc() , &Font_alfanum_8);
}

void Screen_listSelectOutPrint(Screen_listItem *item) {
    Std_printf("%m%#%s%m", item->isSelect, &Font_alfanum_8, ' ', item->description, 0);
    if (UPP_getCursorX() != 0) {
        Std_printf("\r\n");
    }
}
