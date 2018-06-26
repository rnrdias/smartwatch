/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "screens.h"

typedef struct {
    
}Sc_stopwatchParam;

void Sc_stopwatchStart(Screen_windowLoad *this) {
    this->windows->title = (char*) RVCW(&lang->stopwatch);
}

void Sc_stopwatchLoop(Screen_windowLoad *this) {
    Std_printf("%w%2d:%1d%w\n%1d\r", &Font_numeric_16, 0, 0, &Font_alfanum_8, 0);
    Std_printf("178:33:45\r\n");
    Std_printf("212:15:17\r\n");
    Std_printf("318:46:05\r\n");
    if (Keyboard_keyEsc()) {
        Screen_windowClose();
    }
}

void Sc_stopwatchEnd(Screen_windowLoad *this) {
    //Util_memTop(this->title);
}
Screen_window Sc_stopwatch = {0, Sc_stopwatchLoop, Sc_stopwatchStart, Sc_stopwatchEnd, 0, 0};