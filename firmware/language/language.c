/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "language.h"

char *Lang_load(char **end) {
    char *str = (char *) RCW(end);
    char *strPush = Util_memPush(20);
    char *rstr = strPush;
    char data;
    char index = 0;

    do {
        data = RCB(str++);
        *(rstr++) = data;
        index++;
    } while (data);

    Util_memTop(strPush);
    Util_memPush(index);

    return strPush;
}
